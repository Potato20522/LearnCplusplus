cmake_minimum_required(VERSION 3.20)
project(C_Advanced C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Advanced main.c)

add_executable(socketclient_test socketclient/socketclient_test.c socketclient/socketclient.c)
#file(GLOB socketclient CONFIGURE_DEPENDS *.c .*h)
#target_sources(socketclient_test PUBLIC ${socketclient})

add_executable(select_sort select_sort.c)
add_executable(essence_of_data_types essence_of_data_types.c)
add_executable(type_alias type_alias.c)
add_executable(essence_of_variable essence_of_variable.c)