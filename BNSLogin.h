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
	//��¼
	bool Login(WXDB::DBLoginData& loginData);
	//�ǳ�
	bool Logout();

private:
	//�û��Ƿ��ѵ�¼,���ڷ���true
	bool IsLoging(int nUserID);

private:
	WXDB::DBUserData* m_pUserData;
	WXDB::DBLoginData m_loginData;
};


NAMESPACE_BNS_END

