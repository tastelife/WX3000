#pragma once

#include "LogOut.h"
#include "WXCommFun.h"

class CWXLogOut : public CLogOut  
{
private:
	enum
	{
		MODECOUT			= 0X01,
		MODEFILE			= 0X02,
		MODECOUTFILE		= 0X03,
	};
	enum
	{
		DUMPTRUE			= true,
		DUMPFALSE			= false,
	};

public:
	CWXLogOut(void);
	virtual ~CWXLogOut(void);
	//chLevel 1.异常；2.未能按正常的逻辑进行；3.运行痕迹
	long Output(int nMessageID, int nMudle, const char *pcInfo, 
		const char *pcInData, long nDataLen, char chLevel);
};

class CWXLogOutSingle : 
	public CWXCommSingleClass<CWXLogOut>
{
};

