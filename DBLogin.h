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
	//��¼
	void Login(WXDB::DBLoginData& loginData);
	//�ǳ�
	void Logout(int nID, int nState, int nOperator);
	//�쳣�ǳ�
	void Logout(int nUserID, int nOperator);
	//�쳣�ǳ�ȫ��
	void Logout(int nOperator);
	
	//�����µ��û�ID
	int CreateNewID();

	//�û��Ƿ��ѵ�¼,���ڷ���true
	bool IsLoging(int nUserID);

private:
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END
