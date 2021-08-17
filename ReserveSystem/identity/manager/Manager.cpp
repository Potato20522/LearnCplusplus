#include "Manager.h"
#include "../../menu/Menu.h"
//默认构造
Manager::Manager() {
}

//有参构造
Manager::Manager(string name, string pwd) {
    //初始化管理员信息
    this->name = name;
    this->pwd = pwd;

    //初始化容器 获取到所有文件中 学生、老师信息
    this->initVector();

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
    //cout << "机房的数量为：" << vCom.size() << endl;
}

//菜单界面
void Manager::operMenu() {
    teacherMenu(this->name);
}

//添加账号
void Manager::addPerson() {
    cout << "请输入添加账号类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName; //操作文件名
    string tip;  //提示id号
    string errorTip; //重复错误提示

    ofstream ofs;//文件操作对象

    int select = 0;
    cin >> select; //接受用户的选项

    if (select == 1) {
        //添加的是学生
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    } else {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";
    }

    //利用追加的方式 写文件
    ofs.open(fileName, ios::out | ios::app);

    int id; //学号 /职工号
    string name; //姓名
    string pwd; //密码

    cout << tip << endl;

    while (true) {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret) //有重复
        {
            cout << errorTip << endl;
        } else {
            break;
        }

    }


    cout << "请输入姓名： " << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("read");
    system("clear");

    ofs.close();

    //调用初始化容器接口，从新获取文件中的数据
    this->initVector();
}

void printStudent(Student &s) {
    cout << "学号： " << s.id << " 姓名： " << s.name << " 密码：" << s.pwd << endl;
}

void printTeacher(Teacher &s) {
    cout << "职工号： " << s.m_EmpId << " 姓名： " << s.name << " 密码：" << s.pwd << endl;
}

//查看账号
void Manager::showPerson() {
    cout << "请选择查看内容：" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0; //接受用户选择
    cin >> select;

    if (select == 1) {
        //查看学生
        cout << "所有学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        //查看老师
        cout << "所有老师信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }

    system("read");
    system("clear");
}

//查看机房信息
void Manager::showComputer() {
    cout << "机房信息如下：" << endl;

    for (auto & it : vCom) {
        cout << "机房编号： " << it.m_ComId << " 机房最大容量： " << it.m_MaxNum << endl;
    }
    system("read");
    system("clear");
}

//清空预约记录
void Manager::cleanFile() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    system("read");
    system("clear");
}


//初始化容器
void Manager::initVector() {
    //确保容器清空状态
    vStu.clear();
    vTea.clear();

    //读取信息   学生
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }

    Student s;
    while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd) {
        vStu.push_back(s);
    }

    //	cout << "当前学生数量为： " << vStu.size() << endl;
    ifs.close();

    //读取信息   老师
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.name && ifs >> t.pwd) {
        vTea.push_back(t);
    }

    //	cout << "当前老师数量为： " << vTea.size() << endl;
    ifs.close();
}

//检测重复 参数1 检测学号/职工号  参数2  检测类型
bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        //检测学生
        for (auto & it : vStu) {
            if (id == it.id) {
                return true;
            }
        }
    } else {
        //检测老师
        for (auto & it : vTea) {
            if (id == it.m_EmpId) {
                return true;
            }
        }
    }

    return false;
}