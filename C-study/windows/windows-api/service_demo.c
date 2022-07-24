/**
 * 编译后，不要去执行，因为是服务程序，需要进行windows服务安装
 * 安装到服务控制管理器里，才能去执行
 * 编译：gcc .\service_demo.c -o service -fno-exceptions -s
 * 创建服务：sc create demo_service binpath=E:\Gitee\LearnCplusplus\C-study\windows\windows-api\service.exe
 * 启动服务：sc start demo_service
 * 停止服务：sc stop demo_service
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define SLEEP_TIME 5000
#define FILE_PATH "D:\\log.txt"

//服务主函数
void WINAPI ServiceMain(int argc, char **argv);

//服务控制函数，可以进行启动、停止、暂停、恢复操作
void WINAPI ServiceCtrlHandler(DWORD Opcode);

//日志
int WriteToLog(char *str);
//服务是否在运行
BOOL bRunning = TRUE;
//服务状态
SERVICE_STATUS m_ServiceStatus;
//服务状态句柄
SERVICE_STATUS_HANDLE m_ServiceStatusHandle;

int main() {
    //服务分派表
    SERVICE_TABLE_ENTRY dispatchTable[2];
    //服务名称
    dispatchTable[0].lpServiceName = "demo";
    //服务的主函数，是个函数指针
    dispatchTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION) ServiceMain;
    //数组的第二项就要设为NULL，这个例子只有一个服务，如果要写2个服务，数组长度就是3，最后一项也是要设为NULL
    dispatchTable[1].lpServiceName = NULL;
    dispatchTable[1].lpServiceProc = NULL;

    //注册服务的主函数,传入服务分派表。就会使用服务分派表的服务主函数来创建新的线程
    StartServiceCtrlDispatcher(dispatchTable);

    return 0;
}

int WriteToLog(char *str) {
    FILE *pFile;
    //a+表示追加的方式
    fopen_s(&pFile, FILE_PATH, "a+");
    if (pFile == NULL) {
        return -1;
    }
    //文件写入字符串
    fprintf_s(pFile, "%s\n", str);
    fclose(pFile);
    return 0;
}

void WINAPI ServiceMain(int argc, char **argv) {
    MEMORYSTATUS memstatus;
    char str[100];
    int availmb;//可用内存：MB
    //服务类型：win32
    m_ServiceStatus.dwServiceType = SERVICE_WIN32;
    //服务当前状态pending在等待，因为还在初始化
    m_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    //服务允许接收的控制：电脑关机、服务停止(这里写了几个，下面的 switch (Opcode)中的case就要写几个)
    m_ServiceStatus.dwControlsAccepted = SERVICE_CONTROL_SHUTDOWN | SERVICE_CONTROL_STOP;
    //因为现在服务还没退出，所以下面两个ExitCode设为0
    m_ServiceStatus.dwWin32ExitCode = 0;
    m_ServiceStatus.dwServiceSpecificExitCode = 0;
    //下面两个参数现在也用不到，如果服务启动时间很长，比如超过30秒，就能用到下面两个参数
    m_ServiceStatus.dwCheckPoint = 0;
    m_ServiceStatus.dwWaitHint = 0;
    //注册服务控制函数
    //参数1：名称和lpServiceName保存一致，参数2：服务控制函数
    m_ServiceStatusHandle = RegisterServiceCtrlHandler("demo", ServiceCtrlHandler);
    if (m_ServiceStatusHandle == 0) {//如果注册失败了
        //就写入日志，这里我们自己实现日志
        WriteToLog("RegisterServiceCtrlHandler Failed");
        return;
    }
    //成功的信息写入日志
    WriteToLog("RegisterServiceCtrlHandler Success");
    //这时候就可以把服务的状态改为RUNNING了
    m_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
    //报告服务的状态（给服务控制管理器）
    SetServiceStatus(m_ServiceStatusHandle, &m_ServiceStatus);
    bRunning = TRUE;

    memset(str, '\0', 100);//数组初始化：清零

    while (bRunning) {
        //这里，实现检查电脑的可以内存大小，写到日志里
        GlobalMemoryStatus(&memstatus);
        availmb = memstatus.dwAvailPhys / 1024 / 1024;
        sprintf_s(str, 100, "available memory is %dMB", availmb);
        WriteToLog(str);
        //不需要检查这么快，等5秒检查一次就行，单位毫秒
        Sleep(SLEEP_TIME);
    }
    WriteToLog("Service Stopped");
}

void WINAPI ServiceCtrlHandler(DWORD Opcode) {
    switch (Opcode) {
        case SERVICE_CONTROL_STOP://服务停止
            bRunning = FALSE;
            m_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
            break;
        case SERVICE_CONTROL_SHUTDOWN: //电脑要关掉了
            bRunning = FALSE;
            m_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
            break;
        default:
            break;
    }
    SetServiceStatus(m_ServiceStatusHandle, &m_ServiceStatus);
}

