#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN


class CGroup
{
public:
	CGroup(CWXDBConnect* pDBCon);
	virtual ~CGroup(void);

private:
	CGroup(void);

public:
	//����б�
	void GetAllList(CWXMemDataVector<DBGroupData>& memDataVec);

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END


