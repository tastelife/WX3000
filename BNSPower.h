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

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBUserGroupViewData> m_memDataVecUserGroupView;
};


NAMESPACE_BNS_END

