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
	//获得列表
	void GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec);


private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};




NAMESPACE_DB_END

