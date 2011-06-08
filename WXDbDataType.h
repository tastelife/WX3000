//WXDbDataType.h
#pragma once


#include "WXCommMacroCode.h"
#include "WXCommFun.h"

#include "WXDbComm.h"

NAMESPACE_DB_BEGIN;
enum
{
	E_DB_DATA_COMMAND_ROW_COUNT = 4,
};
enum E_DICTIONARY_STATE
{
	E_DICTIONARY_STATE_CREATE							 = 1,
	E_DICTIONARY_STATE_DELETE							 = 2,
	E_DICTIONARY_STATE_EDIT								 = 3,
	E_DICTIONARY_STATE_CREATE_DELETE					 = 4,
	E_DICTIONARY_STATE_DELETE_DELETE					 = 5,
	E_DICTIONARY_STATE_EDIT_DELETE						 = 6,
};
enum E_DICTIONARY_LOGIN_STATE
{
	E_DICTIONARY_LOGIN_STATE_LOGIN						 = 1,
	E_DICTIONARY_LOGIN_STATE_LOGOUT						 = 2,
	E_DICTIONARY_LOGIN_STATE_LOGOUT_EXCEPTION			 = 3,
	E_DICTIONARY_LOGIN_STATE_LOGOUT_CLEAR				 = 4,
};

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



//组、功能点、权限视图对应数据
struct DBGroupFunPointPowerViewData
{
	
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBGroupFunPointPowerViewData, 3);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _groupID, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _funPointName, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _funPointDisplayName, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(Power, _groupFuncitonPointPower, 3);


	DBGroupFunPointPowerViewData()
	{
		_groupID = -1;
		_funPointName = "";
		_funPointDisplayName = "";
		_groupFuncitonPointPower._nPower = 0;
	}
	
	DBGroupFunPointPowerViewData(const DBGroupFunPointPowerViewData& data)
	{
		_groupID = data._groupID;
		_funPointName = data._funPointName;
		_funPointDisplayName = data._funPointDisplayName;
		_groupFuncitonPointPower._nPower = data._groupFuncitonPointPower._nPower;
	}
};


//字典对应数据
struct DBDictionaryData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBDictionaryData, 8);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _type, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _enum, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _name, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _manual, 4, "");

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 5);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 6);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 7);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 8);

	DBDictionaryData()
	{
		_id = -1;
		_type = "";
		_enum = -1;
		_name = "";
		_manual = "";
		
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};



//部门对应数据
struct DBCompanyBaseData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBCompanyBaseData, 10);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _companyName, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _higherAuthoritiesID, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _phone, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _header, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _cretateTime, 5);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _memo, 6, "");

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 7);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 8);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 9);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 10);

	DBCompanyBaseData()
	{
		_id = -1;
		_companyName = "";
		_higherAuthoritiesID = -1;
		_phone = "";
		_header = -1;
		_cretateTime = 0;
		_memo = "";
		
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};



//员工对应数据
struct DBEmployeeData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBEmployeeData, 12);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _companyBaseID, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _name, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _sex, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _birthday, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _mobile, 5, "");
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _phone, 6, "");
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _position, 7);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _positionState, 8);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(short, _recordStat, 9);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _operator, 10);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _operatorTime, 11);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _copyFromID, 12);

	DBEmployeeData()
	{
		_id = -1;
		_name = "";
		_companyBaseID = -1;
		_sex = -1;
		_birthday = 0;
		_mobile = "";
		_phone = "";
		_position = -1;
		_positionState = -1;
		
		_recordStat = 0;
		_operator = 0;
		_operatorTime = 0;
		_copyFromID = 0;
	}
};





NAMESPACE_DB_END


