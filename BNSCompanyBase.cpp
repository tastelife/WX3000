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


//获得所有数据保存在内存数据中
bool CCompanyBase::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::CompanyBase()->GetAllList(this->m_memDataVec);

	return true;
}



//通过部门ID获得部门信息
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


