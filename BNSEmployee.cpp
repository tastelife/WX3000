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

//ͨ��Ա��ID���Ա����Ϣ
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


NAMESPACE_BNS_END
