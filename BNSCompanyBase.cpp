#include "StdAfx.h"
#include "BNSCompanyBase.h"


#include "StaticDB.h"


NAMESPACE_BNS_BEGIN



CCompanyBase::CCompanyBase(void)
{
}


CCompanyBase::~CCompanyBase(void)
{
}


//����������ݱ������ڴ�������
bool CCompanyBase::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::CompanyBase()->GetAllList(this->m_memDataVec);

	return true;
}



//ͨ������ID��ò�����Ϣ
bool CCompanyBase::GetInfo(int nID, WXDB::DBCompanyBaseData &data)
{
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CCompanyBase::IsIDDue), nID), 
		data))
	{
		return true;
	}

	return false;
}


NAMESPACE_BNS_END


