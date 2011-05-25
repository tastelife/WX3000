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

	//ͨ��ö��ֵ��ü�¼״̬��
	std::string GetRecordName(int nEnum);

	//ͨ��ö��ֵ����Ա���
	std::string GetSexName(int nEnum);
		
	//ͨ��ö��ֵ���Ա��.ְλ��
	std::string GetEmployeePositionName(int nEnum);
	//ͨ��ö��ֵ�趨Ա��.ְλ��
	void  SetEmployeePositionName(int nEnum, std::string strName, int nOperator);

private:
	//ͨ��ö��ֵ�������
	std::string GetName(std::string strType, int nEnum);
	//ͨ��ö��ֵ�趨����
	void SetName(std::string strType, int nEnum, std::string strName, int nOperator);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBDictionaryData> m_memDataVec;
};


NAMESPACE_BNS_END
