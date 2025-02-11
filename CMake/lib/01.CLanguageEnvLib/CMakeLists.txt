cmake_minimum_required(VERSION 3.10)
project(CLanguageEnvLib)

add_definitions(-DCLANGUAGEENVLIB_EXPORTS)
add_library(CLanguageEnvLib SHARED cLanguageEnvLib.c)
target_include_directories(CLanguageEnvLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})