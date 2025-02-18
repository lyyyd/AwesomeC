cmake_minimum_required(VERSION 3.10)
project(CLanguageEnvLib)

# 添加可执行文件
#add_executable(3.1.advance-lib 01数据类型别名.c)

# 获取当前目录下所有的 .c 文件
#file(GLOB C_FILES *.c)
#
## 遍历每个 .c 文件
#foreach(C_FILE ${C_FILES})
#    # 获取文件名（不包含扩展名）
#    get_filename_component(EXECUTABLE_NAME ${C_FILE} NAME_WE)
#    # 创建可执行文件
#    add_executable(${EXECUTABLE_NAME} ${C_FILE})
#endforeach()