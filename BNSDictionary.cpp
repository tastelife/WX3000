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
std::string CDictionary::GetName(std::string strType, int nEnum)
{
	WXDB::DBDictionaryData dictionaryData;
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CDictionary::IsTypeEnumDue), std::pair<std::string,int>(strType, nEnum)), 
		dictionaryData))
	{
		return dictionaryData._name;
	}

	return "";
}
//ͨ��ö��ֵ�趨����
void CDictionary::SetName(std::string strType, int nEnum, std::string strName, int nOperator)
{
	WXDB::DBDictionaryData data;
	data._type = strType;
	data._enum = nEnum;
	data._name = strName;
	data._operator = nOperator;
}

//ͨ��ö��ֵ��� ��¼״̬��
std::string CDictionary::GetRecordName(int nEnum)
{
	return this->GetName("recordState", nEnum);
}

//ͨ��ö��ֵ��� �Ա���
std::string CDictionary::GetSexName(int nEnum)
{
	return this->GetName("sex", nEnum);
}


//ͨ��ö��ֵ��� Ա��.ְλ��
std::string CDictionary::GetEmployeePositionName(int nEnum)
{
	return this->GetName("employee.position", nEnum);
}
//ͨ��ö��ֵ�趨 Ա��.ְλ��
void  CDictionary::SetEmployeePositionName(int nEnum, std::string strName, int nOperator)
{
	SetName("employee.position", nEnum, strName, nOperator);
}

//ͨ��ö��ֵ��� Ա��.��ְ״̬ ��ʽ����ʱ����ְ���ݼ�
std::string CDictionary::GetEmployeePositionState(int nEnum)
{
	return this->GetName("employee.positionState", nEnum);
}

NAMESPACE_BNS_END

