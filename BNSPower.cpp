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
	WXDB::Power power;

	
	//�ڴ��е�������	
	WXDB::DBUserGroupViewData groupData;
	if(BNS::Power()->m_memDataVecUserGroupView.Find(std::bind2nd(
		std::ptr_fun(WXDB::CPower::IsUserIDDueGroup), nUserID), groupData))
	{
		//�ڴ��е�Ȩ������
		WXDB::DBGroupFunPointPowerViewData powerData;
		if(BNS::Power()->m_memDataVecGroupFunPointPowerViewData.Find(
			std::bind2nd(std::ptr_fun(WXDB::CPower::IsGroupIDDueUserPower), groupData._groupID), powerData))
		{
			power._nPower = powerData._groupFuncitonPointPower._nPower;
		}
	}

	return power;
}




NAMESPACE_BNS_END

