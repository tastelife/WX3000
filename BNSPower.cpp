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



//����������ݱ������ڴ�������
bool CPower::RefrushAll()
{
	this->m_memDataVecUserGroupView.clear();

	DB::Power()->GetUserGroupViewAllList(this->m_memDataVecUserGroupView);
	DB::Power()->GetGroupFunPointPowerViewAllList(this->m_memDataVecGroupFunPointPowerViewData);

	return true;
}


//ָ���û����û�ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetUserPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueUserPower);
}
//ָ���û���Ȩ��ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetPowerPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDuePowerPower);
}
//ָ���û��Բ���ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetCompanyBasePower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueCompanyBasePower);
}
//ָ���û���Ա��ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetEmployeePower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueEmployeePower);
}
//ָ���û��Կͻ�ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetCustomerPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueCustomerPower);
}
//ָ���û��Թ�Ӧ��ģ��ӵ�е�Ȩ��
WXDB::Power CPower::GetSupplierPower(int nUserID)
{
	return this->GetPower(nUserID, WXDB::CPower::IsGroupIDDueSupplierPower);
}


NAMESPACE_BNS_END

