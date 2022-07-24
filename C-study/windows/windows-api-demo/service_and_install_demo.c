
/**
 * ����󣬲�Ҫȥִ�У���Ϊ�Ƿ��������Ҫ����windows����װ
 * ��װ��������ƹ����������ȥִ��
 * ���룺gcc .\service_demo.c -o service -fno-exceptions -s
 * ��������sc create demo_service binpath=E:\Gitee\LearnCplusplus\C-study\windows\windows-api\service.exe
 * ��������sc start demo_service
 * ֹͣ����sc stop demo_service
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEEP_TIME 5000
#define FILE_PATH "D:\\log.txt"
//#define SERVICE_NAME "demo"

 //����������
void WINAPI ServiceMain(int argc, char** argv);

//������ƺ��������Խ���������ֹͣ����ͣ���ָ�����
void WINAPI ServiceCtrlHandler(DWORD Opcode);

//��װ����
BOOL InstallCmdService();

//ɾ������
void DelService();

//��־
int WriteToLog(char* str);
//�����Ƿ�������
BOOL bRunning = TRUE;
//����״̬
SERVICE_STATUS m_ServiceStatus;
//����״̬���
SERVICE_STATUS_HANDLE m_ServiceStatusHandle;
char *SERVICE_NAME = "demo";

/**
 *
 * @param argc �����ĸ�����
 * @param argv argv[0] Ϊ��������·���ͳ�����,argv[1]ָ���һ��������argv[2]ָ��ڶ�������......
 * @return
 */
int main(int argc, char* argv[]) {
    //��Ϊargv[0] Ϊ��������·���ͳ����������Ը���Ϊ2ʱ��˵���û������������
    printf("%s\n",argv[0]);
    if (argc == 2) {
        //�����ִ�Сд���бȽ�
        if (!_stricmp(argv[1], "-i")) {
            InstallCmdService();
        }
        else if (!_stricmp(argv[1], "-r")) {
            DelService();
        }
        return 0;
    }
    //������ɱ�
    SERVICE_TABLE_ENTRY dispatchTable[2];
    //��������
    dispatchTable[0].lpServiceName = SERVICE_NAME;
    //��������������Ǹ�����ָ��
    dispatchTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;
    //����ĵڶ����Ҫ��ΪNULL���������ֻ��һ���������Ҫд2���������鳤�Ⱦ���3�����һ��Ҳ��Ҫ��ΪNULL
    dispatchTable[1].lpServiceName = NULL;
    dispatchTable[1].lpServiceProc = NULL;

    //ע������������,���������ɱ��ͻ�ʹ�÷�����ɱ�ķ����������������µ��߳�
    StartServiceCtrlDispatcher(dispatchTable);
    return 0;
}

int WriteToLog(char* str) {
    FILE* pFile;
    //a+��ʾ׷�ӵķ�ʽ
    fopen_s(&pFile, FILE_PATH, "a+");
    if (pFile == NULL) {
        return -1;
    }
    //�ļ�д���ַ���
    fprintf_s(pFile, "%s\n", str);
    fclose(pFile);
    return 0;
}

void WINAPI ServiceMain(int argc, char** argv) {
    MEMORYSTATUSEX memstatus;
    char str[100];
    int availmb;//�����ڴ棺MB
    //�������ͣ�win32
    m_ServiceStatus.dwServiceType = SERVICE_WIN32;
    //����ǰ״̬pending�ڵȴ�����Ϊ���ڳ�ʼ��
    m_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    //����������յĿ��ƣ����Թػ�������ֹͣ(����д�˼���������� switch (Opcode)�е�case��Ҫд����)
    m_ServiceStatus.dwControlsAccepted = SERVICE_CONTROL_SHUTDOWN | SERVICE_CONTROL_STOP;
    //��Ϊ���ڷ���û�˳���������������ExitCode��Ϊ0
    m_ServiceStatus.dwWin32ExitCode = 0;
    m_ServiceStatus.dwServiceSpecificExitCode = 0;
    //����������������Ҳ�ò����������������ʱ��ܳ������糬��30�룬�����õ�������������
    m_ServiceStatus.dwCheckPoint = 0;
    m_ServiceStatus.dwWaitHint = 0;
    //ע�������ƺ���
    //����1�����ƺ�lpServiceName����һ�£�����2��������ƺ���
    m_ServiceStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);
    if (m_ServiceStatusHandle == 0) {//���ע��ʧ����
        //��д����־�����������Լ�ʵ����־
        WriteToLog("RegisterServiceCtrlHandler Failed");
        return;
    }
    //�ɹ�����Ϣд����־
    WriteToLog("RegisterServiceCtrlHandler Success");
    //��ʱ��Ϳ��԰ѷ����״̬��ΪRUNNING��
    m_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
    //��������״̬����������ƹ�������
    SetServiceStatus(m_ServiceStatusHandle, &m_ServiceStatus);
    bRunning = TRUE;

    memset(str, '\0', 100);//�����ʼ��������

    while (bRunning) {
        //���ʵ�ּ����ԵĿ����ڴ��С��д����־�� 
        //https://blog.csdn.net/fulminate/article/details/6804365
        GlobalMemoryStatusEx(&memstatus);
        availmb = (int)(memstatus.ullAvailPhys / 1024 / 1024);
        //llu �޷���long long ��ʽ��
        sprintf_s(str, 100, "available memory is %dMB", availmb);
        WriteToLog(str);
        //����Ҫ�����ô�죬��5����һ�ξ��У���λ����
        Sleep(SLEEP_TIME);
    }
    WriteToLog("Service Stopped");
}

