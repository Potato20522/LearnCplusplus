cmake_minimum_required(VERSION 3.20)
project(C_Advanced C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Advanced main.c)

add_executable(socketclient_test socketclient/socketclient_test.c)