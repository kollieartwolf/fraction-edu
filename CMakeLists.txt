cmake_minimum_required(VERSION 3.5)

project(fraction LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fraction fraction.h fraction.cpp main.cpp)
