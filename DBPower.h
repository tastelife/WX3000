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

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

