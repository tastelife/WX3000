#pragma once

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>

NAMESPACE_DB_BEGIN



class CLogin
{
public:
	CLogin(CWXDBConnect* pDBCon);
	virtual ~CLogin(void);
private:
	CLogin(void);

public:
	//登录
	void Login(WXDB::DBLoginData& loginData);
	//登出
	void Logout(int nID, int nState, int nOperator);
	//异常登出
	void Logout(int nUserID, int nOperator);
	//异常登出全部
	void Logout(int nOperator);
	
	//创建新的用户ID
	int CreateNewID();

	//用户是否已登录,存在返回true
	bool IsLoging(int nUserID);

private:
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END
