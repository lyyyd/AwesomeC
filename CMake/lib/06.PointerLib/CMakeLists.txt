cmake_minimum_required(VERSION 3.10)
project(PointerLib)

add_definitions(-DPOINTERLIB_EXPORTS)
add_library(PointerLib SHARED pointerLib.c)
target_include_directories(PointerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})