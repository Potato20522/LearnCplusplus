cmake_minimum_required(VERSION 3.20)
project(ReserveSystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(ReserveSystem main.cpp identity/Identity.h identity/student/Student.h identity/student/Student.cpp identity/teacher/Teacher.cpp identity/teacher/Teacher.h identity/manager/Manager.cpp identity/manager/Manager.h file/globalFile.h login/loginIn.cpp order/computerRoom.h order/OrderFile.cpp order/OrderFile.h login/loginIn.h menu/Menu.h)
