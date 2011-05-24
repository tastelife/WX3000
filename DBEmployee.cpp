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

