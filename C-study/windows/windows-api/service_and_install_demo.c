
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
#include <string.h>

#define SLEEP_TIME 5000
#define FILE_PATH "D:\\log.txt"
//#define SERVICE_NAME "demo"

//服务主函数
void WINAPI ServiceMain(int argc, char** argv);

//服务控制函数，可以进行启动、停止、暂停、恢复操作
void WINAPI ServiceCtrlHandler(DWORD Opcode);

//安装服务
BOOL InstallCmdService();

//删除服务
void DelService();

//日志
int WriteToLog(char* str);
//服务是否在运行
BOOL bRunning = TRUE;
//服务状态
SERVICE_STATUS m_ServiceStatus;
//服务状态句柄
SERVICE_STATUS_HANDLE m_ServiceStatusHandle;
char *SERVICE_NAME = "demo";

/**
 *
 * @param argc 参数的个数，
 * @param argv argv[0] 为自身运行路径和程序名,argv[1]指向第一个参数、argv[2]指向第二个参数......
 * @return
 */
int main(int argc, char* argv[]) {
    //因为argv[0] 为自身运行路径和程序名，所以个数为2时才说明用户有输入参数了
    printf("%s\n",argv[0]);
    if (argc == 2) {
        //不区分大小写进行比较
        if (!_stricmp(argv[1], "-i")) {
            InstallCmdService();
        }
        else if (!_stricmp(argv[1], "-r")) {
            DelService();
        }
        return 0;
    }
    //服务分派表
    SERVICE_TABLE_ENTRY dispatchTable[2];
    //服务名称
    dispatchTable[0].lpServiceName = SERVICE_NAME;
    //服务的主函数，是个函数指针
    dispatchTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;
    //数组的第二项就要设为NULL，这个例子只有一个服务，如果要写2个服务，数组长度就是3，最后一项也是要设为NULL
    dispatchTable[1].lpServiceName = NULL;
    dispatchTable[1].lpServiceProc = NULL;

    //注册服务的主函数,传入服务分派表。就会使用服务分派表的服务主函数来创建新的线程
    StartServiceCtrlDispatcher(dispatchTable);
    return 0;
}

int WriteToLog(char* str) {
    FILE* pFile;
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

void WINAPI ServiceMain(int argc, char** argv) {
    MEMORYSTATUS memstatus;
    char str[100];
    SIZE_T availmb;//可用内存：MB
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
    m_ServiceStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);
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
        GlobalMemoryStatusEx((LPMEMORYSTATUSEX) &memstatus);
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

BOOL InstallCmdService() {
    //保存服务程序的路径
    char strDir[2048];
    //服务控制管理器的句柄,服务的句柄
    SC_HANDLE schSCManager, schService;
    //二进制文件路径名指针
    LPCTSTR lpszBinaryPathName;
    //获取当前的文件夹
    GetCurrentDirectory(1024, strDir);
    printf("%s\n", strDir);
    lpszBinaryPathName = strDir;
    //获取当前的文件名,也就是服务程序
    GetModuleFileName(NULL, strDir, sizeof(strDir));
    printf("%s\n", strDir);
    //打开服务控制管理器句柄
    schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (schSCManager == NULL) {
        printf("Open scmanager failed,maybe you do not have the privilage to do this\n");
        return FALSE;
    }
    //创建服务，得到服务的句柄
    schService = CreateService(
            schSCManager,//服务控制管理器句柄
            SERVICE_NAME,//服务名称
            "demo demo...",//显示名称
            SERVICE_ALL_ACCESS,//访问权限：所有
            SERVICE_WIN32_OWN_PROCESS, //WIN32类型的服务
            SERVICE_AUTO_START, //开机自启动
            SERVICE_ERROR_NORMAL,//错误处理：采用通常的方法进行处理，也就是忽略处理
            lpszBinaryPathName,
            NULL,//不属于任何用户组
            NULL,//使用已存在的标签
            NULL,//独立的服务
            NULL,//本地系统账号
            NULL);//密码为空
    if (schService == NULL) {//创建服务失败
        printf("failed,because we invoke CreateService failed\n");
        return FALSE;
    }
    //如果创建服务成功，则需要把创建的服务句柄关掉.
    printf("CreateService success\n");
    CloseServiceHandle(schSCManager);
    CloseServiceHandle(schService);
    return TRUE;
}

void DelService() {
    //char name[100] = SERVICE_NAME;
    SC_HANDLE scm;//服务控制管理器
    SC_HANDLE service;//服务句柄
    SERVICE_STATUS status;//服务状态
    BOOL isSuccess;
    //打开服务控制管理器
    if ((scm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE)) == NULL) {
        printf("OpenSCManager Error");
        return;
    }
    //打开服务
    service = OpenService(scm, SERVICE_NAME, SERVICE_ALL_ACCESS | DELETE);
    if (!service) {
        printf("OpenService Error");
        return;
    }
    isSuccess = QueryServiceStatus(service, &status);
    if (!isSuccess) {
        printf("QueryServiceStatus Error");
    }
    //如果服务没有停止，就给它停下来
    if (status.dwCurrentState != SERVICE_STOPPED) {
        isSuccess = ControlService(service, SERVICE_CONTROL_STOP, &status);
        if (!isSuccess) {
            printf("Stop Service Error");
            return;
        }
    }
    isSuccess = DeleteService(service);
    if (!isSuccess) {
        printf("Delete Service Fail!");
    }
    else {
        printf("Delete Service Success!");
    }
    //关闭句柄
    CloseServiceHandle(service);
    CloseServiceHandle(scm);
}