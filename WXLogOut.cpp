#include "StdAfx.h"
#include <windows.h>
#include "WXLogOut.h"


CWXLogOut::CWXLogOut(void)
{
	SetFileName("wx3000");
	Init(1024000);
	this->SetOutDump(DUMPFALSE);
	SetOutputMod(MODEFILE);
}


CWXLogOut::~CWXLogOut(void)
{
}

//chLevel 1.异常；2.未能按正常的逻辑进行；3.运行痕迹
long CWXLogOut::Output(int nMessageID, int nMudle, const char *pcInfo, 
	const char *pcInData, long nDataLen, char chLevel)
{
	string strTemp;
	string strTemp1;
	stringstream	sstr;
	//得到时间
	SYSTEMTIME st;
	GetLocalTime(&st);
	sstr.width(4);
	sstr.fill('0');
	sstr << st.wYear << "/";
	sstr.width(2);
	sstr << st.wMonth << "/";
	sstr.width(2);
	sstr << st.wDay << " ";
	sstr.width(2);
	sstr << st.wHour << ":";
	sstr.width(2);
	sstr << st.wMinute << ":";
	sstr.width(2);
	sstr << st.wSecond;
	sstr >> strTemp;
	sstr >> strTemp1;
	strTemp += " ";
	strTemp += strTemp1;
	//数据合并
	strTemp += "\t|Level: ";
	sstr.clear();
	sstr << (int)chLevel;
	sstr >> strTemp1;
	strTemp += strTemp1;
	strTemp += "\t|Msg: ";
	sstr.clear();
	sstr << nMessageID;
	sstr >> strTemp1;
	strTemp += strTemp1;
	strTemp += "\t|Mudle: ";
	sstr.clear();
	sstr << nMudle;
	sstr >> strTemp1;
	strTemp += strTemp1;
	strTemp += "\t|";
	strTemp += pcInfo;

	CLogOut::OutputLog((char *)strTemp.c_str(), pcInData, nDataLen, chLevel);
	return 0;
}