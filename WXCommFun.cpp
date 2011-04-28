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

int CWXFun::GetIPMacName(std::string& strIP, std::string& strMac, std::string& strHostName)
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
	printf("name=%s\naliases=%s\naddrtype=%d\nlength=%d\n",
		he.h_name, he.h_aliases, he.h_addrtype, he.h_length);

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