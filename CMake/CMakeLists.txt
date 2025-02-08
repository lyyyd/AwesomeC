cmake_minimum_required(VERSION 3.10)
project(CMake)

# 设置 C 语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加子目录
add_subdirectory(lib/staticLibrary)
add_subdirectory(lib/dynamicLibrary)

# 添加可执行文件
add_executable(CMake src/main.c)

# 链接静态库和动态库
target_link_libraries(CMake PRIVATE StaticLibrary DynamicLibrary) 

# 包含静态库和动态库的头文件目录
target_include_directories(CMake PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib/staticLibrary
    ${CMAKE_SOURCE_DIR}/lib/dynamicLibrary
)

# 复制动态库到可执行文件目录
add_custom_command(TARGET CMake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:DynamicLibrary>
        $<TARGET_FILE_DIR:CMake>
)