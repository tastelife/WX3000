#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CPower
{
public:
	CPower(CWXDBConnect* pDBCon);
	virtual ~CPower(void);
private:
	CPower(void);

public:
	//�û������б�
	void GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec);
	
private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

