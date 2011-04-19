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



//设定用户关联的组
bool CUserGroup::SetUserGroupByUserID(int nUserID, int nGroupID)
{
	DB::UserGroup()->SetUserGroupByUserID(nUserID, nGroupID, 0);
	return true;
}


NAMESPACE_BNS_END

