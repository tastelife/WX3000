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


//添加一条记录
void CUser::Add(DBUserData& data)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBUserData>()(data, vecVarParam);

	//执行
	this->m_pDBCon->ExecStoredProc("user_add", vecVarParam);
}


//修改一条记录
void CUser::Edit(DBUserData& data)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBUserData>()(data, vecVarParam);

	//执行
	this->m_pDBCon->ExecStoredProc("user_edit", vecVarParam);
}

//删除一条记录
void CUser::Delete(int nID, int nOpretor)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nOpretor));

	//执行
	this->m_pDBCon->ExecStoredProc("user_delete", vecVarParam);
}



//获得列表
void CUser::GetAllList(CWXMemDataVector<DBUserData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_user_id]"
		",[col_user_loginName]"
		" ,[col_user_empId]"
		" ,[col_user_passwd]"
		" ,[col_user_recordState]"
		" ,[col_user_operator]"
		" ,[col_user_operatoTime]"
		" ,[col_user_copyFromID]"
		" FROM [wx].[dbo].[userTBL]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);
}


//用户是否存在,存在返回true
bool CUser::IsBeingByName(std::string strName)
{
	bool bRtn = false;
	//存储过程参数 用户名
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(strName.c_str()));

	//执行
	int nCount = this->m_pDBCon->ExecStoredProc("user_IsBeing", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}

//创建新的用户ID
int CUser::CreateNewID()
{
	//存储过程参数 无
	std::vector<_variant_t> vecVarParam;

	//执行
	return this->m_pDBCon->ExecStoredProc("user_CreateNewID", vecVarParam, NULL).iVal;
}


//从数据库查找一条记录
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
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);
	if(memDataVec.size()<=0)
	{
		return false;
	}

	data = memDataVec.at(0);

	return true;
}


//是否允许登录,允许返回true
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
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBUserData>()(rec, memDataVec);

	//执行

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


//用户名相等返回true
bool  CUser::IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName)
{
	return dbUserData._loginName==strName;
}


//id相等返回true
bool CUser::IsIDDue(WXDB::DBUserData dbUserData, int nID)
{
	return dbUserData._id ==nID;
}



NAMESPACE_DB_END
