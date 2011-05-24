#include "StdAfx.h"
#include "BNSPower.h"

#include "StaticDB.h"

#include <functional>



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
	DB::Power()->GetGroupFunPointPowerViewAllList(this->m_memDataVecGroupFunPointPowerViewData);

	return true;
}


//指定用户对用户模块拥有的权限
WXDB::Power CPower::GetUserPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueUserPower);
}
//指定用户对权限模块拥有的权限
WXDB::Power CPower::GetPowerPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDuePowerPower);
}
//指定用户对部门模块拥有的权限
WXDB::Power CPower::GetCompanyBasePower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueCompanyBasePower);
}
//指定用户对员工模块拥有的权限
WXDB::Power CPower::GetEmployeePower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueEmployeePower);
}
//指定用户对客户模块拥有的权限
WXDB::Power CPower::GetCustomerPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueCustomerPower);
}
//指定用户对供应商模块拥有的权限
WXDB::Power CPower::GetSupplierPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueSupplierPower);
}


NAMESPACE_BNS_END

