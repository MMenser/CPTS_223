cmake_minimum_required(VERSION 3.16)
project(MA4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -fopenmp")
set(CMAKE_BUILD_TYPE Debug)

add_executable(run main.cpp)