#include "StdAfx.h"
#include "BNSUserGroup.h"


#include "StaticDB.h"



NAMESPACE_BNS_BEGIN


CUserGroup::CUserGroup(void)
{
}

CUserGroup::~CUserGroup(void)
{
}



//�趨�û���������
bool CUserGroup::SetUserGroupByUserID(int nUserID, int nGroupID)
{
	DB::UserGroup()->SetUserGroupByUserID(nUserID, nGroupID, 0);
	return true;
}


NAMESPACE_BNS_END

