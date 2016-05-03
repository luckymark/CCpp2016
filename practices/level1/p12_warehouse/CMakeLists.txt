cmake_minimum_required(VERSION 3.5)
project(p12_warehouse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        cargo_helper.h
        cargo_list.cpp
        cargo_meta.cpp
        cargo_push.cpp
        cargo_system_def.h
        main.cpp)

add_executable(p12_warehouse ${SOURCE_FILES})