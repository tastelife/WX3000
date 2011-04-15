//wxlockdb.h
#pragma once

#include "StaticDB.h"
#include "WXDBConnect.h"
#include <string>
#include <sstream>

NAMESPACE_BNS_BEGIN


class CWXLockDB
{
public:
	CWXLockDB(CWXDBConnect& db) : m_db(&db)
	{
	}

	virtual ~CWXLockDB(void)
	{
	}

public:
	//用户锁定
	bool LockUser(std::string strUserName)
	{
		bool bRtn = true;

		//
		// ?????????? 未实现
		//

		std::string strUser;

		if(!bRtn)
		{
			std::stringstream ss;
			ss <<  "[" << strUserName << "]正在被[" << strUser << "使用中";
			AfxMessageBox(ss.str().c_str());
		}

		return bRtn;
	}
	//用户解锁
	bool UnLockUser(std::string strUserName)
	{
		bool bRtn = true;

		//
		// ?????????? 未实现
		//

		if(!bRtn)
		{
			std::stringstream ss;
			ss <<  "对[" << strUserName << "]解除锁定失败请手动解除";
			AfxMessageBox(ss.str().c_str());
		}

		return bRtn;

	}
	//用户是否已经被锁定
	bool IsLockedUser(std::string strUserName)
	{

		//
		// ?????????? 未实现
		//

		return true;
	}


private:
	//上锁用数据库连接
	CWXDBConnect* m_db;
};

class CWXLockDBSingle
{
public :
	
	static CWXLockDB* Init(CWXDBConnect& db=*DB::db())
	{
		static CWXLockDB lockDB(db);
		return &lockDB;
	}
};



NAMESPACE_BNS_END

