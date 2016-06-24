cmake_minimum_required(VERSION 3.4)
project(p_EmployeeAndSales)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    README.md)

add_executable(p_EmployeeAndSales ${SOURCE_FILES})