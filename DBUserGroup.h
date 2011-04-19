#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CUserGroup
{
public:
	CUserGroup(CWXDBConnect* pDBCon);
	virtual ~CUserGroup(void);
private:
	CUserGroup(void);
	
public:
	//�趨�û���������
	void SetUserGroupByUserID(int nUserID, int nGroupID, int nOpertor);

private:
	//���ݿ���
	CWXDBConnect* m_pDBCon;
};



NAMESPACE_DB_END

