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


//删除一个用户
bool CEmployee::Delete(int nID, int nOpertor)
{
	DB::Employee()->Delete(nID, nOpertor);

	return true;
}
//修改一个用户
bool CEmployee::Edit(WXDB::DBEmployeeData& data)
{
	DB::Employee()->Edit(data);

	return true;
}
//添加一个用户
bool CEmployee::Add(WXDB::DBEmployeeData& data)
{

	DB::Employee()->Add(data);

	return true;
}



//获得所有数据保存在内存数据中
bool CEmployee::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Employee()->GetAllList(this->m_memDataVec);

	return true;
}

//通过员工ID获得员工信息
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


//员工是否可以被修改
bool CEmployee::IsPermitEdit(int nID)
{
	WXDB::DBEmployeeData data;
	if(GetInfo(nID, data))
	{
		if(data._recordStat==WXDB::E_DICTIONARY_STATE_CREATE || data._recordStat==WXDB::E_DICTIONARY_STATE_EDIT)
		{
			return true;
		}
	}

	return false;
}


NAMESPACE_BNS_END
