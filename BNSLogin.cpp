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


//登录
bool CLogin::Login(std::string strName, std::string strPassWord)
{
	if(NULL==m_pUserData)
	{
		m_pUserData = new WXDB::DBUserData;
	}

	//判断用户名密码
	if(!DB::User()->IsLogin(strName, strPassWord, m_pUserData))
	{
		return false;
	}


	//锁定用户,失败则返回 false
	if(!WXBNS::CWXLockDBSingle::Init()->LockUser(strName))
	{
		return false;
	}


	//生成数据	
	m_loginData._id = DB::Login()->CreateNewID();
	m_loginData._userID = m_pUserData->_id;
	CWXFun::GetIPMacHostName(m_loginData._ip, m_loginData._mac, m_loginData._computerName);


	//用户是否在其它客户端登录
	if(this->IsLoging(m_loginData._userID))
	{
		if(6==AfxMessageBox("已在其它位置登录,强制对方退出吗?", MB_YESNO))
		{
			//强制其它客户端退出
			//
			// ?????
			//
		}
		else
		{
			return false;
		}
	}


	//清理异常退出
	DB::Login()->Logout(m_loginData._userID, m_loginData._operator);

	bool bRtn = this->Login(m_loginData);

	//解除锁定
	WXBNS::CWXLockDBSingle::Init()->UnLockUser(strName);

	return bRtn;
}
//登录
bool CLogin::Login(WXDB::DBLoginData& loginData)
{
	DB::Login()->Login(loginData);

	return true;
}

//登出
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


//登录ID
int CLogin::GetLoginID()
{
	if(NULL==m_pUserData)
	{
		return -1;
	}

	return m_pUserData->_id;
}


//用户是否已登录,存在返回true
bool CLogin::IsLoging(int nUserID)
{
	return DB::Login()->IsLoging(nUserID);
}

NAMESPACE_BNS_END
