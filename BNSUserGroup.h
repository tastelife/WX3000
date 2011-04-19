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
	//设定用户关联的组
	bool SetUserGroupByUserID(int nUserID, int nGroupID);
};



NAMESPACE_BNS_END

