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



//获得所有数据保存在内存数据中
bool CEmployee::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Employee()->GetAllList(this->m_memDataVec);

	return true;
}



NAMESPACE_BNS_END
