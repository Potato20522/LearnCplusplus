# 概念理清

来源：https://zhuanlan.zhihu.com/p/111110992

最近，有没有被make、cmake、makefile... ... 这些东西绕晕了，看看下面的文章，也许就可以理解清楚了。

## gcc

它是GNU Compiler Collection（就是GNU编译器套件），也可以简单认为是**编译器**，它可以编译很多种编程语言（括C、C++、Objective-C、Fortran、Java等等）。

我们的程序**只有一个**源文件时，直接就可以用gcc命令编译它。

可是，如果我们的程序包含很**多个**源文件时，该咋整？用gcc命令逐个去编译时，就发现很容易混乱而且工作量大，所以出现了下面make工具。

## make

make工具可以看成是一个智能的**批处理**工具，它本身并没有编译和链接的功能，而是用类似于批处理的方式—通过调用**makefile文件**中用户指定的命令来进行编译和链接的。

### makefile

这个是啥东西？

简单的说就像一首歌的乐谱，make工具就像指挥家，指挥家根据乐谱指挥整个乐团怎么样演奏，make工具就根据makefile中的命令进行编译和链接的。makefile命令中就包含了调用gcc（也可以是别的编译器）去编译某个源文件的命令。

makefile在一些简单的工程完全可以人工拿下，但是当工程非常大的时候，手写makefile也是非常麻烦的，如果换了个平台makefile又要重新修改，这时候就出现了下面的Cmake这个工具。

## cmake

cmake就可以更加简单的生成makefile文件给上面那个make用。当然cmake还有其他更牛X功能，就是可以**跨平台**生成对应平台能用的makefile，我们就不用再自己去修改了。

可是cmake根据什么生成makefile呢？它又要根据一个叫CMakeLists.txt文件（学名：组态档）去生成makefile。

### CMakeList.txt

到最后CMakeLists.txt文件谁写啊？亲，是你自己手写的。

## nmake

nmake又是啥东西？

nmake是Microsoft Visual Studio中的附带命令，需要安装VS，实际上可以说相当于linux的make，明白了么？

## 小结

![img](img/CMake.assets/v2-497f031761c929e5c036138f938508c6_720w.jpg)

总结一下大体流程

1.用编辑器编写源代码，如.c文件。

2.用编译器编译代码生成目标文件，如.o。

3.用链接器连接目标代码生成可执行文件，如.exe。

但如果源文件太多，一个一个编译那得多麻烦啊？于是人们想到，为啥不设计一种类似批处理的程序，来批处理编译源文件呢？

于是就有了**make**工具，它是一个自动化编译工具，你可以使用一条命令实现完全编译。但是你需要编写一个规则文件，make依据它来批处理编译，这个文件就是**makefile**，所以编写makefile文件也是一个程序员所必备的技能。

对于一个大工程，编写makefile实在是件复杂的事，于是人们又想，为什么不设计一个工具，读入所有源文件之后，自动生成makefile呢，于是就出现了**cmake**工具，它能够输出各种各样的makefile或者project文件，从而帮助程序员减轻负担。但是随之而来也就是编写cmakelist文件，它是cmake所依据的规则。（cmake中有很多设置库的，此时还不是可执行文件，而make生成后才是二进制可执行文件。）

**所以在编程的世界里没有捷径可走，还是要脚踏实地的。**

# 现代CMake

课程：https://www.bilibili.com/video/BV16P4y1g7MH?

- 现代CMake指的是CMake 3.x
- 古代CMake指的是CMake 2.x
- 通过互联网和学校课程，许多人认识的Cmake都是古代 CMake。
- 现代 CMake和古代 CMake相比，使用更方便，功能更强大

```cmd
# 古代
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release  # 在build目录运行cmake<源码目录>生成Makefile
make -j4  # 执行本地的构建系统make真正开始构建（4进程并行）
make install #让本地的构建系统执行安装步骤
cd..  # 回到源码目录


# 现代
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 4
cmake --build build --target install
```

现代 Cmake提供了更方便的B和--build指令，不同平台，统一命令!

- cmake -B build  在源码目录用-B直接创建buid目录并生成 build/ Makefilec
- make --build build -j4  自动调用本地的构建系统在buld里构建，即: make -c build-j4
- sudo cmake --build build -- target install  调用本地的构建系统执行 install这个目标，即安装



