# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(PointerLib)

# 添加预处理器定义，用于导出动态库符号
add_definitions(-DPOINTERLIB_EXPORTS)

# 定义源文件列表，包含原有的 pointerLib.c 和新增的 extend1.c extend2.c
set(SOURCE_FILES pointerLib.c extend1.c)

# 生成动态库，使用定义好的源文件列表
add_library(PointerLib SHARED ${SOURCE_FILES})

# 设置动态库的包含目录，让编译器能找到头文件
target_include_directories(PointerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})