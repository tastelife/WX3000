#include "StdAfx.h"
#include "BNSEmployee.h"


#include "StaticDB.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN



CEmployee::CEmployee(void)
{
}

CEmployee::~CEmployee(void)
{
}


//生成数据
void CEmployee::CreateData(const BNSEmployeeData& bnsEmployeeData, WXDB::DBEmployeeData& dbEmpData) const
{
	CWXConver::BnsDbConver<BNSEmployeeData, 
		WXDB::DBEmployeeData,
		0,
		0,
		dbEmpData.E_VIA_MAX-WXDB::E_DB_DATA_COMMAND_ROW_COUNT+1>
		(bnsEmployeeData, dbEmpData);
	//操作人
	dbEmpData._operator = BNS::Login()->GetUserData()->_id;
}

//添加一个用户
bool CEmployee::Add(const BNSEmployeeData& data)
{
	bool bRtn = true;
	//用户在内存
	if(this->IsBeingInMem(data._id))
	{
		return false;
	}


	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init()->LockEmployee(data._id))
	{
		return false;
	}
	
	//用户不在数据库
	if(!this->IsBeingInDB(data._id))
	{
		//生成数据	
		WXDB::DBEmployeeData empData;
		CreateData(data, empData);

		//添加到数据库
		bRtn = this->Add(data);
	}
	else
	{
		bRtn =false;
	}


	//解除锁定
	WXBNS::CWXLockDBSingle::Init()->UnLockEmployee(data._id);

	return bRtn;
}
//修改一个用户
bool CEmployee::Edit(const BNSEmployeeData& data)
{
	return false;
}
//删除一个用户
bool CEmployee::Delete(int nID)
{
	return false;
}


//删除一个用户
bool CEmployee::Delete(int nID, int nOpertor)
{
	DB::Employee()->Delete(nID, nOpertor);

	return true;
}
//修改一个用户
bool CEmployee::Edit(WXDB::DBEmployeeData& data)
{
	DB::Employee()->Edit(data);

	return true;
}
//添加一个用户
bool CEmployee::Add(WXDB::DBEmployeeData& data)
{

	DB::Employee()->Add(data);

	return true;
}



//获得所有数据保存在内存数据中
bool CEmployee::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Employee()->GetAllList(this->m_memDataVec);

	return true;
}

//通过员工ID获得员工信息 基础
bool CEmployee::GetInfo(int nID, WXDB::DBEmployeeData &data)
{
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CEmployee::IsIDDue), nID), 
		data))
	{
		return true;
	}

	return false;
}

//通过员工ID获得员工信息 全部
bool CEmployee::GetInfo(int nID, BNSEmployeeData& bnsData)
{
	WXDB::DBEmployeeData dbData;
	if(GetInfo(nID, dbData))
	{
		CWXConver::BnsDbConver<WXDB::DBEmployeeData, BNSEmployeeData, 0, 0, WXDB::DBEmployeeData::E_VIA_MAX-4>(dbData, bnsData);
		return true;
	}

	return false;
}

//员工是否可以被修改
bool CEmployee::IsPermitEdit(int nID)
{
	WXDB::DBEmployeeData data;
	if(GetInfo(nID, data))
	{
		if(data._recordStat==WXDB::E_DICTIONARY_STATE_CREATE || data._recordStat==WXDB::E_DICTIONARY_STATE_EDIT)
		{
			return true;
		}
	}

	return false;
}


//员工在内存
bool CEmployee::IsBeingInMem(int nID)
{
	CWXMemDataVector<WXDB::DBEmployeeData> memDataVecFinded;
	//用户已存在刚返回 false
	if(this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(WXDB::CEmployee::IsIDDue), nID),
		memDataVecFinded)>0)
	{
		return true;
	}

	return false;
}


//用户在数据库
bool CEmployee::IsBeingInDB(int nID)
{
	if(DB::Employee()->IsBeingByID(nID))
	{
		return true;
	}

	return false;
}


NAMESPACE_BNS_END
