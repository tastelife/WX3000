#pragma once


#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN


class CLogin
{
public:
	CLogin(void);
	virtual ~CLogin(void);

public:
	//登录
	bool Login(std::string strName, std::string strPassWord);
	//登出
	bool Logout();
	//登录ID
	int GetLoginID();

private:
	//用户是否已登录,存在返回true
	bool IsLoging(int nUserID);
	//登录
	bool Login(WXDB::DBLoginData& loginData);

private:
	WXDB::DBUserData* m_pUserData;
	WXDB::DBLoginData m_loginData;
};


NAMESPACE_BNS_END

