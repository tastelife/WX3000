#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CEmployee
{
public:
	CEmployee(CWXDBConnect* pDBCon);
	virtual ~CEmployee(void);
private:
	CEmployee(void);


public:
	//���һ����¼
	void Add(DBEmployeeData& data);

	//�޸�һ����¼
	void Edit(DBEmployeeData& data);

	//ɾ��һ����¼
	void Delete(int nID, int nOpretor);

	//�����ݿ����һ����¼
	bool Find(int nID, DBEmployeeData& data);
	
	//Ա���Ƿ����,���ڷ���true
	bool IsBeingByID(int nID);

	//����б�
	void GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec);

	//ID���ʱ����true
	static bool IsIDDue(DBEmployeeData data, int nID);
private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};




NAMESPACE_DB_END

