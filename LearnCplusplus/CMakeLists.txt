# CMakeList.txt: LearnCplusplus 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("LearnCplusplus")

# 将源代码添加到此项目的可执行文件。
# add_executable (point "指针/指针的定义和使用.cpp")
# add_executable (point2 "指针/指针所占空间.cpp")
# add_executable (point3 "指针/空指针和野指针.cpp")
# add_executable (point4 "指针/const修饰指针.cpp")
# add_executable (point5 "指针/利用指针访问数组中元素.cpp")
# add_executable (point6 "指针/值传递和地址传递.cpp")
# add_executable (point7 "指针/案例-冒泡排序.cpp")
# 
# add_executable (struct "结构体/定义和使用.cpp")
# add_executable (struct2 "结构体/结构体数组.cpp")
# add_executable (struct3 "结构体/结构体指针.cpp")
# add_executable (struct4 "结构体/结构体嵌套结构体.cpp")
# add_executable (struct5 "结构体/结构体做函数参数.cpp")
# add_executable (struct6 "结构体/结构体中 const使用场景.cpp")
# 
# add_executable (ram "内存四区/01.全局区.cpp")
# add_executable (ram2 "内存四区/02.栈区.cpp")
# add_executable (ram3 "内存四区/03.堆区.cpp")
# add_executable (ram4 "内存四区/04.new的使用.cpp")
# 
# add_executable (ref "引用/01.引用的基本语法.cpp")
# add_executable (ref2 "引用/02.引用的注意事项.cpp")
# add_executable (ref3 "引用/03.引用做函数参数.cpp")
# add_executable (ref4 "引用/04.引用做函数返回值.cpp")
# add_executable (ref5 "引用/05.常量引用.cpp")
# 
# add_executable (fun "函数提高/01.函数默认参数.cpp")
# add_executable (fun2 "函数提高/02.函数的占位参数.cpp")
# add_executable (fun3 "函数提高/03.函数的重载.cpp")
# 
# add_executable (fz "面向对象/1.封装/封装的意义.cpp")
# add_executable (fz2 "面向对象/1.封装/学生类.cpp")
# add_executable (fz3 "面向对象/1.封装/访问权限.cpp")
# add_executable (fz4 "面向对象/1.封装/struct和class区别.cpp")
# add_executable (fz5 "面向对象/1.封装/成员属性设置为私有.cpp")
# 
# add_executable (in "面向对象/2.对象的初始化和清理/01.构造函数和析构函数.cpp")
# add_executable (in2 "面向对象/2.对象的初始化和清理/02.构造函数的分类及调用.cpp")
# add_executable (in3 "面向对象/2.对象的初始化和清理/03.拷贝构造函数调用时机.cpp")
# add_executable (in4 "面向对象/2.对象的初始化和清理/04.构造函数调用规则.cpp")
# add_executable (in5 "面向对象/2.对象的初始化和清理/05.深拷贝与浅拷贝.cpp")
# add_executable (in6 "面向对象/2.对象的初始化和清理/06.初始化列表.cpp")
# add_executable (in7 "面向对象/2.对象的初始化和清理/07.类对象作为类成员.cpp")
# add_executable (in8 "面向对象/2.对象的初始化和清理/08.静态成员变量.cpp")
# add_executable (in9 "面向对象/2.对象的初始化和清理/09.静态成员函数.cpp")

# add_executable (this1 "面向对象/3.C++对象模型和this指针/01.成员变量和成员函数分开存储.cpp")
# add_executable (this2 "面向对象/3.C++对象模型和this指针/02.this指针.cpp")
# add_executable (this3 "面向对象/3.C++对象模型和this指针/03.空指针访问成员函数.cpp")
# add_executable (this4 "面向对象/3.C++对象模型和this指针/04.const修饰成员函数.cpp")
# 
# add_executable (fri "面向对象/4.友元/01.全局函数做友元.cpp")
# add_executable (fri2 "面向对象/4.友元/02.类做友元.cpp")
# add_executable (fri3 "面向对象/4.友元/03.成员函数做友元.cpp")

