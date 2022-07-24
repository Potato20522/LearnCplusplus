cmake_minimum_required(VERSION 3.20)
project(windows-api)
set(CMAKE_CXX_STANDARD 20)
# C的解决乱码办法
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
# C++ 的解决乱码办法
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

# https://zhuanlan.zhihu.com/p/424234116
# 添加编译器参数，缩小可执行文件大小(该方法是利用 GCC 中的 "-s" 选项来去除可执行程序的符号表和重定位信息。)
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")

#为什么使用Clion，而不是VS2019
#因为会有多个main函数，使用Clion就比较方便，仅此而已

add_executable(SayHi SayHi.c)
add_executable(wchar_t wchar_t.c)
add_executable(HelloWorld HelloWorld.c)
add_executable(A_and_W A_and_W.c)
add_executable(DemoB ReadFile.c)
add_executable(file_attr file_attr.c)
add_executable(SystemDirectory SystemDirectory.c)
add_executable(create_windows create_windows.c)
add_executable(create_windows2 create_windows2.c)
add_executable(service_demo service_demo.c)
add_executable(service_and_install_demo service_and_install_demo.c)