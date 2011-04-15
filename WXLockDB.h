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
	//�û�����
	bool LockUser(std::string strUserName)
	{
		bool bRtn = true;

		//
		// ?????????? δʵ��
		//

		std::string strUser;

		if(!bRtn)
		{
			std::stringstream ss;
			ss <<  "[" << strUserName << "]���ڱ�[" << strUser << "ʹ����";
			AfxMessageBox(ss.str().c_str());
		}

		return bRtn;
	}
	//�û�����
	bool UnLockUser(std::string strUserName)
	{
		bool bRtn = true;

		//
		// ?????????? δʵ��
		//

		if(!bRtn)
		{
			std::stringstream ss;
			ss <<  "��[" << strUserName << "]�������ʧ�����ֶ����";
			AfxMessageBox(ss.str().c_str());
		}

		return bRtn;

	}
	//�û��Ƿ��Ѿ�������
	bool IsLockedUser(std::string strUserName)
	{

		//
		// ?????????? δʵ��
		//

		return true;
	}


private:
	//���������ݿ�����
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

