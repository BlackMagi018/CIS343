cmake_minimum_required(VERSION 3.8)
project(InConcert)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp concert.cpp concert.h)
add_executable(InConcert ${SOURCE_FILES})