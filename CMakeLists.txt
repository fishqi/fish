set(PROJECT_SRC_ROOT ${CMAKE_CURRENT_LIST_DIR}/)

include_directories(${PROJECT_SRC_ROOT}/include)

aux_source_directory(${PROJECT_SRC_ROOT}/src SRC_FILES)

add_executable(main ${SRC_FILES})

target_link_libraries(main -g -lpthread)
