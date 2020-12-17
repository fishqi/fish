#ifndef CONFIG_H_
#define CONFIG_H_

#include <map>
#include <set>
#include <string>
#include <vector>

class Config
{
public:
        bool LoadConfigFile(const std::string& filePath);


        const int GetThreadPoolNum();
        const std::string GetLogPath();
public:
        static Config* GetInstance();
private:
        Config();
        ~Config();
        const std::string FindMapValue(const std::string key);
private:
        std::map<std::string, std::string>      m_key_value;
};
#endif
