cmake_minimum_required(VERSION 3.20)
project(C__11)

set(CMAKE_CXX_STANDARD 11)

add_executable(C__11 main.cpp string-original/string1.cpp)

add_executable(string1 string-original/string1.cpp)