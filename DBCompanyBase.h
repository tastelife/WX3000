#pragma once
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"



NAMESPACE_DB_BEGIN


class CCompanyBase
{
public:
	CCompanyBase(CWXDBConnect* pDBCon);
	virtual ~CCompanyBase(void);
private:
	CCompanyBase(void);


public:
	//����б�
	void GetAllList(CWXMemDataVector<DBCompanyBaseData>& memDataVec);
	
	//ID���ʱ����true
	static bool IsIDDue(DBCompanyBaseData data, int nID);
private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END


