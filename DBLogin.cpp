#include "StdAfx.h"
#include "DBLogin.h"

#include <sstream>

NAMESPACE_DB_BEGIN


CLogin::CLogin(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CLogin::CLogin(void)
{
}

CLogin::~CLogin(void)
{
}


//登录
void CLogin::Login(DBLoginData& loginData)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBLoginData>()(loginData, vecVarParam);

	//执行
	this->m_pDBCon->ExecStoredProc("login_login", vecVarParam);
}

//登出
void CLogin::Logout(int nID, int nState, int nOperator)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nState));
	vecVarParam.push_back(_variant_t(nOperator));

	//执行
	this->m_pDBCon->ExecStoredProc("login_logout", vecVarParam);
}

//异常登出
void CLogin::Logout(int nUserID, int nOperator)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nUserID));
	vecVarParam.push_back(_variant_t(nOperator));

	//执行
	this->m_pDBCon->ExecStoredProc("[login_logoutException]", vecVarParam);
}

//异常登出全部
void CLogin::Logout(int nOperator)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nOperator));

	//执行
	this->m_pDBCon->ExecStoredProc("[login_logoutExceptionAll]", vecVarParam);
}

//创建新的用户ID
int CLogin::CreateNewID()
{
	//存储过程参数 无
	std::vector<_variant_t> vecVarParam;

	//执行
	return this->m_pDBCon->ExecStoredProc("login_CreateNewID", vecVarParam, NULL).iVal;
}

//用户是否已登录,存在返回true
bool CLogin::IsLoging(int nUserID)
{
	bool bRtn = false;
	//存储过程参数 用户名
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nUserID));

	//执行
	int nCount = this->m_pDBCon->ExecStoredProc("login_IsLogining", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}


NAMESPACE_DB_END