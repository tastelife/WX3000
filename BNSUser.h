#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>


NAMESPACE_BNS_BEGIN

class CUser
{
public:
	CUser(void);
	virtual ~CUser(void);

public:
	//添加一个用户
	bool Add(std::string strName, std::string strPassWord, int nEmpID);	
	//修改一个用户
	bool Edit(int nID, std::string strPassWord, int nEmpID);
	//删除一个用户
	bool Delete(int nID);
	//获得一个用户名
	bool FindUserName(int nID, std::string& strUserName);

	//获得所有数据保存在内存数据中
	bool RefrushAll();

private:
	//添加一个用户
	bool Add(WXDB::DBUserData& data);
	//修改一个用户
	bool Edit(WXDB::DBUserData& data);
	//删除一个用户
	bool Delete(int nID, int nOpertor);


private:
	//用户在内存
	bool IsBeingInMem(std::string strName);
	//用户在数据库
	bool IsBeingInDB(std::string strName);

	//数据是否被更新
	bool IsChanged(int nID, WXDB::DBUserData dbUserData);

public:
	//内存数据
	CWXMemDataVector<WXDB::DBUserData> m_memDataVec;
};

NAMESPACE_BNS_END