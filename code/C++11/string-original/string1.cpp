#include<iostream>
#include<string>

using namespace std;

int main() {
    string str = R"(<html>
        <head>
        <title>
        海贼王
        </title>
        </head>
        <body>
        <p>
        我是要成为海贼王的男人!!!
        </p>
        </body>
    </html>)";
    cout << str << endl;
    string str1 = R"(D:\hello\world\test.text)";
    cout << str1 << endl;
    string str2 = R"luffy(D:\hello\world\test.text)luffy";
    cout << str2 << endl;
    return 0;
}