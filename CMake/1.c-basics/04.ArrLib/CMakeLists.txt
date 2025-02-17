cmake_minimum_required(VERSION 3.10)
project(ArrLib)

add_definitions(-DARRLIB_EXPORTS)
add_library(ArrLib SHARED arrLib.c)
target_include_directories(ArrLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})