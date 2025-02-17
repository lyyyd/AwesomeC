cmake_minimum_required(VERSION 3.10)
project(DynamicLibrary)

add_definitions(-DDYNAMICLIBRARY_EXPORTS)
add_library(DynamicLibrary SHARED dynamicLibrary.c)
target_include_directories(DynamicLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})