cmake_minimum_required(VERSION 3.10)
project(CMake)

# 设置 C 语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 11)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# 添加子目录
add_subdirectory(1.c-basics/staticLibrary)
add_subdirectory(1.c-basics/dynamicLibrary)
add_subdirectory(1.c-basics/01.CLanguageEnvLib)
add_subdirectory(1.c-basics/02.CTypeLib)
add_subdirectory(1.c-basics/03.StatementsLib)
add_subdirectory(1.c-basics/04.ArrLib)
add_subdirectory(1.c-basics/05.FunLib)
add_subdirectory(1.c-basics/06.PointerLib)
add_subdirectory(1.c-basics/07.MemoryLib)
add_subdirectory(1.c-basics/08.CompositeTypeLib)
add_subdirectory(1.c-basics/09.FileLib)
add_subdirectory(2.c-advance/1.1.typedef)
add_subdirectory(2.c-advance/1.2.void)
add_subdirectory(2.c-advance/1.3.sizeof)
add_subdirectory(2.c-advance/1.4.modify-variable)
add_subdirectory(2.c-advance/1.5.stack-area)
add_subdirectory(2.c-advance/1.6.heap-area)
add_subdirectory(2.c-advance/1.7.static-extern)
add_subdirectory(2.c-advance/1.8.const)
add_subdirectory(2.c-advance/2.1.macro-function)
add_subdirectory(2.c-advance/2.2.variable-transfer-analysis)
add_subdirectory(2.c-advance/2.3.growth-direction-of-the-stack)
add_subdirectory(2.c-advance/2.4.null-and-wild-pointers)
add_subdirectory(2.c-advance/2.5.step-length-of-pointer)
add_subdirectory(2.c-advance/2.6.indirect-assignment-of-a-pointer)
add_subdirectory(2.c-advance/2.7.pointers-do-the-input-and-output-properties-of-function-parameters)
add_subdirectory(2.c-advance/2.8.note-on-string-ointers)
add_subdirectory(2.c-advance/2.9.string-exercise)
add_subdirectory(2.c-advance/3.1.advance-lib)

# 添加可执行文件
add_executable(CMake src/main.c)

# 链接静态库和动态库
target_link_libraries(CMake PRIVATE StaticLibrary DynamicLibrary CLanguageEnvLib CTypeLib StatementsLib ArrLib FunLib PointerLib MemoryLib CompositeTypeLib FileLib)

# 包含静态库和动态库的头文件目录
target_include_directories(CMake PRIVATE 
    ${CMAKE_SOURCE_DIR}/1.c-basics/staticLibrary
    ${CMAKE_SOURCE_DIR}/1.c-basics/dynamicLibrary
    ${CMAKE_SOURCE_DIR}/1.c-basics/01.CLanguageEnvLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/02.CTypeLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/03.StatementsLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/04.ArrLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/05.FunLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/06.PointerLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/07.MemoryLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/08.CompositeTypeLib
    ${CMAKE_SOURCE_DIR}/1.c-basics/09.FileLib
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