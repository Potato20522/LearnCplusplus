/**
 * 类模板分文件编写， "Person.h",编译出错
 * 因为类模板中的成员函数在调用阶段产生
 * 第一种解决方式，直接包含源文件 "Person.hpp"
 * 第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp为文件,包含 "Person.hpp"
 */
#include <iostream>
#include "Person.hpp"

using namespace std;

void test01() {
    Person<string, int> p("Jerry", 18);
    p.showPerson();
}

int main() {
    test01();
    return 0;
}