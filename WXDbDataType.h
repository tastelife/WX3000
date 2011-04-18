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



NAMESPACE_DB_END


