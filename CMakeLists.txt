cmake_minimum_required(VERSION 3.8)
project(InConcert)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # enable C++11 standard

set(SOURCE_FILES main.cpp concert.cpp concert.h)
add_executable(InConcert ${SOURCE_FILES})