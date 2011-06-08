#pragma once

#include "DBDictionary.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>
#include <vector>
#include <map>


NAMESPACE_BNS_BEGIN

class CDictionary
{
public:
	CDictionary(void);
	virtual ~CDictionary(void);
public:
	typedef std::map<int, std::string> LIST;
public:
	//����������ݱ������ڴ�������
	bool RefrushAll();

	//ͨ��ö��ֵ��� ��¼״̬��
	std::string GetRecordName(int nEnum);

	//ͨ��ö��ֵ��� �Ա���
	std::string GetSexName(int nEnum);
		
	//ͨ��ö��ֵ��� Ա��.ְλ��
	std::string GetEmployeePositionName(int nEnum);
	//ͨ��ö��ֵ�趨 Ա��.ְλ��
	void  SetEmployeePositionName(int nEnum, std::string strName, int nOperator);
	
	//ͨ��ö��ֵ��� Ա��.��ְ״̬ ��ʽ����ʱ����ְ���ݼ�
	std::string GetEmployeePositionState(int nEnum);
	
	//����Ա���б� ö��ֵ����Ӧ���� 
	LIST GetListByTypeSex();
	//���ְλ״̬���б� ö��ֵ����Ӧ���� 
	LIST GetListByTypePositionState();
	//���ְλ���б� ö��ֵ����Ӧ���� 
	LIST GetListByTypePosition();

private:
	//ͨ��ö��ֵ�������
	std::string GetName(std::string strType, int nEnum);
	//ͨ��ö��ֵ�趨����
	void SetName(std::string strType, int nEnum, std::string strName, 
		std::string strManual, int nOperator);
	//���ָ�����͵��б� ö��ֵ����Ӧ����
	LIST GetListByType(std::string strType);

public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBDictionaryData> m_memDataVec;
};


NAMESPACE_BNS_END
