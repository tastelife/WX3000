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
	//����������ݱ������ڴ�������
	bool RefrushAll();
	//ָ���û����û�ģ��ӵ�е�Ȩ��
	WXDB::Power GetUserPower(int nUserID);
	//ָ���û���Ȩ��ģ��ӵ�е�Ȩ��
	WXDB::Power GetPowerPower(int nUserID);
	//ָ���û��Բ���ģ��ӵ�е�Ȩ��
	WXDB::Power GetCompanyBasePower(int nUserID);
	//ָ���û���Ա��ģ��ӵ�е�Ȩ��
	WXDB::Power GetEmployeePower(int nUserID);
	//ָ���û��Կͻ�ģ��ӵ�е�Ȩ��
	WXDB::Power GetCustomerPower(int nUserID);
	//ָ���û��Թ�Ӧ��ģ��ӵ�е�Ȩ��
	WXDB::Power GetSupplierPower(int nUserID);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
	CWXMemDataVector<WXDB::DBGroupFunPointPowerViewData> m_memDataVecGroupFunPointPowerViewData;

private:
	//ָ���û���ָ��ģ��ӵ�е�Ȩ��
	template<class _Pr>
	WXDB::Power GetPower(int nUserID, _Pr pred);
	
};

//ָ���û���ָ��ģ��ӵ�е�Ȩ��
template<class _Pr>
WXDB::Power CPower::GetPower(int nUserID, _Pr pred)
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
			std::bind2nd(std::ptr_fun(pred), groupData._groupID), powerData))
		{
			power._nPower = powerData._groupFuncitonPointPower._nPower;
		}
	}

	return power;
}

NAMESPACE_BNS_END

