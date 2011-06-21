//StaticDB.h

#pragma once

#include "WXCommConfigure.h"


#include "DBUser.h"
#include "DBLogin.h"
#include "DBPower.h"
#include "DBGroup.h"
#include "DBUserGroup.h"
#include "DBDictionary.h"
#include "DBEmployee.h"
#include "DBCompanyBase.h"



#include "BNSUser.h"
#include "BNSLogin.h"
#include "BNSPower.h"
#include "BNSGroup.h"
#include "BNSUserGroup.h"
#include "BNSDictionary.h"
#include "BNSEmployee.h"
#include "BNSCompanyBase.h"
#include "BNSImageSave.h"




class DB
{
public:
	static bool Init()
	{
		//db()->SetSQLConcetText(("Provider=SQLOLEDB; Server=7BWZ82X_win7pro\\uboxc;Database=wx; uid=sa; pwd=U-BOXc1921#;"));
		db()->SetSQLConcetText(("Provider=SQLOLEDB; server=(local)\\sqlexpress;database=wx;integrated security=sspi"));
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

	static WXDB::CPower* Power()
	{
		static WXDB::CPower dbPower(db());

		return  &dbPower;
	}
	

	static WXDB::CGroup* Group()
	{
		static WXDB::CGroup dbGroup(db());

		return  &dbGroup;
	}
	

	static WXDB::CUserGroup* UserGroup()
	{
		static WXDB::CUserGroup dbUserGroup(db());

		return  &dbUserGroup;
	}
	

	static WXDB::CDictionary* Dictionary()
	{
		static WXDB::CDictionary dbDictionary(db());

		return  &dbDictionary;
	}
	

	static WXDB::CEmployee* Employee()
	{
		static WXDB::CEmployee dbEmployee(db());

		return  &dbEmployee;
	}
	

	static WXDB::CCompanyBase* CompanyBase()
	{
		static WXDB::CCompanyBase dbCompanyBase(db());

		return  &dbCompanyBase;
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
	
	static WXBNS::CLogin* Login()
	{
		static WXBNS::CLogin bnsLogin;

		return &bnsLogin;
	}
	
	static WXBNS::CPower* Power()
	{
		static WXBNS::CPower bnsPower;

		return &bnsPower;
	}
	
	static WXBNS::CGroup* Group()
	{
		static WXBNS::CGroup bnsGroup;

		return &bnsGroup;
	}
	
	static WXBNS::CUserGroup* UserGroup()
	{
		static WXBNS::CUserGroup bnsUserGroup;

		return &bnsUserGroup;
	}
	
	static WXBNS::CDictionary* Dictionary()
	{
		static WXBNS::CDictionary bnsDictionary;

		return &bnsDictionary;
	}
	
	static WXBNS::CEmployee* Employee()
	{
		static WXBNS::CEmployee bnsEmployee;

		return &bnsEmployee;
	}
	
	static WXBNS::CCompanyBase* CompanyBase()
	{
		static WXBNS::CCompanyBase bnsCompanyBase;

		return &bnsCompanyBase;
	}
	
	static WXBNS::CImageSave* ImageSave()
	{
		static WXBNS::CImageSave imageSave;

		return &imageSave;
	}
};

class CMM
{
public:
	static CWXCommConfigure* Configure()
	{
		static CWXCommConfigure configure("config.xml");

		return &configure;
	}
};
