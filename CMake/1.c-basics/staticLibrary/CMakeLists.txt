cmake_minimum_required(VERSION 3.10)
project(StaticLibrary)

add_library(StaticLibrary STATIC staticLibrary.c)
target_include_directories(StaticLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})