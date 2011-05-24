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
	//����б�
	void GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec);

	//ID���ʱ����true
	static bool IsIDDue(DBEmployeeData data, int nID);
private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};




NAMESPACE_DB_END

