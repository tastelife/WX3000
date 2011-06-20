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


//��������
void CEmployee::CreateData(const BNSEmployeeData& bnsEmployeeData, WXDB::DBEmployeeData& dbEmpData) const
{
	CWXConver::BnsDbConver<BNSEmployeeData, 
		WXDB::DBEmployeeData,
		0,
		0,
		dbEmpData.E_VIA_MAX-WXDB::E_DB_DATA_COMMAND_ROW_COUNT+1>
		(bnsEmployeeData, dbEmpData);
	//������
	dbEmpData._operator = BNS::Login()->GetUserData()->_id;
}

//���һ���û�
bool CEmployee::Add(const BNSEmployeeData& data)
{
	bool bRtn = true;
	//�û����ڴ�
	if(this->IsBeingInMem(data._id))
	{
		return false;
	}


	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init()->LockEmployee(data._id))
	{
		return false;
	}
	
	//�û��������ݿ�
	if(!this->IsBeingInDB(data._id))
	{
		//��������	
		WXDB::DBEmployeeData empData;
		CreateData(data, empData);

		//��ӵ����ݿ�
		bRtn = this->Add(data);
	}
	else
	{
		bRtn =false;
	}


	//�������
	WXBNS::CWXLockDBSingle::Init()->UnLockEmployee(data._id);

	return bRtn;
}
//�޸�һ���û�
bool CEmployee::Edit(const BNSEmployeeData& data)
{
	return false;
}
//ɾ��һ���û�
bool CEmployee::Delete(int nID)
{
	return false;
}


//ɾ��һ���û�
bool CEmployee::Delete(int nID, int nOpertor)
{
	DB::Employee()->Delete(nID, nOpertor);

	return true;
}
//�޸�һ���û�
bool CEmployee::Edit(WXDB::DBEmployeeData& data)
{
	DB::Employee()->Edit(data);

	return true;
}
//���һ���û�
bool CEmployee::Add(WXDB::DBEmployeeData& data)
{

	DB::Employee()->Add(data);

	return true;
}



//����������ݱ������ڴ�������
bool CEmployee::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Employee()->GetAllList(this->m_memDataVec);

	return true;
}

//ͨ��Ա��ID���Ա����Ϣ ����
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

//ͨ��Ա��ID���Ա����Ϣ ȫ��
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

//Ա���Ƿ���Ա��޸�
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


//Ա�����ڴ�
bool CEmployee::IsBeingInMem(int nID)
{
	CWXMemDataVector<WXDB::DBEmployeeData> memDataVecFinded;
	//�û��Ѵ��ڸշ��� false
	if(this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(WXDB::CEmployee::IsIDDue), nID),
		memDataVecFinded)>0)
	{
		return true;
	}

	return false;
}


//�û������ݿ�
bool CEmployee::IsBeingInDB(int nID)
{
	if(DB::Employee()->IsBeingByID(nID))
	{
		return true;
	}

	return false;
}


NAMESPACE_BNS_END
