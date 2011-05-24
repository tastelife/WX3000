#pragma once

#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_BNS_BEGIN


class CPower
{
public:
	CPower(void);
	virtual ~CPower(void);
	
public:
	//获得所有数据保存在内存数据中
	bool RefrushAll();
	//指定用户对用户模块拥有的权限
	WXDB::Power GetUserPower(int nUserID);
	//指定用户对权限模块拥有的权限
	WXDB::Power GetPowerPower(int nUserID);
	//指定用户对部门模块拥有的权限
	WXDB::Power GetCompanyBasePower(int nUserID);
	//指定用户对员工模块拥有的权限
	WXDB::Power GetEmployeePower(int nUserID);
	//指定用户对客户模块拥有的权限
	WXDB::Power GetCustomerPower(int nUserID);
	//指定用户对供应商模块拥有的权限
	WXDB::Power GetSupplierPower(int nUserID);

public:
	//内存数据
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
	CWXMemDataVector<WXDB::DBGroupFunPointPowerViewData> m_memDataVecGroupFunPointPowerViewData;

private:
	//指定用户对指定模块拥有的权限
	template<class _Pr>
	WXDB::Power GetPower(int nUserID, _Pr pred);
	
};

//指定用户对指定模块拥有的权限
template<class _Pr>
WXDB::Power CPower::GetPower(int nUserID, _Pr pred)
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
			std::bind2nd(std::ptr_fun(pred), groupData._groupID), powerData))
		{
			power._nPower = powerData._groupFuncitonPointPower._nPower;
		}
	}

	return power;
}

NAMESPACE_BNS_END

