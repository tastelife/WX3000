#pragma once

#include "DBDictionary.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN

class CDictionary
{
public:
	CDictionary(void);
	virtual ~CDictionary(void);
public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();

	//通过枚举值获得指定的记录状态名
	std::string GetRecordName(int nEnum);

private:
	//通过枚举值获得名称
	std::string GetName(std::string strName, int nEnum);

public:
	//内存数据
	CWXMemDataVector<WXDB::DBDictionaryData> m_memDataVec;
};


NAMESPACE_BNS_END
