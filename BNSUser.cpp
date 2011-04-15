#include "StdAfx.h"
#include "BNSUser.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN

CUser::CUser(void) : dbUser(&db)
{
	db.SetSQLConcetText(("Provider=SQLOLEDB; Server=7BWZ82X_win7pro\\uboxc;Database=wx; uid=sa; pwd=U-BOXc1921#;"));
	if(!db.Open())
	{
		AfxMessageBox("open db error");
	}
}

CUser::~CUser(void)
{
	db.Close();
}


//添加一个用户
bool CUser::Add(std::string strName, std::string strPassWord, int nEmpID)
{
	bool bRtn = true;
	//用户在内存
	if(this->IsBeingInMem(strName))
	{
		return false;
	}


	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(strName))
	{
		return false;
	}
	
	//用户不在数据库
	if(!this->IsBeingInDB(strName))
	{
		//生成数据	
		WXDB::DBUserData data;
		data._loginName = strName;
		data._passwd = strPassWord;
		data._empId = nEmpID;
		//用户ID
		data._id = dbUser.CreateNewID();

		//添加到数据库
		bRtn = this->Add(data);
	}
	else
	{
		bRtn =false;
	}


	//解除锁定
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(strName);

	return bRtn;
}
//添加一个用户
bool CUser::Add(WXDB::DBUserData& data)
{

	dbUser.Add(data);

	return true;
}


//修改一个用户
bool CUser::Edit(int nID, std::string strPassWord, int nEmpID)
{
	bool bRtn = true;
	
	//内存中有该数据	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsIDDue), nID), data))
	{
		return false;
	}

	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(data._loginName))
	{
		return false;
	}

	//数据被更新
	if(IsChanged(nID, data))
	{
		//解除锁定
		WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);
		return false;
	}

	//修改密码
	data._passwd = strPassWord;
	//修改关联
	data._empId = nEmpID;
	
	//添加到数据库
	bRtn = this->Edit(data);
	
	//解除锁定
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);

	return bRtn;
}
//修改一个用户
bool CUser::Edit(WXDB::DBUserData& data)
{
	dbUser.Edit(data);

	return true;
}


//删除一个用户
bool CUser::Delete(int nID)
{
	
	//内存中有该数据	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsIDDue), nID), data))
	{
		return false;
	}

	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(data._loginName))
	{
		return false;
	}

	//数据被更新
	if(IsChanged(nID, data))
	{
		//解除锁定
		WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);
		return false;
	}

	//删除一个用户
	Delete(nID, 0);

	//解除锁定
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);

	return true;
}

//删除一个用户
bool CUser::Delete(int nID, int nOpertor)
{
	dbUser.Delete(nID, nOpertor);

	return true;
}


//获得所有数据保存在内存数据中
bool CUser::RefrushAll()
{
	this->m_memDataVec.clear();

	dbUser.GetAllList(this->m_memDataVec);

	return true;
}

//获得一个用户
bool CUser::FindUserName(int nID, std::string& strUserName)
{
	bool bRtn = false;

	WXDB::DBUserData data;
	if(bRtn = dbUser.Find(nID, data))
	{
		strUserName = data._loginName;
	}

	return bRtn;
}


//用户在内存
bool CUser::IsBeingInMem(std::string strName)
{
	CWXMemDataVector<WXDB::DBUserData> memDataVecFinded;
	//用户已存在刚返回 false
	if(this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsUserNameDue), strName), memDataVecFinded)>0)
	{
		return true;
	}

	return false;
}

//用户在数据库
bool CUser::IsBeingInDB(std::string strName)
{
	if(dbUser.IsBeingByName(strName))
	{
		return true;
	}

	return false;
}


//数据是否被更新 true被更新
bool CUser::IsChanged(int nID, WXDB::DBUserData dbUserData)
{
	WXDB::DBUserData lastData;
	//未找到视为被更新
	if(!dbUser.Find(nID, lastData))
	{
		return true;
	}
	//以下有一处更新,视为被更新
	if(dbUserData._empId!=lastData._empId)
	{
		return true;
	}
	if(dbUserData._operator!=lastData._operator)
	{
		return true;
	}
	if(dbUserData._operatorTime!=lastData._operatorTime)
	{
		return true;
	}
	if(dbUserData._passwd!=lastData._passwd)
	{
		return true;
	}
	if(dbUserData._recordStat!=lastData._recordStat)
	{
		return true;
	}

	return false;
}


//用户名相等返回true
bool  CUser::IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName)
{
	return dbUserData._loginName==strName;
}


//id相等返回true
bool CUser::IsIDDue(WXDB::DBUserData dbUserData, int nID)
{
	return dbUserData._id ==nID;
}


NAMESPACE_BNS_END

