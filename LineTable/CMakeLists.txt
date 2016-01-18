cmake_minimum_required(VERSION 3.3)
project(LineTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c main.c)
add_executable(LineTable ${SOURCE_FILES})