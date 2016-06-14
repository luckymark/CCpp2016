cmake_minimum_required(VERSION 3.4)
project(p05_Canvas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Circ.cpp
        Circ.h
        Rect.cpp
        Rect.h
    README.md)

add_executable(p05_Canvas ${SOURCE_FILES})