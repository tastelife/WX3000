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
	_RecordsetPtr rec = this->m_pDBCon->ExecText("SELECT [col_dictionary_id]"
		"  ,[col_dictionary_type]"
		"  ,[col_dictionary_enum]"
		"  ,[col_dictionary_name]"
		"  ,[col_dictionary_manual]"
		"  ,[col_dictionary_recordState]"
		"  ,[col_dictionary_operator]"
		"  ,[col_dictionary_operatoTime]"
		"  ,[col_dictionary_recordCopyFrom]"
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

