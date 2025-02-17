cmake_minimum_required(VERSION 3.10)
project(CTypeLib)

add_definitions(-DCTYPELIB_EXPORTS)
add_library(CTypeLib SHARED cTypeLib.c)
target_include_directories(CTypeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})