void WINAPI ServiceCtrlHandler(DWORD Opcode) {
    switch (Opcode) {
    case SERVICE_CONTROL_STOP://����ֹͣ
        bRunning = FALSE;
        m_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
        break;
    case SERVICE_CONTROL_SHUTDOWN: //����Ҫ�ص���
        bRunning = FALSE;
        m_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
        break;
    default:
        break;
    }
    SetServiceStatus(m_ServiceStatusHandle, &m_ServiceStatus);
}

BOOL InstallCmdService() {
    //�����������·��
    char strDir[2048];
    //������ƹ������ľ��,����ľ��
    SC_HANDLE schSCManager, schService;
    //�������ļ�·����ָ��
    LPCTSTR lpszBinaryPathName;
    //��ȡ��ǰ���ļ���
    GetCurrentDirectory(1024, strDir);
    printf("%s\n", strDir);
    lpszBinaryPathName = strDir;
    //��ȡ��ǰ���ļ���,Ҳ���Ƿ������
    GetModuleFileName(NULL, strDir, sizeof(strDir));
    printf("%s\n", strDir);
    //�򿪷�����ƹ��������
    schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (schSCManager == NULL) {
        printf("Open scmanager failed,maybe you do not have the privilage to do this\n");
        return FALSE;
    }
    //�������񣬵õ�����ľ��
    schService = CreateService(
        schSCManager,//������ƹ��������
        SERVICE_NAME,//��������
        "demo demo...",//��ʾ����
        SERVICE_ALL_ACCESS,//����Ȩ�ޣ�����
        SERVICE_WIN32_OWN_PROCESS, //WIN32���͵ķ���
        SERVICE_AUTO_START, //����������
        SERVICE_ERROR_NORMAL,//����������ͨ���ķ������д���Ҳ���Ǻ��Դ���
        lpszBinaryPathName,
        NULL,//�������κ��û���
        NULL,//ʹ���Ѵ��ڵı�ǩ
        NULL,//�����ķ���
        NULL,//����ϵͳ�˺�
        NULL);//����Ϊ��
    if (schService == NULL) {//��������ʧ��
        printf("failed,because we invoke CreateService failed\n");
        return FALSE;
    }
    //�����������ɹ�������Ҫ�Ѵ����ķ������ص�.
    printf("CreateService success\n");
    CloseServiceHandle(schSCManager);
    CloseServiceHandle(schService);
    return TRUE;
}

void DelService() {
    //char name[100] = SERVICE_NAME;
    SC_HANDLE scm;//������ƹ�����
    SC_HANDLE service;//������
    SERVICE_STATUS status;//����״̬
    BOOL isSuccess;
    //�򿪷�����ƹ�����
    if ((scm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE)) == NULL) {
        printf("OpenSCManager Error");
        return;
    }
    //�򿪷���
    service = OpenService(scm, SERVICE_NAME, SERVICE_ALL_ACCESS | DELETE);
    if (!service) {
        printf("OpenService Error");
        return;
    }
    isSuccess = QueryServiceStatus(service, &status);
    if (!isSuccess) {
        printf("QueryServiceStatus Error");
    }
    //�������û��ֹͣ���͸���ͣ����
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
    //�رվ��
    CloseServiceHandle(service);
    CloseServiceHandle(scm);
}