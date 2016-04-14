cmake_minimum_required(VERSION 3.5)
project(p10_pushBoxes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp)

add_executable(p10_pushBoxes ${SOURCE_FILES})