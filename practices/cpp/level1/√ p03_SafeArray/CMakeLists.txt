cmake_minimum_required(VERSION 3.4)
project(p03_SafeArray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        safearray.cpp
        safearray.h
        README.md)

add_executable(p03_SafeArray ${SOURCE_FILES})