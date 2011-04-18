#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN


class CGroup
{
public:
	CGroup(CWXDBConnect* pDBCon);
	virtual ~CGroup(void);

private:
	CGroup(void);

public:
	//获得列表
	void GetAllList(CWXMemDataVector<DBGroupData>& memDataVec);

private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END


