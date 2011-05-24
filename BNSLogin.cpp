#include "StdAfx.h"
#include "BNSLogin.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN



CLogin::CLogin(void) : m_pUserData(NULL)
{
}

CLogin::~CLogin(void)
{
	Logout(); 
}


//��¼
bool CLogin::Login(std::string strName, std::string strPassWord)
{
	if(NULL==m_pUserData)
	{
		m_pUserData = new WXDB::DBUserData;
	}

	//�ж��û�������
	if(!DB::User()->IsLogin(strName, strPassWord, m_pUserData))
	{
		return false;
	}


	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init()->LockUser(strName))
	{
		return false;
	}


	//��������	
	m_loginData._id = DB::Login()->CreateNewID();
	m_loginData._userID = m_pUserData->_id;
	CWXFun::GetIPMacHostName(m_loginData._ip, m_loginData._mac, m_loginData._computerName);


	//�û��Ƿ��������ͻ��˵�¼
	if(this->IsLoging(m_loginData._userID))
	{
		if(6==AfxMessageBox("��������λ�õ�¼,ǿ�ƶԷ��˳���?", MB_YESNO))
		{
			//ǿ�������ͻ����˳�
			//
			// ?????
			//
		}
		else
		{
			return false;
		}
	}


	//�����쳣�˳�
	DB::Login()->Logout(m_loginData._userID, m_loginData._operator);

	bool bRtn = this->Login(m_loginData);

	//�������
	WXBNS::CWXLockDBSingle::Init()->UnLockUser(strName);

	return bRtn;
}
//��¼
bool CLogin::Login(WXDB::DBLoginData& loginData)
{
	DB::Login()->Login(loginData);

	return true;
}

//�ǳ�
bool CLogin::Logout()
{
	if(NULL==m_pUserData)
	{
		return true;
	}

	DB::Login()->Logout(m_loginData._id, m_loginData._state, m_loginData._operator);

	delete m_pUserData;
	m_pUserData = NULL;

	return true;
}


//��¼ID
int CLogin::GetLoginID()
{
	if(NULL==m_pUserData)
	{
		return -1;
	}

	return m_pUserData->_id;
}


//�û��Ƿ��ѵ�¼,���ڷ���true
bool CLogin::IsLoging(int nUserID)
{
	return DB::Login()->IsLoging(nUserID);
}

NAMESPACE_BNS_END
