#pragma once


#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_BNS_BEGIN


class CUserGroup
{
public:
	CUserGroup(void);
	virtual ~CUserGroup(void);

public:
	//�趨�û���������
	bool SetUserGroupByUserID(int nUserID, int nGroupID);
};



NAMESPACE_BNS_END

