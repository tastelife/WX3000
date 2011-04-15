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


//���һ���û�
bool CUser::Add(std::string strName, std::string strPassWord, int nEmpID)
{
	bool bRtn = true;
	//�û����ڴ�
	if(this->IsBeingInMem(strName))
	{
		return false;
	}


	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(strName))
	{
		return false;
	}
	
	//�û��������ݿ�
	if(!this->IsBeingInDB(strName))
	{
		//��������	
		WXDB::DBUserData data;
		data._loginName = strName;
		data._passwd = strPassWord;
		data._empId = nEmpID;
		//�û�ID
		data._id = dbUser.CreateNewID();

		//��ӵ����ݿ�
		bRtn = this->Add(data);
	}
	else
	{
		bRtn =false;
	}


	//�������
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(strName);

	return bRtn;
}
//���һ���û�
bool CUser::Add(WXDB::DBUserData& data)
{

	dbUser.Add(data);

	return true;
}


//�޸�һ���û�
bool CUser::Edit(int nID, std::string strPassWord, int nEmpID)
{
	bool bRtn = true;
	
	//�ڴ����и�����	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsIDDue), nID), data))
	{
		return false;
	}

	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(data._loginName))
	{
		return false;
	}

	//���ݱ�����
	if(IsChanged(nID, data))
	{
		//�������
		WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);
		return false;
	}

	//�޸�����
	data._passwd = strPassWord;
	//�޸Ĺ���
	data._empId = nEmpID;
	
	//��ӵ����ݿ�
	bRtn = this->Edit(data);
	
	//�������
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);

	return bRtn;
}
//�޸�һ���û�
bool CUser::Edit(WXDB::DBUserData& data)
{
	dbUser.Edit(data);

	return true;
}


//ɾ��һ���û�
bool CUser::Delete(int nID)
{
	
	//�ڴ����и�����	
	WXDB::DBUserData data;
	if(!this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsIDDue), nID), data))
	{
		return false;
	}

	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(data._loginName))
	{
		return false;
	}

	//���ݱ�����
	if(IsChanged(nID, data))
	{
		//�������
		WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);
		return false;
	}

	//ɾ��һ���û�
	Delete(nID, 0);

	//�������
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(data._loginName);

	return true;
}

//ɾ��һ���û�
bool CUser::Delete(int nID, int nOpertor)
{
	dbUser.Delete(nID, nOpertor);

	return true;
}


//����������ݱ������ڴ�������
bool CUser::RefrushAll()
{
	this->m_memDataVec.clear();

	dbUser.GetAllList(this->m_memDataVec);

	return true;
}

//���һ���û�
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


//�û����ڴ�
bool CUser::IsBeingInMem(std::string strName)
{
	CWXMemDataVector<WXDB::DBUserData> memDataVecFinded;
	//�û��Ѵ��ڸշ��� false
	if(this->m_memDataVec.Find(std::bind2nd(std::ptr_fun(IsUserNameDue), strName), memDataVecFinded)>0)
	{
		return true;
	}

	return false;
}

//�û������ݿ�
bool CUser::IsBeingInDB(std::string strName)
{
	if(dbUser.IsBeingByName(strName))
	{
		return true;
	}

	return false;
}


//�����Ƿ񱻸��� true������
bool CUser::IsChanged(int nID, WXDB::DBUserData dbUserData)
{
	WXDB::DBUserData lastData;
	//δ�ҵ���Ϊ������
	if(!dbUser.Find(nID, lastData))
	{
		return true;
	}
	//������һ������,��Ϊ������
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


//�û�����ȷ���true
bool  CUser::IsUserNameDue(WXDB::DBUserData dbUserData, std::string strName)
{
	return dbUserData._loginName==strName;
}


//id��ȷ���true
bool CUser::IsIDDue(WXDB::DBUserData dbUserData, int nID)
{
	return dbUserData._id ==nID;
}


NAMESPACE_BNS_END

