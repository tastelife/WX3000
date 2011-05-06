#include "StdAfx.h"
#include "DBPower.h"


NAMESPACE_DB_BEGIN

CPower::CPower(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CPower::CPower(void)
{
}

CPower::~CPower(void)
{
}



//获得列表
void CPower::GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_userGroup_id]"
		" ,[col_user_id]"
		" ,[col_group_id]"
		" ,[col_user_loginName]"
		" ,[col_group_name]"
		" FROM [wx].[dbo].[View_UserGroup]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBUserGroupViewData>()(rec, memDataVec);
}

//组、功能点、权限视图　获得列表
void CPower::GetGroupFunPointPowerViewAllList(CWXMemDataVector<DBGroupFunPointPowerViewData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_group_id]"
		" ,[col_functinPoint_name]"
		" ,[col_functinPoint_displayName]"
		" ,[col_groupFuncitonPointPower]"
		" FROM [wx].[dbo].[View_GroupFunPointPower]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBGroupFunPointPowerViewData>()(rec, memDataVec);
}


//用户、组中的user id相等返回true
bool CPower::IsUserIDDueGroup(DBUserGroupViewData dbUserGroupViewData, int nUserID)
{
	return dbUserGroupViewData._userID == nUserID;
}

//组、功能点、权限视图中的 组id相等 功能点＝user”返回true
bool CPower::IsGroupIDDueUserPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID)
{
	if(dbGroupFunPointPowerViewData._funPointName!="user")
	{
		return false;
	}
	return dbGroupFunPointPowerViewData._groupID == nGroupID;
}
//组、功能点、权限视图中的 组id相等 功能点=“power”返回true
bool CPower::IsGroupIDDuePowerPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID)
{
	if(dbGroupFunPointPowerViewData._funPointName!="power")
	{
		return false;
	}
	return dbGroupFunPointPowerViewData._groupID == nGroupID;
}


NAMESPACE_DB_END

