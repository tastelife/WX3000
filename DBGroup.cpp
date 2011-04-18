#include "StdAfx.h"
#include "DBGroup.h"



NAMESPACE_DB_BEGIN



CGroup::CGroup(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CGroup::CGroup(void)
{
}

CGroup::~CGroup(void)
{
}


//获得列表
void CGroup::GetAllList(CWXMemDataVector<DBGroupData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_group_id]"
		" ,[col_group_name]"
		" ,[col_group_recordState]"
		" ,[col_group_opertor]"
		" ,[col_group_opertoTime]"
		" ,[col_group_copyFromID]"
		" FROM [wx].[dbo].[group]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBGroupData>()(rec, memDataVec);
}



NAMESPACE_DB_END


