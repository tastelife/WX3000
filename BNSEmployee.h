#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN


class CEmployee
{
public:
	CEmployee(void);
	~CEmployee(void);

public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();

public:
	//内存数据
	CWXMemDataVector<WXDB::DBEmployeeData> m_memDataVec;
};


NAMESPACE_BNS_END


