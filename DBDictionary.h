#pragma once

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>

NAMESPACE_DB_BEGIN



class CDictionary
{
public:
	CDictionary::CDictionary(CWXDBConnect* pDBCon);
	virtual ~CDictionary(void);
private:
	CDictionary(void);

public:
	//�޸�һ����¼
	void Edit(DBDictionaryData& data);

	//����б�
	void GetAllList(CWXMemDataVector<DBDictionaryData>& memDataVec);

	//���͡�ö��ֵ����ȷ���true
	static bool  IsTypeEnumDue(WXDB::DBDictionaryData dbDictionaryData, std::pair<std::string, int> pairData);

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};


NAMESPACE_DB_END