# add_executable (yun "面向对象/5.运算符重载/01.加号运算符重载.cpp")
# add_executable (yun2 "面向对象/5.运算符重载/02.左移运算符重载.cpp")
# add_executable (yun3 "面向对象/5.运算符重载/03.递增运算符重载.cpp")
# add_executable (yun4 "面向对象/5.运算符重载/04.赋值运算符重载.cpp")
# add_executable (yun5 "面向对象/5.运算符重载/05.关系运算符重载.cpp")
# add_executable (yun6 "面向对象/5.运算符重载/06.函数调用运算符重载.cpp")

# add_executable (ext1 "面向对象/6.继承/01.继承的基本语法.cpp")
# add_executable (ext3 "面向对象/6.继承/03.继承中的对象模型.cpp")
# add_executable (ext4 "面向对象/6.继承/04.继承中构造和析构顺序.cpp")
# add_executable (ext5 "面向对象/6.继承/05.继承同名成员处理方式.cpp")
# add_executable (ext6 "面向对象/6.继承/06.继承同名静态成员处理方式.cpp")
# add_executable (ext7 "面向对象/6.继承/07.多继承.cpp")
# add_executable (ext8 "面向对象/6.继承/08.菱形继承.cpp")

# add_executable (duo1 "面向对象/7.多态/01.多态的基本概念.cpp")
# add_executable (duo2 "面向对象/7.多态/02.多态案例一-计算器类.cpp")
# add_executable (duo3 "面向对象/7.多态/03.纯虚函数和抽象类.cpp")
# add_executable (duo4 "面向对象/7.多态/04.多态案例二-制作饮品.cpp")
# add_executable (duo5 "面向对象/7.多态/05.虚析构和纯虚析构.cpp")
# add_executable (duo6 "面向对象/7.多态/06.多态案例三-电脑组装")

# add_executable (fil1 "文件操作/01.文本文件-写文件.cpp")
# add_executable (fil2 "文件操作/02.文本文件-读文件.cpp")
# add_executable (fil3 "文件操作/03.二进制文件-写文件.cpp")
# add_executable (fil4 "文件操作/04.二进制文件-读文件.cpp")
#
# add_executable (mo1 "模板/01.函数模板语法.cpp")
# add_executable (mo2 "模板/02.函数模板注意事项.cpp")
# add_executable (mo3 "模板/03.函数模板案例-数组排序.cpp")
# add_executable (mo4 "模板/04.普通函数与函数模板的区别.cpp")
# add_executable (mo5 "模板/05.普通函数与函数模板的调用规则.cpp")
# add_executable (mo6 "模板/06.模板的局限性.cpp")
# add_executable (mo7 "模板/07.类模板语法.cpp")
# add_executable (mo8 "模板/08.类模板与函数模板区别.cpp")
# add_executable (mo9 "模板/09.类模板中成员函数创建时机.cpp")
# add_executable (mo10 "模板/10.类模板对象做函数参数.cpp")
# add_executable (mo11 "模板/11.类模板与继承.cpp")
# add_executable (mo12 "模板/12.类模板成员函数类外实现.cpp")
# add_executable (mo13 "模板/13.类模板分文件编写.cpp" 模板/Person.hpp)
# add_executable (mo14 "模板/14.类模板与友元.cpp")
# add_executable (mo15 "模板/15.类模板案例—数组类封装.cpp" 模板/MyArray.hpp)

add_executable (vector1 "stl/container/vector/01.vector容器存放内置数据类型.cpp")
add_executable (vector2 "stl/container/vector/02.vector存放自定义数据类型.cpp")
add_executable (vector3 "stl/container/vector/03.vector容器嵌套容器.cpp")

add_executable (string1 "stl/container/string/01.string构造函数.cpp")
add_executable (string2 "stl/container/string/02.string赋值操作.cpp")
add_executable (string3 "stl/container/string/03.string字符串拼接.cpp")
add_executable (string4 "stl/container/string/04.string查找和替换.cpp")

# 遍历项目根目录及二级目录下所有的 .cpp 文件
#[[file (GLOB files *.cpp */*cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()]]


# TODO: 如有需要，请添加测试并安装目标。
