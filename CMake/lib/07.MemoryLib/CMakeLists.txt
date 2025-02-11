cmake_minimum_required(VERSION 3.10)
project(MemoryLib)

add_definitions(-DMEMORYLIB_EXPORTS)
add_library(MemoryLib SHARED memoryLib.c)
target_include_directories(MemoryLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})