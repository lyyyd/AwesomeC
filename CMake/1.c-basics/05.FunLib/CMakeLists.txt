cmake_minimum_required(VERSION 3.10)
project(FunLib)

add_definitions(-DFUNLIB_EXPORTS)
add_library(FunLib SHARED funLib.c)
target_include_directories(FunLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})