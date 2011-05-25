#include "StdAfx.h"

#include "DBUser.h"
#include <sstream>

NAMESPACE_DB_BEGIN


CUser::CUser(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CUser::CUser(void)
{
}

CUser::~CUser(void)
{
}


//���һ����¼
void CUser::Add(DBUserData& data)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBUserData>()(data, vecVarParam);

	//ִ��
	this->m_pDBCon->ExecStoredProc("user_add", vecVarParam);
}


//�޸�һ����¼
void CUser::Edit(DBUserData& data)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBUserData>()(data, vecVarParam);

	//ִ��
	this->m_pDBCon->ExecStoredProc("user_edit", vecVarParam);
}

//ɾ��һ����¼
void CUser::Delete(int nID, int nOpretor)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nOpretor));

	//ִ��
	this->m_pDBCon->ExecStoredProc("user_delete", vecVarParam);
}



//����б�
void CUser::GetAllList(CWXMemDataVector<DBUserData>& memDataVec)
{
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_user_id]"
		",[col_user_loginName]"
		" ,[col_user_empId]"
		" ,[col_user_passwd]"
		" ,[col_user_recordState]"
		" ,[col_user_operator]"
		" ,[col_user_operatoTime]"
		" ,[col_user_copyFromID]"
		" FROM [wx].[dbo].[userTBL]");
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);
}


//�û��Ƿ����,���ڷ���true
bool CUser::IsBeingByName(std::string strName)
{
	bool bRtn = false;
	//�洢���̲��� �û���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(strName.c_str()));

	//ִ��
	int nCount = this->m_pDBCon->ExecStoredProc("user_IsBeing", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}

//�����µ��û�ID
int CUser::CreateNewID()
{
	//�洢���̲��� ��
	std::vector<_variant_t> vecVarParam;

	//ִ��
	return this->m_pDBCon->ExecStoredProc("user_CreateNewID", vecVarParam, NULL).iVal;
}


//�����ݿ����һ����¼
bool CUser::Find(int nID, DBUserData& data)
{
	//sql 
	std::string strSql;

	std::stringstream ss;
	ss << nID;
	ss >> strSql;
	strSql = "SELECT [col_user_id]"
		",[col_user_loginName]"
		" ,[col_user_empId]"
		" ,[col_user_passwd]"
		" ,[col_user_recordState]"
		" ,[col_user_operator]"
		" ,[col_user_operatoTime]"
		" ,[col_user_copyFromID]"
		" FROM [wx].[dbo].[userTBL]" 
		" where col_user_id = "
		+ strSql;

	CWXMemDataVector<DBUserData> memDataVec;
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);
	if(memDataVec.size()<=0)
	{
		return false;
	}

	data = memDataVec.at(0);

	return true;
}


//�Ƿ������¼,������true
bool CUser::IsLogin(std::string strName, std::string strPassWord, DBUserData* pData)
{
	bool bRtn = false;

	//sql 
	std::string strSql;

	strSql = "SELECT [col_user_id]"
		",[col_user_loginName]"
		" ,[col_user_empId]"
		" ,[col_user_passwd]"
		" ,[col_user_recordState]"
		" ,[col_user_operator]"
		" ,[col_user_operatoTime]"
		" ,[col_user_copyFromID]"
		" FROM [wx].[dbo].[userTBL]" 
		" where col_user_loginName = '"
		+ strName
		+ "' and col_user_passwd = '"
		+ strPassWord
		+ "'"
		+ " and (col_user_recordState = " + CWXConver::single2s(E_DICTIONARY_STATE_CREATE) 
		+ " OR col_user_recordState = " + CWXConver::single2s(E_DICTIONARY_STATE_EDIT) + ")";

	CWXMemDataVector<DBUserData> memDataVec;
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);

	//ִ��

	if(memDataVec.size()>0)
	{
		if(NULL!=pData)
		{
			*pData = memDataVec.at(0);
		}

		bRtn = true;
	}

	return bRtn;
}


//�û�����ȷ���true
bool  CUser::IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName)
{
	return dbUserData._loginName==strName;
}


//id��ȷ���true
bool CUser::IsIDDue(WXDB::DBUserData dbUserData, int nID)
{
	return dbUserData._id ==nID;
}



NAMESPACE_DB_END
