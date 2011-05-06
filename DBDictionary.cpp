#include "StdAfx.h"
#include "DBDictionary.h"


NAMESPACE_DB_BEGIN



CDictionary::CDictionary(CWXDBConnect* pDBCon) : m_pDBCon(pDBCon)
{
}

CDictionary::CDictionary(void)
{
}

CDictionary::~CDictionary(void)
{
}


//获得列表
void CDictionary::GetAllList(CWXMemDataVector<DBDictionaryData>& memDataVec)
{
	//执行
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_powerEnum_id]"
		"  ,[col_powerEnum_type]"
		"  ,[col_powerEnum_enum]"
		"  ,[col_powerEnum_name]"
		"  ,[col_powerEnum_manual]"
		"  ,[col_powerEnum_recordState]"
		"  ,[col_powerEnum_operator]"
		"  ,[col_powerEnum_operatoTime]"
		"  ,[col_powerEnum_recordCopyFrom]"
		"  FROM [wx].[dbo].[dictionary ]");
	//转换成内存数据
	CWXRecordsetPtrToVecDBdata<DBDictionaryData>()(rec, memDataVec);
}




//类型、枚举值　相等返回true
bool  CDictionary::IsTypeEnumDue(WXDB::DBDictionaryData dbDictionaryData, std::pair<std::string, int> pairData)
{
	return (dbDictionaryData._enum==pairData.second)&&(dbDictionaryData._type==pairData.first);
}


NAMESPACE_DB_END

