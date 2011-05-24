#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CPower
{
public:
	CPower(CWXDBConnect* pDBCon);
	virtual ~CPower(void);
private:
	CPower(void);

public:
	//�û����顡����б�
	void GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec);
	//�顢���ܵ㡢Ȩ����ͼ������б�
	void GetGroupFunPointPowerViewAllList(CWXMemDataVector<DBGroupFunPointPowerViewData>& memDataVec);
	
	
	//�û������е�user id��ȷ���true
	static bool IsUserIDDueGroup(DBUserGroupViewData dbUserGroupViewData, int nUserID);
	
	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ㣽��user������true
	static bool IsGroupIDDueUserPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��power������true
	static bool IsGroupIDDuePowerPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��companyBase������true
	static bool IsGroupIDDueCompanyBasePower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��employee������true
	static bool IsGroupIDDueEmployeePower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��customer������true
	static bool IsGroupIDDueCustomerPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

	//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��supplier������true
	static bool IsGroupIDDueSupplierPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID);

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

