#pragma once

#include "DBDictionary.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN

class CDictionary
{
public:
	CDictionary(void);
	virtual ~CDictionary(void);
public:
	//����������ݱ������ڴ�������
	bool RefrushAll();

	//ͨ��ö��ֵ���ָ���ļ�¼״̬��
	std::string GetRecordName(int nEnum);

private:
	//ͨ��ö��ֵ�������
	std::string GetName(std::string strName, int nEnum);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBDictionaryData> m_memDataVec;
};


NAMESPACE_BNS_END