cmake -B build  免去了先创建 build目录再切换进去再指定源码目录的麻烦。

cmake --build build  统一了不同平台( Linux上会调用make， Windows上调用 devenv.exe)

结论:从现在开始，如果在命令行操作 cmake，请使用更方便的-B和-bυuild命令。



## Cmake项目的构建

Cmake项目的构建分为两步:

第一步是 cmake -B build，称为**配置阶段**( configure)，这时只检测环境并生成构建规则，会在 build目录下生成本地构建系统能识别的项目文件( Makefile或是.sln)

第二步是 cmake --build build，称为**构建阶段**( build)，这时才实际调用编译器来编译代码。

## -D选项 配置变量 缓存变量

-D选项:指定配置变量(又称缓存变量)

在**配置阶段**可以通过 -DXXX 设置缓存变量。

第二次配置时，之前的-DXXX添加仍然会被保留。

**cmake -B build -DCMAKE_INSTALL_PREFIX=**/opt/openvdb-8.0
设置安装路径为/opt/openvdb80(会安装到/opt/openvdb-80/ib/ /ibopenvdb.so)

**cmake -B build -DCMAKE_BUILD_TYPE=Release**
设置构建模式为发布模式(开启全部优化)

cmake -B build  ←第二次配置时没有-D参数，但是之前的-D设置的变量都会被保留(此时缓存里仍有你之前定义的 CMAKE_BUILD_TYPE和 CMAKE_INSTALL_PREFIX)

### -G选项 指定要用的生成器

众所周知， CMake是一个**跨平台的构建系统**，可以从 CMakeLists.txt生成不同类型的构建系统(比如 Linux的make， Windows的 MSBuild)，从而让构建规则可以只写一份，跨平台使用。

过去的软件(例如TBB)要跨平台，只好 Makefile的构建规则写一份， MSBuild也写一份。现在只需要写一次 CMakeLists.txt，他会视不同的操作系统，生成不同构建系统的规则文件。

那个**和操作系统绑定的构建系统**(make、 MSBuild)称为**本地构建系统**( native buildsystem)。

**负责从 CMakeLists.txt 生成本地构建系统构建规则文件的，称为生成器( generator)。**



- Linux系统上的 CMake默认用是 Unix Makefiles生成器;

- Windows系统默认是suaStudio2019生成器; 
- Macos系统默认是code生成器。

可以用-G参数改用别的生成器,例如 cmake- Ninja会生成 Ninja这个构建系统的构建规则。Ninja是一个高性能,跨平台的构建系统, Linux、 Windows、 Macos上都可以用。

Ninja可以从包管理器里安装，没有包管理器的 Windows可以用 Python的包管理器安装pip install ninja

(有趣的事实: CMake也可以通过 pip install cmake安装)

事实上, MSBuild是单核心的构建系统, Makefile虽然多核心但因历史兼容原因效率一般。**而Ninja则是专为性能优化的构建系统,他和 Cmake结合都是行业标准了。**

```cmd
cmake -GNinja -B build
```



![image-20220321214505421](img/CMake.assets/image-20220321214505421.png)



# 第一个CMake工程

## 先来一个源文件

main.cpp

```c++
#include <cstdio>
int mian() {
    printf("hello world!\n");
    return 0;
}
```

CMakeLists.txt

```cmake
add_executable(main main.cpp)
```

或者这样写：

```cmake
add_executable(main)
target_sources(main PUBLIC main.cpp)
```

## 如果有多个源文件呢

main.cpp

```c++
#include <cstdio>
#include "other.h"
int mian() {
    printf("hello world!\n");
	say_hello();
    return 0;
}
```

other.h

```h
#pragma once

void say_hello();
```

other.cpp

```c++
#include "other.h"
#include <cstdio>

void say_hello() {
    printf("Hello from other.cpp!\n");
}
```

CMakeLists.txt

```cmake
add_executable(main)
target_sources(main PUBLIC main.cpp other.cpp)
```

或者这样写：**使用变量来存储**

```cmake
add_executable(main)
set(sources main.cpp other.cpp)
target_sources(main PUBLIC ${sources})
```

格式：

```cmake
set(变量名 变量值1 变量值2...)
${sources} # 使用变量
```

建议把头文件也加上，这样在VS里可以出现在"Header Files" 一栏

