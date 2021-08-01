#include <iostream>
#include <string>

using namespace std;

//1.查找
void test01() {
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "pos = " << pos << endl;
    }
    //rfind从右往左查找，find从左往右查找
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}
//2.替换
void test02() {
    string str1 = "abcdefgde";
    //从1号位置起，3个字符替换为"1111"
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}

int main() {
    test01();
    test02();
    return 0;
}