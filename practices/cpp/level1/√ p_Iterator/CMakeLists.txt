cmake_minimum_required(VERSION 3.4)
project(p_Iterator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Iterator.cpp
        Iterator.h
    README.md)

add_executable(p_Iterator ${SOURCE_FILES})