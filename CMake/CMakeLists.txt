cmake_minimum_required(VERSION 3.10)
project(CMake)

# 设置 C 语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加子目录
add_subdirectory(lib/staticLibrary)
add_subdirectory(lib/dynamicLibrary)
add_subdirectory(lib/01.CLanguageEnvLib)
add_subdirectory(lib/02.CTypeLib)
add_subdirectory(lib/03.StatementsLib)
add_subdirectory(lib/04.ArrLib)
add_subdirectory(lib/05.FunLib)
add_subdirectory(lib/06.PointerLib)
add_subdirectory(lib/07.MemoryLib)
add_subdirectory(lib/08.CompositeTypeLib)
add_subdirectory(lib/09.FileLib)

# 添加可执行文件
add_executable(CMake src/main.c)

# 链接静态库和动态库
target_link_libraries(CMake PRIVATE StaticLibrary DynamicLibrary CLanguageEnvLib CTypeLib StatementsLib ArrLib FunLib PointerLib MemoryLib CompositeTypeLib FileLib)

# 包含静态库和动态库的头文件目录
target_include_directories(CMake PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib/staticLibrary
    ${CMAKE_SOURCE_DIR}/lib/dynamicLibrary
    ${CMAKE_SOURCE_DIR}/lib/01.CLanguageEnvLib
    ${CMAKE_SOURCE_DIR}/lib/02.CTypeLib
    ${CMAKE_SOURCE_DIR}/lib/03.StatementsLib
    ${CMAKE_SOURCE_DIR}/lib/04.ArrLib
    ${CMAKE_SOURCE_DIR}/lib/05.FunLib
    ${CMAKE_SOURCE_DIR}/lib/06.PointerLib
    ${CMAKE_SOURCE_DIR}/lib/07.MemoryLib
    ${CMAKE_SOURCE_DIR}/lib/08.CompositeTypeLib
    ${CMAKE_SOURCE_DIR}/lib/09.FileLib
)

# 复制动态库到可执行文件目录
add_custom_command(TARGET CMake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:DynamicLibrary>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CLanguageEnvLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CTypeLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:StatementsLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:ArrLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:FunLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:PointerLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MemoryLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CompositeTypeLib>
        $<TARGET_FILE_DIR:CMake>
)
add_custom_command(TARGET CMake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:FileLib>
        $<TARGET_FILE_DIR:CMake>
)