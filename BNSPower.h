#pragma once

#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_BNS_BEGIN


class CPower
{
public:
	CPower(void);
	virtual ~CPower(void);
	
public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();
	//指定用户对用户模块拥有的权限
	WXDB::Power GetUserPower(int nUserID);
	//指定用户对权限模块拥有的权限
	WXDB::Power GetPowerPower(int nUserID);

public:
	//内存数据
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
	CWXMemDataVector<WXDB::DBGroupFunPointPowerViewData> m_memDataVecGroupFunPointPowerViewData;
};


NAMESPACE_BNS_END

