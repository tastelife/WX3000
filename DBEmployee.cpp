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

//���һ����¼
void CEmployee::Add(DBEmployeeData& data)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBEmployeeData>()(data, vecVarParam);

	//ִ��
	this->m_pDBCon->ExecStoredProc("employee_add", vecVarParam);
}

//�޸�һ����¼
void CEmployee::Edit(DBEmployeeData& data)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	CWXDBdataToVecVar<DBEmployeeData>()(data, vecVarParam);

	//ִ��
	this->m_pDBCon->ExecStoredProc("employee_edit", vecVarParam);
}

//ɾ��һ����¼
void CEmployee::Delete(int nID, int nOpretor)
{
	//�洢���̲���
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));
	vecVarParam.push_back(_variant_t(nOpretor));

	//ִ��
	this->m_pDBCon->ExecStoredProc("employee_delete", vecVarParam);
}

//�����ݿ����һ����¼
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
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText(strSql);
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBEmployeeData>()(rec, memDataVec);
	if(memDataVec.size()<=0)
	{
		return false;
	}

	data = memDataVec.at(0);

	return true;
}


//Ա���Ƿ����,���ڷ���true
bool CEmployee::IsBeingByID(int nID)
{
	bool bRtn = false;
	//�洢���̲��� Ա��ID
	std::vector<_variant_t> vecVarParam;
	vecVarParam.push_back(_variant_t(nID));

	//ִ��
	int nCount = this->m_pDBCon->ExecStoredProc("employee_IsBeing", vecVarParam, NULL).lVal;

	if(nCount>0)
	{
		bRtn = true;
	}

	return bRtn;
}


//����б�
void CEmployee::GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec)
{
	//ִ��
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
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBEmployeeData>()(rec, memDataVec);
}


//ID���ʱ����true
bool CEmployee::IsIDDue(DBEmployeeData data, int nID)
{
	return data._id == nID;
}


NAMESPACE_DB_END

