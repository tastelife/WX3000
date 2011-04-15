#include "StdAfx.h"
#include "BNSLogin.h"

#include "wxlockdb.h"
#include <sstream>
#include <functional>

NAMESPACE_BNS_BEGIN



CLogin::CLogin(void) : dbLogin(&db), dbUser(&db), m_pUserData(NULL)
{
	db.SetSQLConcetText(("Provider=SQLOLEDB; Server=7BWZ82X_win7pro\\uboxc;Database=wx; uid=sa; pwd=U-BOXc1921#;"));
	if(!db.Open())
	{
		AfxMessageBox("open db error");
	}
}

CLogin::~CLogin(void)
{
	Logout(); 

	db.Close();
}


//��¼
bool CLogin::Login(std::string strName, std::string strPassWord)
{
	if(NULL==m_pUserData)
	{
		m_pUserData = new WXDB::DBUserData;
	}

	//�ж��û�������
	if(!dbUser.IsLogin(strName, strPassWord, m_pUserData))
	{
		return false;
	}


	//�����û�,ʧ���򷵻� false
	if(!WXBNS::CWXLockDBSingle::Init(db)->LockUser(strName))
	{
		return false;
	}


	//��������	
	m_loginData._id = dbLogin.CreateNewID();
	m_loginData._userID = m_pUserData->_id;
	CFun::GetIPMacName(m_loginData._ip, m_loginData._mac, m_loginData._computerName);


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
	dbLogin.Logout(m_loginData._userID, m_loginData._operator);

	bool bRtn = this->Login(m_loginData);

	//�������
	WXBNS::CWXLockDBSingle::Init(db)->UnLockUser(strName);

	return bRtn;
}
//��¼
bool CLogin::Login(WXDB::DBLoginData& loginData)
{
	dbLogin.Login(loginData);

	return true;
}

//�ǳ�
bool CLogin::Logout()
{
	if(NULL==m_pUserData)
	{
		return true;
	}

	dbLogin.Logout(m_loginData._id, m_loginData._state, m_loginData._operator);

	delete m_pUserData;
	m_pUserData = NULL;

	return true;
}


//�û��Ƿ��ѵ�¼,���ڷ���true
bool CLogin::IsLoging(int nUserID)
{
	return dbLogin.IsLoging(nUserID);
}

NAMESPACE_BNS_END
