#pragma once
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>
#include <map>


NAMESPACE_BNS_BEGIN


class CCompanyBase
{
public:
	CCompanyBase(void);
	virtual ~CCompanyBase(void);

public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();
	
	//通过部门ID获得部门信息
	bool GetInfo(int nID, WXDB::DBCompanyBaseData &data);

	//部门枚举
	std::map<int, std::string> GetEnumList();

public:
	//内存数据
	CWXMemDataVector<WXDB::DBCompanyBaseData> m_memDataVec;
};



NAMESPACE_BNS_END



