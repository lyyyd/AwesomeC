cmake_minimum_required(VERSION 3.10)
project(StatementsLib)

add_definitions(-DSTATEMENTSLIB_EXPORTS)
add_library(StatementsLib SHARED statementsLib.c)
target_include_directories(StatementsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})