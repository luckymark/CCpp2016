cmake_minimum_required(VERSION 3.4)
project(p_CircleAndPoint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Point.hpp
        Circle.h
        Circle.cpp
    README.md)

add_executable(p_CircleAndPoint ${SOURCE_FILES})