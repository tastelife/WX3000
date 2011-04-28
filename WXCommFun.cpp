#include "StdAfx.h"
#include "WXCommFun.h"
#include <windows.h>


//异常抛出类
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
//断言异常抛出类
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

//常用类型转换
wchar_t* CWXConver::Char2WChar(const char* p)   
{   
    //首先计算需要的缓冲区大小   
    int chaCount =  MultiByteToWideChar(   
        CP_ACP,                 //ANSI code page    
        0,    
        p,                      //源字符串   
        -1,                     //自动判断源字符串长度   
        NULL,                   //目标地址设为空   
        0                       //目标地址缓冲区大小   
        );   
  
    wchar_t* pw = new wchar_t[chaCount];   
       
    MultiByteToWideChar(   
        CP_ACP,                                         //ANSI code page    
        0,    
        p,                                              //源字符串   
        -1,                                             //自动判断源字符串长度   
        pw,                                             //目标地址   
        chaCount                                        //目标地址缓冲区大小   
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
        NULL,                       //若出现无法转换的字符,使用系统默认的字符代替   
        NULL                        //验证所有字符是否成功转换,在这里忽略   
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
	// 初始化 Windows sockets API. 要求版本为 version 1.1
	//
	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	if (WSAStartup(wVersionRequested, &wsaData)) {
		return -1;
	}

	//////////////////
	// 获得主机名.
	//
	char hostname[256];
	int res = gethostname(hostname, sizeof(hostname));
	if (res != 0) {
		return -1;
	}
	strHostName = hostname;
	////////////////
	// 根据主机名获取主机信息. 
	//
	hostent* pHostent = gethostbyname(hostname);
	if (pHostent==NULL) {
		return -1;
	}
	//////////////////
	// 解析返回的hostent信息.
	//
	hostent& he = *pHostent;
	printf("name=%s\naliases=%s\naddrtype=%d\nlength=%d\n",
		he.h_name, he.h_aliases, he.h_addrtype, he.h_length);

	sockaddr_in sa;
	strIP = "";
	for (int nAdapter=0; he.h_addr_list[nAdapter]; nAdapter++) {
		memcpy ( &sa.sin_addr.s_addr, he.h_addr_list[nAdapter],he.h_length);
		// 输出机器的IP地址.
		strIP += inet_ntoa(sa.sin_addr); 
		strIP += "  "; // 显示地址串
	}
	//////////////////
	// 终止 Windows sockets API
	//
	WSACleanup();

	return 0;
}