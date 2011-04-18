#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CPower
{
public:
	CPower(CWXDBConnect* pDBCon);
	virtual ~CPower(void);
private:
	CPower(void);

public:
	//获得列表
	void GetAllList(CWXMemDataVector<DBPowerViewData>& memDataVec);
	
private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

