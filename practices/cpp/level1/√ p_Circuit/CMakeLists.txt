cmake_minimum_required(VERSION 3.4)
project(p_Circuit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Door.h
        Fan.h
        Button.h
        Button.cpp
        SwitchAble.h
    README.md)

add_executable(p_Circuit ${SOURCE_FILES})