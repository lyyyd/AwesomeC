cmake_minimum_required(VERSION 3.10)
project(FileLib)

add_definitions(-DFILELIB_EXPORTS)
add_library(FileLib SHARED fileLib.c)
target_include_directories(FileLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})