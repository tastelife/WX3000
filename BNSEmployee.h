#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN


class CEmployee
{
public:
	CEmployee(void);
	~CEmployee(void);

public:
	//����������ݱ������ڴ�������
	bool RefrushAll();
	//ͨ��Ա��ID���Ա����Ϣ
	bool GetInfo(int nID, WXDB::DBEmployeeData &data);
public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBEmployeeData> m_memDataVec;
};


NAMESPACE_BNS_END


