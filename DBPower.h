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
	//用户组获得列表
	void GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec);
	
private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

