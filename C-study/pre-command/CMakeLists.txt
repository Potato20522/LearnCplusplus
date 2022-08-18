# 项目说明：用于学习C语言中常见的预处理命令
cmake_minimum_required(VERSION 3.22)
project(pre_command)

set(CMAKE_CXX_STANDARD 14)

add_executable(pre_command define.c)

add_executable(error error.c)
add_executable(warning warning.c)
add_executable(if if.c)