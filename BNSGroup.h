#pragma once


#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"



NAMESPACE_BNS_BEGIN


class CGroup
{
public:
	CGroup(void);
	virtual ~CGroup(void);

public:
	//����������ݱ������ڴ�������
	bool RefrushAll();

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBGroupData> m_memDataVec;
};


NAMESPACE_DB_END

