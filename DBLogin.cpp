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


//��¼
void CLogin::Login(DBLoginData& loginData)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBLoginData>()(loginData, vecVarParam);

	//ִ��
	this->m_pDBCon->ExecStoredProc("login_login", vecVarParam);
}

//�ǳ�
void CLogin::Logout(int nID, int nState, int nOperator)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nState));
	vecVarParam.push_back(_variant_t(nOperator));

	//ִ��
	this->m_pDBCon->ExecStoredProc("login_logout", vecVarParam);
}

//�쳣�ǳ�
void CLogin::Logout(int nUserID, int nOperator)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nUserID));
	vecVarParam.push_back(_variant_t(nOperator));

	//ִ��
	this->m_pDBCon->ExecStoredProc("[login_logoutException]", vecVarParam);
}

//�쳣�ǳ�ȫ��
void CLogin::Logout(int nOperator)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nOperator));

	//ִ��
	this->m_pDBCon->ExecStoredProc("[login_logoutExceptionAll]", vecVarParam);
}

//�����µ��û�ID
int CLogin::CreateNewID()
{
	//�洢���̲��� ��
	std::vector<_variant_t> vecVarParam;

	//ִ��
	return this->m_pDBCon->ExecStoredProc("login_CreateNewID", vecVarParam, NULL).iVal;
}

//�û��Ƿ��ѵ�¼,���ڷ���true
bool CLogin::IsLoging(int nUserID)
{
	bool bRtn = false;
	//�洢���̲��� �û���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nUserID));

	//ִ��
	int nCount = this->m_pDBCon->ExecStoredProc("login_IsLogining", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}


NAMESPACE_DB_END