#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN

class CUser
{
public:
	CUser(void);
	virtual ~CUser(void);

public:
	//���һ���û�
	bool Add(std::string strName, std::string strPassWord, int nEmpID);	
	//�޸�һ���û�
	bool Edit(int nID, std::string strPassWord, int nEmpID);
	//ɾ��һ���û�
	bool Delete(int nID);
	//���һ���û���
	bool FindUserName(int nID, std::string& strUserName);

	//����������ݱ������ڴ�������
	bool RefrushAll();

private:
	//���һ���û�
	bool Add(WXDB::DBUserData& data);
	//�޸�һ���û�
	bool Edit(WXDB::DBUserData& data);
	//ɾ��һ���û�
	bool Delete(int nID, int nOpertor);


private:
	//�û����ڴ�
	bool IsBeingInMem(std::string strName);
	//�û������ݿ�
	bool IsBeingInDB(std::string strName);

	//�����Ƿ񱻸���
	bool IsChanged(int nID, WXDB::DBUserData dbUserData);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBUserData> m_memDataVec;
};

NAMESPACE_BNS_END