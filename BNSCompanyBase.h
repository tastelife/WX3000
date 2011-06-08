#pragma once
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>
#include <map>


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

	//����ö��
	std::map<int, std::string> GetEnumList();

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBCompanyBaseData> m_memDataVec;
};



NAMESPACE_BNS_END



