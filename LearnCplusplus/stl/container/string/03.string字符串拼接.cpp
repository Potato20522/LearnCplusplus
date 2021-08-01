#include <iostream>
#include <string>

using namespace std;

/*
 * string& operator+=(const char* str);            //重载+=操作符
 * string& operator+=(const char c);               //重载+=操作符
 * string& operator+=(const string& str);          //重载+=操作符
 * string& append(const char *s);                  //把字符串s连接到当前字符串结尾
 * string& append(const char *s, int n);           //把字符串s的前n个字符连接到当前字符串结尾
 * string& append(const string &s);                //同operator+=(const string& str)
 * string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
 */
void test01() {
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1=" << str1 << endl;

    str1+=':';
    cout << "str1=" << str1 << endl;

    string str2 = "LOL DNF";
    str1+=str2;
    cout << "str1=" << str1 << endl;

    string str3 = "I ";
    str3.append("love ");
    cout << "str3=" << str3 << endl;

    str3.append("game abcde", 4);
    cout << "str3=" << str3 << endl;

//    str3.append(str2);
//    str3.append(str2,0,3);
    str3.append(str2,4,3);//参数2:从哪个位置开始截取，参数3:截取字符个数
    cout << "str3=" << str3 << endl;

}

int main() {
    test01();
    return 0;
}