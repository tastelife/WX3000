#include "StdAfx.h"
#include "WXCommFun.h"
#include <windows.h>


//�쳣�׳���
CWXCommThrow::CWXCommThrow(): m_strMsg("") , m_nNo(0)
{
}
CWXCommThrow::CWXCommThrow(int nNo, std::string strMsg)
{
	this->SetMsg(strMsg);
	this->SetNo(nNo);
}
CWXCommThrow::CWXCommThrow(CWXCommThrow& comThrow)
{
	if(this==&comThrow)
	{
		return;
	}
	this->SetMsg(comThrow.GetMsg());
	this->SetNo(comThrow.GetNo());
}
CWXCommThrow::~CWXCommThrow()
{
}
//�����쳣�׳���
CWXCommAssertThrow::CWXCommAssertThrow(std::string fileAndLine)
{
	this->SetMsg(fileAndLine);
}
CWXCommAssertThrow::CWXCommAssertThrow(CWXCommAssertThrow& assertThrow)
{
	this->SetMsg(assertThrow.GetMsg());
	this->SetNo(assertThrow.GetNo());
}
CWXCommAssertThrow::~CWXCommAssertThrow()
{
}

//��������ת��
wchar_t* CWXConver::Char2WChar(const char* p)   
{   
    //���ȼ�����Ҫ�Ļ�������С   
    int chaCount =  MultiByteToWideChar(   
        CP_ACP,                 //ANSI code page    
        0,    
        p,                      //Դ�ַ���   
        -1,                     //�Զ��ж�Դ�ַ�������   
        NULL,                   //Ŀ���ַ��Ϊ��   
        0                       //Ŀ���ַ��������С   
        );   
  
    wchar_t* pw = new wchar_t[chaCount];   
       
    MultiByteToWideChar(   
        CP_ACP,                                         //ANSI code page    
        0,    
        p,                                              //Դ�ַ���   
        -1,                                             //�Զ��ж�Դ�ַ�������   
        pw,                                             //Ŀ���ַ   
        chaCount                                        //Ŀ���ַ��������С   
        );   
  
    return pw;   
  
}   
  
std::wstring CWXConver::s2ws(const std::string str)   
{   
    wchar_t* pw = CWXConver::Char2WChar(str.c_str());   
    std::wstring wstr(pw);   
    delete[] pw;   
    return wstr;   
}   
  
  
char* CWXConver::WChar2Char(const wchar_t* pw)   
{   
    int chaCount = WideCharToMultiByte(   
        CP_ACP,    
        0,    
        pw,    
        -1,    
        NULL,    
        0,    
        NULL,   
        NULL    
        );   
    char* p = new char[chaCount];   
    WideCharToMultiByte(   
        CP_ACP,    
        0,    
        pw,    
        -1,    
        p,    
        chaCount,    
        NULL,                       //�������޷�ת�����ַ�,ʹ��ϵͳĬ�ϵ��ַ�����   
        NULL                        //��֤�����ַ��Ƿ�ɹ�ת��,���������   
        );   
    return p;   
}   
  
  
std::string CWXConver::ws2s(const std::wstring& wstr)   
{   
    char* p = CWXConver::WChar2Char(wstr.c_str());   
    std::string str(p);   
    delete[] p;   
    return str;   
}  



CWXFun::CWXFun()
{
}
CWXFun::~CWXFun()
{
}


//�������з�ʽ��ȡ����MAC��ַ
BOOL GetMacByCmd(char *lpszMac);

////////////////////////////////////////////////////////////////////////////
// �������� GetMacByCmd(char *lpszMac)
// ������
//      ���룺 void
//      ����� lpszMac,���ص�MAC��ַ��
// ����ֵ��
//      TRUE:  ���MAC��ַ��
//      FALSE: ��ȡMAC��ַʧ�ܡ�
// ���̣�
//      1. ����һ�������ܵ���
//      2. ����һ��IPCONFIG �Ľ��̣���������ض��򵽹ܵ���
//      3. �ӹܵ���ȡ�����з��ص�������Ϣ���뻺����lpszBuffer��
//      4. �ӻ�����lpszBuffer�л�ó�ȡ��MAC����
//
//  ��ʾ�����Է�����ɴ˳�����IP��ַ��������Ϣ��
//        ���������Ŀ���ͨ���������ʽ�õ�����Ϣֻ��ı�strFetCmd ��
//        str4Search�����ݼ��ɡ�
///////////////////////////////////////////////////////////////////////////

