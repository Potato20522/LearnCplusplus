#pragma once

#include<iostream>
#include<vector>
#include <fstream>
#include "../Identity.h"
#include "../../order/computerRoom.h"
#include "../../file/globalFile.h"

using namespace std;

//学生类
class Student : public Identity {
public:
    //默认构造
    Student();

    //有参构造(学号、姓名、密码)
    Student(int id, string name, string pwd);

    //菜单界面
    void operMenu() override;

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder() const;

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int id;

    //机房容器
    vector<ComputerRoom> com;
};