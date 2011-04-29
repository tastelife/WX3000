//WXDbDataType.h
#pragma once


#include "WXCommMacroCode.h"
#include "WXCommFun.h"

#include "WXDbComm.h"

NAMESPACE_DB_BEGIN

//用户表对应数据
struct DBUserData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBUserData, 7);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _loginName, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(int, _empId, 2, -1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _passwd, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 5);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 6);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 7);

	DBUserData()
	{
		_id = -1;
		_loginName = "";
		_empId = -1;
		_passwd = "";
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};



//登录表对应数据
struct DBLoginData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBLoginData, 10);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _userID, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _loginTime, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _state, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _computerName, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _mac, 5);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _ip, 6);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 7);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 8);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 9);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 10);

	DBLoginData()
	{
		_id = -1;
		_userID = -1;
		_loginTime=0;
		_state=0;
		_computerName = "";
		_mac = "";
		_ip = "";
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};


//用户组视图对应数据
struct DBUserGroupViewData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBUserGroupViewData, 4);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(int, _groupUserID, 0, -1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _userID, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(int, _groupID, 2, -1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _loginName, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _groupName, 4, "");

	DBUserGroupViewData()
	{
		_groupUserID = -1;
		_userID = -1;
		_groupID = -1;
		_loginName = "";
		_groupName = "";
	}
};



//组对应数据
struct DBGroupData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBGroupData, 5);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _name, 1);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 5);

	DBGroupData()
	{
		_id = -1;
		_name = "";
		
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};





//用户-组对应数据
struct DBUserGroupData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBUserGroupData, 6);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _groupID, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _userID, 2);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 5);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 6);

	DBUserGroupData()
	{
		_id = -1;
		_groupID = -1;
		_userID = -1;
		
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};


/*
struct Power
{
	int _nPower;

	bool GetCreatePower()
	{
		return (_nPower&0x01)!=0;
	}
	void SetCreatePower(bool bPower)
	{
		if(bPower)
		{
			_nPower = _nPower|0x01;
		}
		else
		{
			_nPower = _nPower&(~0x01);
		}
	}

	bool GetDeletePower()
	{
		return (_nPower&0x02)!=0;
	}
	void SetDeletePower(bool bPower)
	{
		if(bPower)
		{
			_nPower = _nPower|0x02;
		}
		else
		{
			_nPower = _nPower&(~0x02);
		}
	}

	bool GetEditPower()
	{
		return (_nPower&0x04)!=0;
	}
	void SetEditPower(bool bPower)
	{
		if(bPower)
		{
			_nPower = _nPower|0x04;
		}
		else
		{
			_nPower = _nPower&(~0x04);
		}
	}

	bool GetReadPower()
	{
		return (_nPower&0x08)!=0;
	}
	void SetReadPower(bool bPower)
	{
		if(bPower)
		{
			_nPower = _nPower|0x08;
		}
		else
		{
			_nPower = _nPower&(~0x08);
		}
	}

	Power()
	{
		_nPower = 0;
	}

	Power(int nPower)
	{
		_nPower = nPower;
	}

	Power(Power& power)
	{
		_nPower = power._nPower;
	}
};


//组、功能点、权限视图对应数据
struct DBGroupFunPointPowerViewData
{
	
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBGroupFunPointPowerViewData, 3);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _groupID, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _funPointName, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _funPointDisplayName, 2);
	//WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(Power, _groupFuncitonPointPower, 3);

	Power _groupFuncitonPointPower;
	template<>
		class SetClass<3>
		{
		public:
			void operator()(DBGroupFunPointPowerViewData* stru, const _variant_t& varData)
			{
				stru->_groupFuncitonPointPower = CWXGetVariantValue<Power>()(varData);
			}
		};
		
		template<>
		class GetClass<3>
		{
		public:
			_variant_t operator()(const DBGroupFunPointPowerViewData* stru)
			{
				return CWXSetVariantValue<Power>()(stru->_groupFuncitonPointPower);
			}
		};

	DBGroupFunPointPowerViewData()
	{
		_groupID = -1;
		_funPointName = "";
		_funPointDisplayName = "";
		//_groupFuncitonPointPower._nPower = 0;
	}
};

*/

NAMESPACE_DB_END


