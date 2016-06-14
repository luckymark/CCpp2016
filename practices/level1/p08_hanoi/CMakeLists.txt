cmake_minimum_required(VERSION 3.4)
project(p08_hanoi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    hanoi.c)

add_executable(p08_hanoi ${SOURCE_FILES})