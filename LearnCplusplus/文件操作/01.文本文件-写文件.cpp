#include <fstream>
#include <iostream>

using namespace std;
//文本文件 写文件
void test01() {
    //创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("test.txt", ios::out);
    //写内容
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

int main() {
    test01();
    return 0;
}