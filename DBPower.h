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
	//用户、组　获得列表
	void GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec);
	//组、功能点、权限视图　获得列表
	void GetGroupFunPointPowerViewAllList(CWXMemDataVector<DBGroupFunPointPowerViewData>& memDataVec);
	
	
	//用户、组中的user id相等返回true
	static bool IsUserIDDueGroup(DBUserGroupViewData dbUserGroupViewData, int nUserID);
	
	//组、功能点、权限视图中的 组id相等 功能点＝“user”返回true
	static bool IsGroupIDDueUserPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//组、功能点、权限视图中的 组id相等 功能点=“power”返回true
	static bool IsGroupIDDuePowerPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

