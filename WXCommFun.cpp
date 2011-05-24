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


//用命令行方式获取网卡MAC地址
BOOL GetMacByCmd(char *lpszMac);

////////////////////////////////////////////////////////////////////////////
// 函数名： GetMacByCmd(char *lpszMac)
// 参数：
//      输入： void
//      输出： lpszMac,返回的MAC地址串
// 返回值：
//      TRUE:  获得MAC地址。
//      FALSE: 获取MAC地址失败。
// 过程：
//      1. 创建一个无名管道。
//      2. 创建一个IPCONFIG 的进程，并将输出重定向到管道。
//      3. 从管道获取命令行返回的所有信息放入缓冲区lpszBuffer。
//      4. 从缓冲区lpszBuffer中获得抽取出MAC串。
//
//  提示：可以方便的由此程序获得IP地址等其他信息。
//        对于其他的可以通过其他命令方式得到的信息只需改变strFetCmd 和
//        str4Search的内容即可。
///////////////////////////////////////////////////////////////////////////

int CWXFun::GetMacByCmd(std::string& strMac)
{
	
	char lpszMac[128];
	//命令行输出缓冲大小
	const long MAX_COMMAND_SIZE = 10000;

	//获取MAC命令行
	char szFetCmd[] = "ipconfig /all";
	//网卡MAC地址的前导信息
	const std::string str4Search = "Physical Address. . . . . . . . . : ";
	//初始化返回MAC地址缓冲区
	memset(lpszMac, 0x00, sizeof(lpszMac));
	BOOL bret; 

	SECURITY_ATTRIBUTES sa;
	HANDLE hReadPipe,hWritePipe;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//创建管道
	bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
	if(!bret)
	{
		return -2;
	}

	//控制命令行窗口信息
	STARTUPINFO si;
	//返回进程信息
	PROCESS_INFORMATION pi;

	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = hWritePipe;
	si.hStdOutput = hWritePipe;
	si.wShowWindow = SW_HIDE; //隐藏命令行窗口
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	//创建获取命令行进程
	bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL,
		NULL, &si, &pi );

	char szBuffer[MAX_COMMAND_SIZE+1]; //放置命令行输出缓冲区
	std::string strBuffer;

	if (bret)
	{
		WaitForSingleObject (pi.hProcess, INFINITE);
		unsigned long count;

		memset(szBuffer, 0x00, sizeof(szBuffer));
		bret  =  ReadFile(hReadPipe,  szBuffer,  MAX_COMMAND_SIZE,  &count,  0);
		if(!bret)
		{
			//关闭所有的句柄
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

			//提取MAC地址串
			strBuffer = strBuffer.substr(ipos+str4Search.length());
			ipos = strBuffer.find("\n");
			strBuffer = strBuffer.substr(0, ipos);
		}

	}
	
	memset(szBuffer, 0x00, sizeof(szBuffer));
	strcpy_s(szBuffer, strBuffer.c_str());

	//去掉中间的“00-50-EB-0F-27-82”中间的'-'得到0050EB0F2782
	int j = 0;
	for(int i=0; i<(int)strlen(szBuffer); i++)
	{
		if(szBuffer[i] != '-')
		{
			lpszMac[j] = szBuffer[i];
			j++;
		}
	}

	//关闭所有的句柄
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


int CWXFun::GetIPMacHostName(std::string& strIP, std::string& strMac, std::string& strHostName)
{
	return GetIPHostName(strIP, strHostName) + GetMacByCmd(strMac);
}