#pragma once

#include "sqlite3.h"
#include <string>

#pragma comment(lib, "sqlite3")

class CWXDBSqlite
{
public:
	CWXDBSqlite(std::string strDBName);
	virtual ~CWXDBSqlite(void);
	
	template<class Pred>
	inline bool GetAnyBlob(std::string strName, Pred _pred)
	{
		sqlite3_stmt * stat;
		std::string strSql = "select * from any where ID='";
		strSql += strName;
		strSql += "'";

		if(SQLITE_OK!=sqlite3_prepare( m_pdb,  strSql.c_str(), -1, &stat, 0 ))
		{
			return false;
		}
		int result = sqlite3_step( stat );
		if(result==SQLITE_DONE || result==SQLITE_ROW)
		{
			const unsigned char * pOther = sqlite3_column_text(stat, 2 );
			const void * pFileContent = sqlite3_column_blob( stat, 1 );
			int len = sqlite3_column_bytes( stat, 1 );

			_pred((const char *)pFileContent, len, pOther);

			sqlite3_finalize( stat );

			return true;
		}

		return false;
	}
	bool SetAnyBlob(std::string strName, char* pData, int nDataLen, std::string strOthe);

	bool Open();
	void Close();

	bool CreateAnyBlobTable();

private:
	std::string m_strDBName; 

	sqlite3 *m_pdb;
};
