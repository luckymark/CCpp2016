cmake_minimum_required(VERSION 3.4)
project(p05_allPrimes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    isPrime.cpp
    isPrime.h
    prime.c)

add_executable(p05_allPrimes ${SOURCE_FILES})