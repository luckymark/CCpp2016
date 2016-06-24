cmake_minimum_required(VERSION 3.4)
project(p_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
        Node.hpp
   )

add_executable(p_Tree ${SOURCE_FILES})