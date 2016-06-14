cmake_minimum_required(VERSION 3.4)
project(p02_isPrime)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    isPrime.c)

add_executable(p02_isPrime ${SOURCE_FILES})