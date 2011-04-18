#pragma once


#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"



NAMESPACE_BNS_BEGIN


class CGroup
{
public:
	CGroup(void);
	virtual ~CGroup(void);

public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();

public:
	//内存数据
	CWXMemDataVector<WXDB::DBGroupData> m_memDataVec;
};


NAMESPACE_DB_END

