#pragma once

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>

NAMESPACE_DB_BEGIN


class CUser
{
public:
	CUser(CWXDBConnect* m_pDBCon);
	virtual ~CUser(void);
private:
	CUser(void);

public:
	//���һ����¼
	void Add(DBUserData& data);

	//�޸�һ����¼
	void Edit(DBUserData& data);

	//ɾ��һ����¼
	void Delete(int nID, int nOpretor);

	//�����ݿ����һ����¼
	bool Find(int nID, DBUserData& data);

	//����б�
	void GetAllList(CWXMemDataVector<DBUserData>& memDataVec);

	//�û��Ƿ����,���ڷ���true
	bool IsBeingByName(std::string strName);
	
	//�Ƿ������¼,������true
	bool IsLogin(std::string strName, std::string strPassWord, DBUserData* pData);

	//�����µ��û�ID
	int CreateNewID();
	
	//�û�����ȷ���true
	static bool IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName);
	//id��ȷ���true
	static bool IsIDDue(WXDB::DBUserData dbUserData, int nID);

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};

NAMESPACE_DB_END
