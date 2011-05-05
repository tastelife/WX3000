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

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
	CWXMemDataVector<WXDB::DBGroupFunPointPowerViewData> m_memDataVecGroupFunPointPowerViewData;
};


NAMESPACE_BNS_END

