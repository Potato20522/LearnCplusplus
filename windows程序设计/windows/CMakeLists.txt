cmake_minimum_required(VERSION 3.20)
project(windows C)

set(CMAKE_C_STANDARD 11)

add_executable(windows main.c SayHi.c)
