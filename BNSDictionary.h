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

	//通过枚举值获得记录状态名
	std::string GetRecordName(int nEnum);

	//通过枚举值获得性别名
	std::string GetSexName(int nEnum);
		
	//通过枚举值获得员工.职位名
	std::string GetEmployeePositionName(int nEnum);
	//通过枚举值设定员工.职位名
	void  SetEmployeePositionName(int nEnum, std::string strName, int nOperator);

private:
	//通过枚举值获得名称
	std::string GetName(std::string strType, int nEnum);
	//通过枚举值设定名称
	void SetName(std::string strType, int nEnum, std::string strName, int nOperator);

public:
	//内存数据
	CWXMemDataVector<WXDB::DBDictionaryData> m_memDataVec;
};


NAMESPACE_BNS_END
