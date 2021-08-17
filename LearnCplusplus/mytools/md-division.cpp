#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int test01() {
    //读入文件
    ifstream ifs;
    ifs.open(R"(E:\C++\LearnCplusplus\LearnCplusplus\mytools\text.md)", ios::in);
    //创建正则表达式对象
    //匹配一级标题,开头最多允许三个空格,#+至少一个空格+至少一个的非空白字符
    std::regex first_title("^[ ]{0,3}#[ ]{1,}.+");
    std::regex second_title("^[ ]{0,3}##[ ]{1,}.+");//匹配二级标题
    std::regex code_block("^[ ]{0,3}```");//匹配代码块,开头最多允许三个空格
    std::regex code_four_space("^[ ]{4,}");//匹配代码块,开头四个或以上的空格
    std::regex code_tab("^\\t{1,}");//匹配代码块,开头至少一个tab
//    std::regex ordered_list("^[ ]{0,}\\d{1,}");//有序列表
//    std::regex unordered_list("");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return -1;
    }
    string buf;
    while (getline(ifs, buf)) {
        bool isFirstTitle = regex_match(buf, first_title);
        if (!isFirstTitle) {

        }
        cout << buf << endl;
    }
    ifs.close();

    return 0;
}

void createNewFile(string fileName, const string &content, string title) {
    fileName += title;
    ofstream ofs;
    ofs.open(fileName);
    title += "# ";
    ofs << title << endl;
    ofs << content << endl;
    ofs.close();
}

/**
 * 取出字符串首尾空格
 */
void trim(string &s) {
    if (s.empty()) {
        return;
    }
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
}

int main() {
    int result = test01();
    cout << result << endl;
    return 0;
}