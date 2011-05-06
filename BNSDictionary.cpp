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


//����������ݱ������ڴ�������
bool CDictionary::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Dictionary()->GetAllList(this->m_memDataVec);

	return true;
}


//ͨ��ö��ֵ�������
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


//ͨ��ö��ֵ���ָ���ļ�¼״̬��
std::string CDictionary::GetRecordName(int nEnum)
{
	return this->GetName("recordState", nEnum);
}



NAMESPACE_BNS_END

