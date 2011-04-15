#pragma once


#include "DBUser.h"
#include "DBLogin.h"
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
	//登录
	bool Login(WXDB::DBLoginData& loginData);
	//登出
	bool Logout();

private:
	//用户是否已登录,存在返回true
	bool IsLoging(int nUserID);

private:
	WXDB::DBUserData* m_pUserData;
	WXDB::DBLoginData m_loginData;

private:
	//数据库连接	
	CWXDBConnect db;
	WXDB::CUser dbUser;
	WXDB::CLogin dbLogin;
};


NAMESPACE_BNS_END

