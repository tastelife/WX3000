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



//����б�
void CPower::GetUserGroupViewAllList(CWXMemDataVector<DBUserGroupViewData>& memDataVec)
{
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_userGroup_id]"
		" ,[col_user_id]"
		" ,[col_group_id]"
		" ,[col_user_loginName]"
		" ,[col_group_name]"
		" FROM [wx].[dbo].[View_UserGroup]");
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBUserGroupViewData>()(rec, memDataVec);
}

//�顢���ܵ㡢Ȩ����ͼ������б�
void CPower::GetGroupFunPointPowerViewAllList(CWXMemDataVector<DBGroupFunPointPowerViewData>& memDataVec)
{
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_group_id]"
		" ,[col_functinPoint_name]"
		" ,[col_functinPoint_displayName]"
		" ,[col_groupFuncitonPointPower]"
		" FROM [wx].[dbo].[View_GroupFunPointPower]");
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBGroupFunPointPowerViewData>()(rec, memDataVec);
}


//�û������е�user id��ȷ���true
bool CPower::IsUserIDDueGroup(DBUserGroupViewData dbUserGroupViewData, int nUserID)
{
	return dbUserGroupViewData._userID == nUserID;
}

//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ㣽user������true
bool CPower::IsGroupIDDueUserPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID)
{
	if(dbGroupFunPointPowerViewData._funPointName!="user")
	{
		return false;
	}
	return dbGroupFunPointPowerViewData._groupID == nGroupID;
}
//�顢���ܵ㡢Ȩ����ͼ�е� ��id��� ���ܵ�=��power������true
bool CPower::IsGroupIDDuePowerPower(DBGroupFunPointPowerViewData dbGroupFunPointPowerViewData, int nGroupID)
{
	if(dbGroupFunPointPowerViewData._funPointName!="power")
	{
		return false;
	}
	return dbGroupFunPointPowerViewData._groupID == nGroupID;
}


NAMESPACE_DB_END

