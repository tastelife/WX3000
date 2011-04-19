#include "StdAfx.h"
#include "DBUserGroup.h"


NAMESPACE_DB_BEGIN



CUserGroup::CUserGroup(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CUserGroup::CUserGroup(void)
{
}

CUserGroup::~CUserGroup(void)
{
}

//设定用户关联的组
void CUserGroup::SetUserGroupByUserID(int nUserID, int nGroupID, int nOpertor)
{
	
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nUserID));
	vecVarParam.push_back(_variant_t(nGroupID));
	vecVarParam.push_back(_variant_t(nOpertor));

	//执行
	this->m_pDBCon->ExecStoredProc("userGroup_setByUserID", vecVarParam);
}



NAMESPACE_DB_END


