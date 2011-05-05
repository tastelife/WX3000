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
	WXDB::Power power;

	
	//内存中的组数据	
	WXDB::DBUserGroupViewData groupData;
	if(BNS::Power()->m_memDataVecUserGroupView.Find(std::bind2nd(
		std::ptr_fun(WXDB::CPower::IsUserIDDueGroup), nUserID), groupData))
	{
		//内存中的权限数据
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

