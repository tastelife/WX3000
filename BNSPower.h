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

public:
	//内存数据
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
};


NAMESPACE_BNS_END

