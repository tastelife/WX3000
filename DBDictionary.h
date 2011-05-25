#pragma once

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>

NAMESPACE_DB_BEGIN



class CDictionary
{
public:
	CDictionary::CDictionary(CWXDBConnect* pDBCon);
	virtual ~CDictionary(void);
private:
	CDictionary(void);

public:
	//修改一条记录
	void Edit(DBDictionaryData& data);

	//获得列表
	void GetAllList(CWXMemDataVector<DBDictionaryData>& memDataVec);

	//类型、枚举值　相等返回true
	static bool  IsTypeEnumDue(WXDB::DBDictionaryData dbDictionaryData, std::pair<std::string, int> pairData);

private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END
