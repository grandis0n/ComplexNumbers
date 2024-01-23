cmake_minimum_required(VERSION 3.23)
project(complex)

set(CMAKE_CXX_STANDARD 20)

add_executable(complex ComplexNum.cpp ComplexNum.hpp ComplexTest.cpp
        ComplexTest.cpp
        ComplexNum.hpp)
