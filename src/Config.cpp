#include "Config.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string.h>
Config::Config()
{
        LoadConfigFile("conf/config");
}

Config::~Config()
{}


//遍历整个map，然后找出里面的键值对
const std::string Config::FindMapValue(const std::string key)
{
        std::map<std::string, std::string>::iterator it = m_key_value.find(key);
        if (it == m_key_value.end()) return "";
        if (it->second.size() <= 0) return "";
        else return it->second.data();
}

const std::string Config::GetLogPath()
{
        return FindMapValue("log_path");
}

const int Config::GetThreadPoolNum()
{
				std::string str = FindMapValue("pool_num");
				return atoi(str.data());
}

bool Config::LoadConfigFile(const std::string& filePath)
{
        std::ifstream configFile;
        configFile.open(filePath.c_str());
        std::string str_line;
        if (configFile.is_open())
        {
                while (!configFile.eof())
                {
                        getline(configFile, str_line);
                        int i = 0;
                        while (i < str_line.size() && str_line[i] == ' ')
                        {
                                i++;
                        }
                        if (i >= str_line.size() || str_line[i] == '#') //过滤掉注释信息，即如果首个字符为#就过滤掉这一行
                        {
                                continue;
                        }
                        size_t pos = str_line.find('=');
                        std::string str_key = str_line.substr(i, pos - i);
                        std::string str_value = str_line.substr(pos + 1);
                        std::cout << "key is " << str_key << " and values is " << str_value << std::endl;
                        m_key_value.insert(std::pair<std::string, std::string>(str_key, str_value));
                }
        }
        else
        {
                return false;
        }
        return true;
}

Config* Config::GetInstance()
{
        static Config g_Instance;
        return &g_Instance;
}
