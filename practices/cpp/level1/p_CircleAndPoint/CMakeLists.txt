cmake_minimum_required(VERSION 3.4)
project(p_CircleAndPoint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        shape.cpp
        shape.h
    README.md)

add_executable(p_CircleAndPoint ${SOURCE_FILES})