```cmake
add_executable(main)
set(sources main.cpp other.cpp other.h)
target_sources(main PUBLIC ${sources})
```

## 使用file(GLOB ...) 自动查找文件

**使用GLOB自动查找当前目录下指定扩展名的文件，实现批量添加源文件**

```cmake
add_executable(main)
file(GLOB sources *.cpp *.h)
target_sources(main PUBLIC ${sources})
```

方便是方便，唯一的问题是当你写了一个新的cpp或h文件时，CMake可能不会被更新。
所以最好加上**CONFIGURE_DEPENDS**选项，当添加新文件时，自动更新变量。

```cmake
add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h)
target_sources(main PUBLIC ${sources})
```

当执行build时，它会检测有没有添加新的文件，检测到就重新刷新一遍。

## 如果源码放在子文件夹里怎么办

main.cpp

```c++
#include <cstdio>
#include "mylib/other.h"
int mian() {
    printf("hello world!\n");
	say_hello();
    return 0;
}
```

mylib目录下：

```
other.h
other.cpp
```

必须把路径名和后缀名的排列组合全部写出来吗？感觉好麻烦：

```cmake
add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h mylib/*.cpp mylib/*.h)
target_sources(main PUBLIC ${sources})
```

大可不必，用 aux_source_directory，自动搜集需要的文件名后缀

```cmake
add_executable(main)
#查找当前目录下的所有源文件将名称保存到 sources 变量
aux_source_directory(. sources)
aux_source_directory(mylib sources)
target_sources(main PUBLIC ${sources})
```

格式：

```cmake
aux_source_directory(< dir > < variable >)
```

## GLOB 换成 GLOB_RECURSE 

进一步：GLOB_RECURSE 了解以下，能自动包含所有**子文件夹**下的文件：

```cmake
add_executable(main
file(GLOB_RECURSE sources CONFIGURE_DEPENDS *.cpp .*h)
target_sources(main PUBLIC ${sources})
```

GLOB_RECURSE 的问题：会把build目录里生成的临时.cpp文件也加进来。CMake为了测试编译器，会生成一些临时的cpp文件，而临时的cpp文件里也有mian函数，就和我们写的main函数冲突了

![image-20220321222120761](img/CMake.assets/image-20220321222120761.png)

解决方案：要么把源码统一放到src目录下，要么要求使用者不要把buid放到和源码同一个目录里，我个人的建议是把源码放到src目录下。

# 项目配置变量

## 构建的类型

**CMAKE_BUILD_TYPE构建的类型，调试模式还是发布模式。**

CMAKE_BUILD_TYPE 是 CMake 中一个特殊的变量，用于控制构建类型，他的值可以是：

- **Debug调试模式**，完全不优化，生成调试信息，方便调试程序
- **Release发布模式**，优化程度最高，性能最佳，但是编译比 Debug慢
- **MinsizeRel最小体积发布**，生成的文件比 Release更小，不完全优化，减少二进制体积
- **RelwithDeblnfo带调试信息发布**，生成的文件比 Release更大，因为带有调试的符号信息

**默认情况下 CMAKE_BUILD_TYPE为空字符串，这时相当于 Debug。**

```cmake
cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
add_executable(main main.cpp)
```

## 各种构建类型在编译器选项上的区别

在 Release模式下，追求的是程序的最佳性能表现，在此情况下，编译器会对程序做最大的代码优化以达到最快运行速度。另一方面，由于代码优化后不与源代码一致，此模式下般会丢失大量的调试信息。

```
1.Debug:`-O0 -g`
2.Release:`-O3 -DNDEBUG`
3.MinSizeRel:`-Os -DNDEBUG`
4.RelWithDebInfo:`-O2 -g DNDEBUG`
```

此外，注意定义了 NDEBUG宏会使 assert被去除掉。

小技巧：设定一个变量的默认值

如何让 CMAKE_BUILD_TYPE在用户没有指定的时候为 Release,指定的时候保持用户指定的值不变呢。

也就是说 CMake默认情况下 CMAKE_BUILD_TYPE 是一个空字符串。因此这里通过if( NOT  CMAKE_BUILD_TYPE)判断是否为空，如果空则自动设为 Release模式。

