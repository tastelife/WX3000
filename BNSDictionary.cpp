#include "StdAfx.h"
#include "BNSDictionary.h"

#include "StaticDB.h"
#include <functional>


NAMESPACE_BNS_BEGIN



CDictionary::CDictionary(void)
{
}

CDictionary::~CDictionary(void)
{
}


//获得所有数据保存在内存数据中
bool CDictionary::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Dictionary()->GetAllList(this->m_memDataVec);

	return true;
}


//通过枚举值获得名称
std::string CDictionary::GetName(std::string strName, int nEnum)
{
	WXDB::DBDictionaryData dictionaryData;
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CDictionary::IsTypeEnumDue), std::pair<std::string,int>(strName, nEnum)), 
		dictionaryData))
	{
		return dictionaryData._name;
	}

	return "";
}


//通过枚举值获得指定的记录状态名
std::string CDictionary::GetRecordName(int nEnum)
{
	return this->GetName("recordState", nEnum);
}



NAMESPACE_BNS_END

