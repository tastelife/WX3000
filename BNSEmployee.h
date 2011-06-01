#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>
#include "WXBNSDataType.h"



NAMESPACE_BNS_BEGIN


class CEmployee
{
public:
	CEmployee(void);
	~CEmployee(void);

public:	
	//���һ���û�
	bool Add(const BNSEmployeeData& data);	
	//�޸�һ���û�
	bool Edit(const BNSEmployeeData& data);
	//ɾ��һ���û�
	bool Delete(int nID);

	//����������ݱ������ڴ�������
	bool RefrushAll();

	//ͨ��Ա��ID���Ա����Ϣ
	bool GetInfo(int nID, WXDB::DBEmployeeData &data);
	
	//Ա���Ƿ���Ա��޸�
	bool IsPermitEdit(int nID);
	
private:
	//���һ���û�
	bool Add(WXDB::DBEmployeeData& data);
	//�޸�һ���û�
	bool Edit(WXDB::DBEmployeeData& data);
	//ɾ��һ���û�
	bool Delete(int nID, int nOpertor);
public:
	//�ڴ�����
	CWXMemDataVector<WXDB::DBEmployeeData> m_memDataVec;
};


NAMESPACE_BNS_END


