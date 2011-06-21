#include "StdAfx.h"
#include "WXDBSqlite.h"


CWXDBSqlite::CWXDBSqlite(std::string strDBName) : m_strDBName(strDBName) , m_pdb(NULL)
{
}


CWXDBSqlite::~CWXDBSqlite(void)
{
}

bool CWXDBSqlite::SetAnyBlob(std::string strName, char* pData, int nDataLen, std::string strOther)
{
	sqlite3_stmt * stat;		
	std::string strSql = "insert into any( ID, image) values( '";
	strSql += strName;
	strSql += "', ?,";
	strSql += strOther;
	strSql += ") ";

	if(SQLITE_OK!=sqlite3_prepare( m_pdb, strSql.c_str() , -1, &stat, 0 ))
	{
		return false;
	}
	sqlite3_bind_blob( stat, 1, pData, nDataLen, NULL );
	int result = sqlite3_step( stat );
	sqlite3_finalize( stat );

	if(result==SQLITE_DONE || result==SQLITE_ROW)
	{
		return true;
	}
	return false;
}

bool CWXDBSqlite::Open()
{
	int  rc;  
	rc = sqlite3_open(m_strDBName.c_str() , &m_pdb);  
	if  (rc)  
	{  
		m_pdb = NULL;
		return false;
	}  
	return true;
}
void CWXDBSqlite::Close()
{
	sqlite3_close(m_pdb);  
	m_pdb = NULL;
}

bool CWXDBSqlite::CreateAnyBlobTable()
{	
	if(SQLITE_OK!=sqlite3_exec(m_pdb,"create table any( ID varchar(255) PRIMARY KEY, image  blob , othor varchar(255))",0,0,0))
	{
		return false;
	}

	return true;
}