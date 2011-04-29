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


NAMESPACE_DB_END

