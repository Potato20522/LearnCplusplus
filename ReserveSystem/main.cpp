#include <iostream>
#include "login/loginIn.h"
#include "menu/Menu.cpp"

using namespace std;

int main() {
    int select = 0;//用于接收用户的选择
    while (true) {
        mainMenu();
        cin >> select;//接收用户选择
        switch (select) {
            case 1://学生身份
                loginIn(STUDENT_FILE, 1);
                break;
            case 2: //老师身份
                loginIn(TEACHER_FILE, 2);
                break;
            case 3://管理员身份
                loginIn(ADMIN_FILE, 3);
                break;
            case 0://推出系统
                cout << "欢迎下次使用" << endl;
                system("read");
                return 0;
            default:
                cout << "输入有误,请重新选择!" << endl;
                system("read");
                system("clear");
                break;
        }
    }
}

