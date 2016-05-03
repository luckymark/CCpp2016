cmake_minimum_required(VERSION 3.5)
project(p11_linkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        linked_list.c linked_list.h main.cpp )

add_executable(p11_linkedList ${SOURCE_FILES})