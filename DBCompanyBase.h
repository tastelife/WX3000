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
	//获得列表
	void GetAllList(CWXMemDataVector<DBCompanyBaseData>& memDataVec);
	
	//ID相等时返回true
	static bool IsIDDue(DBCompanyBaseData data, int nID);
private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END


