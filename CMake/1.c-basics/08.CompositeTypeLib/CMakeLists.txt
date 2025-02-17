cmake_minimum_required(VERSION 3.10)
project(CompositeTypeLib)

add_definitions(-DCOMPOSITETYPELIB_EXPORTS)
add_library(CompositeTypeLib SHARED compositeTypeLib.c)
target_include_directories(CompositeTypeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})