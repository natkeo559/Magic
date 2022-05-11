cmake_minimum_required(VERSION 3.10)

project(Magic)

add_executable(3x3 3x3_intrin.cpp) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