大多数 CMakeLists.txt 的开头都会有这样三行，为的是让默认的构建类型为发布模式(高度优化)而不是默认的调试模式(不会优化)。
我们稍后会详细捋一遍类似于 CMAKE_BUILD_TYPE  这样的东西。绝大多数 CMakeLists.txt 开头都会有的部分，可以说是“标准模板”了。

```cmake
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
```

## project：初始化项目信息

project：初始化项目信息，并把当前 CMakeLists.txt 所在位置作为根目录。

这里初始化了一个名称为 hellocmake的项，为什么需要项目名?
对于MSVC，他会在build里生成 hellocmake.sln作为“IDE眼中的项目”。

```cmake
cmake_minimum_required(VERSION 3.15)
project(hellocmake)
message("PROJECT_NAME:${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR}")
add_executable(main main.cpp)
```

CMAKE_CURRENT_SOURCE_DIR 表示当前源码目录的位置，例如：~/hellocmake。

CMAKE_CURRENT_BINARY_DIR 表示当前输出目录的位置，例如：~/hellocmake/build。



**和子模块的关系: PROJECT_X_DIR和 CMAKE_CURRENT_X_DIR的区别**

PROJECT_SOURCE_DIR 表示**最近一次调用** project的 CMakeLists.txt所在的源码目录。

CMAKE_CURRENT_SOURCE_DIR 表示**当前**  CMakeLists.txt 所在的源码目录。

CMAKE_SOURCE_DIR 表示**最为外层**  CMakeLists.txt 的源码根目录。

利用 PROJECT_SOURCE_DIR 可以实现从子模块里直接获得项目最外层目录的路径。

**不建议用 CMAKE_SOURCE_DIR，那样会让你的项目无法被人作为子模块使用。**

![image-20220321225241892](img/CMake.assets/image-20220321225241892.png)



## 其他相关变量

PROJECT_SOURCE_DIR：**当前项目**源码路径(存放main.cp的地方)

PROJECT_ BINARY_DIR：**当前项目**输岀路径(存放main.exe的地方)

CMAKE_SOURCE_DIR：**根项目**源码路径(存放main.cpp的地方)

CMAKE_BINARY_DIR：**根项目**输出路径(存放main.exe的地方)

PROJECT_ISITOP_LEVEL: BOOL类型，表示当前项目是否是(最顶层的)根项目

PROJECT_NAME：当前项目名

CMAKE_PROJECT_NAME：根项目的项目名

详见：https://cmake.org/cmake/help/latest/command/project.html

## 子模块

子模块里也可以用 project命令，将当前目录作为一个独立的子项目这样一来 PROJECT_SOURCE_DIR就会是子模块的源码目录而不是外层了。

这时候 CMake会认为这个子模块是个独立的项目，会额外做一些初始化。

他的构建目录 PROJECT_BINARY_DIR也会变成 build/<源码相对路径>。这样在MSvC上也会看见 build/mylib/mylib. vcxproj的生成。

![image-20220321225220619](img/CMake.assets/image-20220321225220619.png)

## project的初始化：LANGUAGES字段

project(项目名 LANGUAGES使用的语言列表…) 指定了该项目使用了哪些编程语言。

目前支持的语言包括:

- C：C语言
- CXX：C++语言
- ASM：汇编语言
- Fortran：老年人的编程语言
- CUDA:英伟达的CUDA(3.8版本新增)
- OBJC：苹果的 Objective-C(3.16版本新增)
- OBJCXX:苹果的 Objective-C++(3.16版本新增)
- lSPC:一种因特尔的自动SIMD编程语言(3.18版本新增)

**如果不指定 LANGUAGES,默认为C和CXX**。

常见问题：LANGUAGES中没有启用C语言，但是却用到了C语言

```cmake
cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES CXX)
add_executable(main main.c)
```

main.c

```c
#include <stdio.h>

int main(void) {
  printf("Hello, world from C！\n");
  return 0;
}
```

![image-20220321225751815](img/CMake.assets/image-20220321225751815.png)

解决：改成project(项目名 LANGUAGES C CXX) 即可

```cmake
cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES C CXX)
add_executable(main main.c)
```

也可以先设置 LANGUAGES NONE,之后再调用 enable_ language(CXX)

这样可以把 enable_language放到if语句里，从而只有某些选项开启才启用某语言之类的。

```cmake
cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES NONE)
enable_language(CXX)
add_executable(main main.cp)
```



1