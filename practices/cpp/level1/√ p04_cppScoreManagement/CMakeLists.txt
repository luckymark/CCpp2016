cmake_minimum_required(VERSION 3.4)
project(p04_cppScoreManagement)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Student.cpp
        Student.h
    README.md)

add_executable(p04_cppScoreManagement ${SOURCE_FILES})