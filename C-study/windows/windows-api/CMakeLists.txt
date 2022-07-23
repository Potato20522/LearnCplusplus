cmake_minimum_required(VERSION 3.20)
project(windows)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MFC_FLAG 2)
#add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
#add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_executable(SayHi SayHi.c)
set_target_properties(SayHi PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
#-D_AFXDLL :表示动态连接MFC
#-D_MBCS:多字节字符集

target_compile_definitions(SayHi PRIVATE
        -DWIN32
        -D_WINDOWS
        -D_UNICODE
        )
