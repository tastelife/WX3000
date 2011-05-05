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
	//��¼
	bool Login(std::string strName, std::string strPassWord);
	//�ǳ�
	bool Logout();
	//��¼ID
	int GetLoginID();

private:
	//�û��Ƿ��ѵ�¼,���ڷ���true
	bool IsLoging(int nUserID);
	//��¼
	bool Login(WXDB::DBLoginData& loginData);

private:
	WXDB::DBUserData* m_pUserData;
	WXDB::DBLoginData m_loginData;
};


NAMESPACE_BNS_END

