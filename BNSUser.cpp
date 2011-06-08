#include "StdAfx.h"
#include "BNSUser.h"

#include "StaticDB.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN

CUser::CUser(void)
{
}

CUser::~CUser(void)
{
}


//生成数据
WXDB::DBUserData CUser::CreateData(std::string strName, std::string strPassWord, int nEmpID)
{
	WXDB::DBUserData data;
	data._loginName = strName;
	data._passwd = strPassWord;
	data._empId = nEmpID;
	//用户ID
	data._id = DB::User()->CreateNewID();
	
	//操作人
	data._operator = BNS::Login()->GetUserData()->_id;
	return std::move(data);
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
	if(!WXBNS::CWXLockDBSingle::Init()->LockUser(strName))
	{
		return false;
	}
	
	//用户不在数据库
	if(!this->IsBeingInDB(strName))
	{
		//添加到数据库
		WXDB::DBUserData data = CreateData(strName, strPassWord, nEmpID);
		bRtn = this->Add(data);
	}
	else
	{
		bRtn =false;
	}


	//解除锁定
	WXBNS::CWXLockDBSingle::Init()->UnLockUser(strName);

	return bRtn;
}
//添加一个用户
bool CUser::Add(WXDB::DBUserData& data)
{

	DB::User()->Add(data);

	return true;
}


//修改一个用户
bool CUser::Edit(int nID, std::string strPassWord, int nEmpID)
{
	bool bRtn = true;
	
	//内存中有该数据	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(WXDB::CUser::IsIDDue), nID), data))
	{
		return false;
	}

	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init()->LockUser(data._loginName))
	{
		return false;
	}

	//数据被更新
	if(IsChanged(nID, data))
	{
		//解除锁定
		WXBNS::CWXLockDBSingle::Init()->UnLockUser(data._loginName);
		return false;
	}

	//修改密码
	data._passwd = strPassWord;
	//修改关联
	data._empId = nEmpID;
	//操作人
	data._operator = BNS::Login()->GetUserData()->_id;
	
	//添加到数据库
	bRtn = this->Edit(data);
	
	//解除锁定
	WXBNS::CWXLockDBSingle::Init()->UnLockUser(data._loginName);

	return bRtn;
}
//修改一个用户
bool CUser::Edit(WXDB::DBUserData& data)
{
	DB::User()->Edit(data);

	return true;
}


//删除一个用户
bool CUser::Delete(int nID)
{	
	//内存中有该数据	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(WXDB::CUser::IsIDDue), nID), data))
	{
		return false;
	}

	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init()->LockUser(data._loginName))
	{
		return false;
	}

	//数据被更新
	if(IsChanged(nID, data))
	{
		//解除锁定
		WXBNS::CWXLockDBSingle::Init()->UnLockUser(data._loginName);
		return false;
	}
	
	//删除一个用户
	Delete(nID, BNS::Login()->GetUserData()->_id);

	//解除锁定
	WXBNS::CWXLockDBSingle::Init()->UnLockUser(data._loginName);

	return true;
}

//删除一个用户
bool CUser::Delete(int nID, int nOpertor)
{
	DB::User()->Delete(nID, nOpertor);

	return true;
}


//获得所有数据保存在内存数据中
bool CUser::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::User()->GetAllList(this->m_memDataVec);

	return true;
}

//获得一个用户名
bool CUser::FindUserName(int nID, std::string& strUserName)
{
	bool bRtn = false;

	WXDB::DBUserData data;
	if(GetInfo(nID, data))
	{
		strUserName = data._loginName;
		bRtn = true;
	}

	return bRtn;
}

//获得一个用户
bool CUser::GetInfo(int nID, WXDB::DBUserData& data)
{
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CUser::IsIDDue), nID), 
		data))
	{
		return true;
	}

	return false;
}

//用户是否可以被修改
bool CUser::IsPermitEdit(int nID)
{
	WXDB::DBUserData data;
	if(GetInfo(nID, data))
	{
		if(data._recordStat==WXDB::E_DICTIONARY_STATE_CREATE || data._recordStat==WXDB::E_DICTIONARY_STATE_EDIT)
		{
			return true;
		}
	}

	return false;
}

//用户是否关联了员工
bool CUser::IsRelevanceEmployee(int nID)
{
	WXDB::DBUserData data;
	if(GetInfo(nID, data))
	{
		if(data._empId>=0)
		{
			return true;
		}
	}

	return false;
}


//用户在内存
bool CUser::IsBeingInMem(std::string strName)
{
	CWXMemDataVector<WXDB::DBUserData> memDataVecFinded;
	//用户已存在刚返回 false
	if(this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(WXDB::CUser::IsUserNameDue), strName), memDataVecFinded)>0)
	{
		return true;
	}

	return false;
}

//用户在数据库
bool CUser::IsBeingInDB(std::string strName)
{
	if(DB::User()->IsBeingByName(strName))
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
	if(!DB::User()->Find(nID, lastData))
	{
		return true;
	}
	//相等视为未更新
	return !IsEqual(dbUserData, lastData);
}


//用户数据是否相等
bool CUser::IsEqual(const WXDB::DBUserData& dbUserDataFirst, const WXDB::DBUserData& dbUserDataSec) const
{
	//以下有一处不同,视为不相等
	if(dbUserDataFirst._empId!=dbUserDataSec._empId)
	{
		return false;
	}
	if(dbUserDataFirst._operator!=dbUserDataSec._operator)
	{
		return false;
	}
	if(dbUserDataFirst._operatorTime!=dbUserDataSec._operatorTime)
	{
		return false;
	}
	if(dbUserDataFirst._passwd!=dbUserDataSec._passwd)
	{
		return false;
	}
	if(dbUserDataFirst._recordStat!=dbUserDataSec._recordStat)
	{
		return false;
	}

	return true;
}



NAMESPACE_BNS_END