int CWXFun::GetMacByCmd(std::string& strMac)
{
	
	char lpszMac[128];
	//��������������С
	const long MAX_COMMAND_SIZE = 10000;

	//��ȡMAC������
	char szFetCmd[] = "ipconfig /all";
	//����MAC��ַ��ǰ����Ϣ
	const std::string str4Search = "Physical Address. . . . . . . . . : ";
	//��ʼ������MAC��ַ������
	memset(lpszMac, 0x00, sizeof(lpszMac));
	BOOL bret; 

	SECURITY_ATTRIBUTES sa;
	HANDLE hReadPipe,hWritePipe;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//�����ܵ�
	bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
	if(!bret)
	{
		return -2;
	}

	//���������д�����Ϣ
	STARTUPINFO si;
	//���ؽ�����Ϣ
	PROCESS_INFORMATION pi;

	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = hWritePipe;
	si.hStdOutput = hWritePipe;
	si.wShowWindow = SW_HIDE; //���������д���
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	//������ȡ�����н���
	bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL,
		NULL, &si, &pi );

	char szBuffer[MAX_COMMAND_SIZE+1]; //�������������������
	std::string strBuffer;

	if (bret)
	{
		WaitForSingleObject (pi.hProcess, INFINITE);
		unsigned long count;

		memset(szBuffer, 0x00, sizeof(szBuffer));
		bret  =  ReadFile(hReadPipe,  szBuffer,  MAX_COMMAND_SIZE,  &count,  0);
		if(!bret)
		{
			//�ر����еľ��
			CloseHandle(hWritePipe);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			CloseHandle(hReadPipe);
			return -2;
		}
		else
		{
			strBuffer = szBuffer;
			long ipos;
			ipos = strBuffer.find(str4Search);

			//��ȡMAC��ַ��
			strBuffer = strBuffer.substr(ipos+str4Search.length());
			ipos = strBuffer.find("\n");
			strBuffer = strBuffer.substr(0, ipos);
		}

	}
	
	memset(szBuffer, 0x00, sizeof(szBuffer));
	strcpy_s(szBuffer, strBuffer.c_str());

	//ȥ���м�ġ�00-50-EB-0F-27-82���м��'-'�õ�0050EB0F2782
	int j = 0;
	for(int i=0; i<(int)strlen(szBuffer); i++)
	{
		if(szBuffer[i] != '-')
		{
			lpszMac[j] = szBuffer[i];
			j++;
		}
	}

	//�ر����еľ��
	CloseHandle(hWritePipe);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(hReadPipe);
	strMac = lpszMac;

	return 0;

}

int CWXFun::GetIPHostName(std::string& strIP, std::string& strHostName)
{   
	////////////////
	// ��ʼ�� Windows sockets API. Ҫ��汾Ϊ version 1.1
	//
	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	if (WSAStartup(wVersionRequested, &wsaData)) {
		return -1;
	}

	//////////////////
	// ���������.
	//
	char hostname[256];
	int res = gethostname(hostname, sizeof(hostname));
	if (res != 0) {
		return -1;
	}
	strHostName = hostname;
	////////////////
	// ������������ȡ������Ϣ. 
	//
	hostent* pHostent = gethostbyname(hostname);
	if (pHostent==NULL) {
		return -1;
	}
	//////////////////
	// �������ص�hostent��Ϣ.
	//
	hostent& he = *pHostent;
	sockaddr_in sa;
	strIP = "";
	for (int nAdapter=0; he.h_addr_list[nAdapter]; nAdapter++) {
		memcpy ( &sa.sin_addr.s_addr, he.h_addr_list[nAdapter],he.h_length);
		// ���������IP��ַ.
		strIP += inet_ntoa(sa.sin_addr); 
		strIP += "  "; // ��ʾ��ַ��
	}
	//////////////////
	// ��ֹ Windows sockets API
	//
	WSACleanup();

	return 0;
}


int CWXFun::GetIPMacHostName(std::string& strIP, std::string& strMac, std::string& strHostName)
{
	return GetIPHostName(strIP, strHostName) + GetMacByCmd(strMac);
}