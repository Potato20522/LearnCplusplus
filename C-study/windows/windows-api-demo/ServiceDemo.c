/**
 * ����󣬲�Ҫȥִ�У���Ϊ�Ƿ��������Ҫ����windows����װ
 * ��װ��������ƹ����������ȥִ��
 * ���룺gcc .\service_demo.c -o service -fno-exceptions -s
 * ��������sc create demo_service binpath=E:\Gitee\LearnCplusplus\C-study\windows\windows-api\service.exe
 * ��������sc start demo_service
 * ֹͣ����sc stop demo_service
 */
#pragma comment(linker,"/align:0x80")
#pragma optimize("data",on)
#pragma comment(linker,"/merge:.data=.text") 
#pragma comment(linker,"/merge:.rdata=.text")
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define SLEEP_TIME 5000
#define FILE_PATH "D:\\log.txt"

 //����������
void WINAPI ServiceMain(int argc, char** argv);

//������ƺ��������Խ���������ֹͣ����ͣ���ָ�����
void WINAPI ServiceCtrlHandler(DWORD Opcode);

//��־
int WriteToLog(char* str);
//�����Ƿ�������
BOOL bRunning = TRUE;
//����״̬
SERVICE_STATUS m_ServiceStatus;
//����״̬���
SERVICE_STATUS_HANDLE m_ServiceStatusHandle;

int main() {
    //������ɱ�
    SERVICE_TABLE_ENTRY dispatchTable[2];
    //��������
    dispatchTable[0].lpServiceName = "demo";
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
    MEMORYSTATUS memstatus;
    char str[100];
    SIZE_T availmb;//�����ڴ棺MB
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
    m_ServiceStatusHandle = RegisterServiceCtrlHandler("demo", ServiceCtrlHandler);
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
        GlobalMemoryStatus(&memstatus);
        availmb = memstatus.dwAvailPhys / 1024 / 1024;
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

