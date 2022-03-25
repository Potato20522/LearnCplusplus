cmake_minimum_required(VERSION 3.20)
project(C_Advanced C)

set(CMAKE_C_STANDARD 11)

# 遍历项目根目录下所有的 .c文件
file (GLOB_RECURSE  files ${PROJECT_SOURCE_DIR}/*.c)
foreach (file ${files})
    message(source\ is: ${file})
    #排除编译输出目录: cmake-build
    if (NOT ${file} MATCHES .*cmake-build.*)
        string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
        add_executable (${exe} ${file})
        message (\ \ \ \ --\ ${exe}.c\ will\ be\ compiled\ to\ ${exe}.exe)
    endif ()
endforeach ()
