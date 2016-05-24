cmake_minimum_required(VERSION 3.4)
project(p02_Stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Stack.cpp
    Stack.h)

add_executable(p02_Stack ${SOURCE_FILES})