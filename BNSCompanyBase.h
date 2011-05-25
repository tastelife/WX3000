#pragma once
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN


class CCompanyBase
{
public:
	CCompanyBase(void);
	virtual ~CCompanyBase(void);

public:
	//����������ݱ������ڴ�������
	bool RefrushAll();
	
	//ͨ������ID��ò�����Ϣ
	bool GetInfo(int nID, WXDB::DBCompanyBaseData &data);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBCompanyBaseData> m_memDataVec;
};



NAMESPACE_BNS_END



