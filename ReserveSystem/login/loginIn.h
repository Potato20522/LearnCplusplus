#include "../identity/Identity.h"
#include "../identity/student/Student.h"
#include "../identity/teacher/Teacher.h"


#include <string>
//进入学生子菜单界面
void studentMenu(Identity*&student);

//进入教师子菜单界面
void teacherMenu(Identity*&teacher);

//进入管理员子菜单界面
void managerMenu(Identity*&manager);

//登录功能   参数1  操作文件名   参数2  操作身份类型
void loginIn(string fileName, int type);