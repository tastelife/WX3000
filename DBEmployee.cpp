#include "StdAfx.h"
#include "DBEmployee.h"


NAMESPACE_DB_BEGIN


CEmployee::CEmployee(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CEmployee::CEmployee(void)
{
}

CEmployee::~CEmployee(void)
{
}

//添加一条记录
void CEmployee::Add(DBEmployeeData& data)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBEmployeeData>()(data, vecVarParam);

	//执行
	this->m_pDBCon->ExecStoredProc("employee_add", vecVarParam);
}

//修改一条记录
void CEmployee::Edit(DBEmployeeData& data)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBEmployeeData>()(data, vecVarParam);

	//执行
	this->m_pDBCon->ExecStoredProc("employee_edit", vecVarParam);
}

//删除一条记录
void CEmployee::Delete(int nID, int nOpretor)
{
	//存储过程参数
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nOpretor));

	//执行
	this->m_pDBCon->ExecStoredProc("employee_delete", vecVarParam);
}

//从数据库查找一条记录
bool CEmployee::Find(int nID, DBEmployeeData& data)
{
	//sql 
	std::string strSql;

	std::stringstream ss;
	ss << nID;
	ss >> strSql;
	strSql = "SELECT [col_employee_id]"
		" ,[col_companyBase_id]"
		" ,[col_employee_name]"
		" ,[col_employee_sex]"
		" ,[col_employee_birthday]"
		" ,[col_employee_mobile]"
		" ,[col_employee_phone]"
		" ,[col_employee_position]"
		" ,[col_employee_recordState]"
		" ,[col_employee_operator]"
		" ,[col_employee_operatoTime]"
		" ,[col_employee_recordCopyFrom]"
		" FROM [wx].[dbo].[employee]"
		" where col_employee_id = "
		+ strSql;

	CWXMemDataVector<DBEmployeeData> memDataVec;
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBEmployeeData>()(rec, memDataVec);
	if(memDataVec.size()<=0)
	{
		return false;
	}

	data = memDataVec.at(0);

	return true;
}


//员工是否存在,存在返回true
bool CEmployee::IsBeingByID(int nID)
{
	bool bRtn = false;
	//存储过程参数 员工ID
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));

	//执行
	int nCount = this->m_pDBCon->ExecStoredProc("employee_IsBeing", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}


//获得列表
void CEmployee::GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_employee_id]"
		" ,[col_companyBase_id]"
		" ,[col_employee_name]"
		" ,[col_employee_sex]"
		" ,[col_employee_birthday]"
		" ,[col_employee_mobile]"
		" ,[col_employee_phone]"
		" ,[col_employee_position]"
		" ,[col_employee_recordState]"
		" ,[col_employee_operator]"
		" ,[col_employee_operatoTime]"
		" ,[col_employee_recordCopyFrom]"
		" FROM [wx].[dbo].[employee]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBEmployeeData>()(rec, memDataVec);
}


//ID相等时返回true
bool CEmployee::IsIDDue(DBEmployeeData data, int nID)
{
	return data._id == nID;
}


NAMESPACE_DB_END

