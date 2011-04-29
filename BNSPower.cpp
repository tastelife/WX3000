#include "StdAfx.h"
#include "BNSPower.h"

#include "StaticDB.h"



NAMESPACE_BNS_BEGIN


CPower::CPower(void)
{
}

CPower::~CPower(void)
{
}



//获得所有数据保存在内存数据中
bool CPower::RefrushAll()
{
	this->m_memDataVecUserGroupView.clear();

	DB::Power()->GetUserGroupViewAllList(this->m_memDataVecUserGroupView);

	return true;
}



NAMESPACE_BNS_END

