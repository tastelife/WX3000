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



//����������ݱ������ڴ�������
bool CPower::RefrushAll()
{
	this->m_memDataVecUserGroupView.clear();

	DB::Power()->GetUserGroupViewAllList(this->m_memDataVecUserGroupView);

	return true;
}



NAMESPACE_BNS_END

