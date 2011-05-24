#include "StdAfx.h"
#include "BNSEmployee.h"


#include "StaticDB.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN



CEmployee::CEmployee(void)
{
}

CEmployee::~CEmployee(void)
{
}



//����������ݱ������ڴ�������
bool CEmployee::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Employee()->GetAllList(this->m_memDataVec);

	return true;
}

//ͨ��Ա��ID���Ա����Ϣ
bool CEmployee::GetInfo(int nID, WXDB::DBEmployeeData &data)
{
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CEmployee::IsIDDue), nID), 
		data))
	{
		return true;
	}

	return false;
}


NAMESPACE_BNS_END
