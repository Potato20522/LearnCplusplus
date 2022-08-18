#pragma once

#include<iostream>
#include <string>
#include <vector>
#include "../Identity.h"
#include "../../order/OrderFile.h"

using namespace std;

class Teacher : public Identity {
public:

    //默认构造
    Teacher();

    //有参构造 (职工编号，姓名，密码)
    Teacher(int empId, string name, string pwd);

    //菜单界面
    void operMenu() override;

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    int m_EmpId; //教师编号

};