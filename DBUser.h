#pragma once

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>

NAMESPACE_DB_BEGIN


class CUser
{
public:
	CUser(CWXDBConnect* m_pDBCon);
	virtual ~CUser(void);
private:
	CUser(void);

public:
	//添加一条记录
	void Add(DBUserData& data);

	//修改一条记录
	void Edit(DBUserData& data);

	//删除一条记录
	void Delete(int nID, int nOpretor);

	//从数据库查找一条记录
	bool Find(int nID, DBUserData& data);

	//获得列表
	void GetAllList(CWXMemDataVector<DBUserData>& memDataVec);

	//用户是否存在,存在返回true
	bool IsBeingByName(std::string strName);
	
	//是否允许登录,允许返回true
	bool IsLogin(std::string strName, std::string strPassWord, DBUserData* pData);

	//创建新的用户ID
	int CreateNewID();
	
	//用户名相等返回true
	static bool IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName);
	//id相等返回true
	static bool IsIDDue(WXDB::DBUserData dbUserData, int nID);

private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};

NAMESPACE_DB_END
