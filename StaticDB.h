//StaticDB.h

#pragma once


#include "DBUser.h"
#include "DBLogin.h"
#include "BNSUser.h"


class DB
{
public:
	static bool Init()
	{
		db()->SetSQLConcetText(("Provider=SQLOLEDB; Server=7BWZ82X_win7pro\\uboxc;Database=wx; uid=sa; pwd=U-BOXc1921#;"));
		if(!db()->Open())
		{
			AfxMessageBox("open db error");

			return false;
		}

		return true;
	}

	static WXDB::CUser* User()
	{
		static WXDB::CUser dbUser(db());

		return  &dbUser;
	}

	static WXDB::CLogin* Login()
	{
		static WXDB::CLogin dbLogin(db());

		return  &dbLogin;
	}
	

	static bool UnInit()
	{
		return db()->Close();
	}
	
	//数据库连接	
	static CWXDBConnect* db()
	{
		static CWXDBConnect db;
		return &db;
	}
};

class BNS
{
public:
	static WXBNS::CUser* User()
	{
		static WXBNS::CUser bnsUser;

		return &bnsUser;
	}
};

