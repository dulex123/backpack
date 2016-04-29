cmake_minimum_required(VERSION 3.5)
project(dynamic_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    largest-subsquare.cpp)

add_executable(dynamic_programming ${SOURCE_FILES})