#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CUserGroup
{
public:
	CUserGroup(CWXDBConnect* pDBCon);
	virtual ~CUserGroup(void);
private:
	CUserGroup(void);
	
public:
	//设定用户关联的组
	void SetUserGroupByUserID(int nUserID, int nGroupID, int nOpertor);

private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

