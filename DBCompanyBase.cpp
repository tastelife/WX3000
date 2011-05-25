#include "StdAfx.h"
#include "DBCompanyBase.h"



NAMESPACE_DB_BEGIN
	


CCompanyBase::CCompanyBase(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}


CCompanyBase::CCompanyBase(void)
{
}


CCompanyBase::~CCompanyBase(void)
{
}

//����б�
void CCompanyBase::GetAllList(CWXMemDataVector<DBCompanyBaseData>& memDataVec)
{
	//ִ��
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_companyBase_id]"
		" ,[col_companyBase_companyName]"
		" ,[col_companyBase_higherAuthoritiesID]"
		" ,[col_companyBase_phone]"
		" ,[col_companyBase_header]"
		" ,[col_companyBase_cretateTime]"
		" ,[col_companyBase_memo]"
		" ,[col_companyBase_recordState]"
		" ,[col_companyBase_operator]"
		" ,[col_companyBase_operatoTime]"
		" ,[col_companyBase_recordCopyFrom]"
		" FROM [wx].[dbo].[companyBase]");
	//ת�����ڴ�����
	CWXRecordsetPtrToVecDBdata<DBCompanyBaseData>()(rec, memDataVec);
}

//ID���ʱ����true
bool CCompanyBase::IsIDDue(DBCompanyBaseData data, int nID)
{
	return data._id == nID;
}

NAMESPACE_DB_END
