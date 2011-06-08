//WXBNSDataType.h
#pragma once


#include "WXCommMacroCode.h"
#include "WXCommFun.h"
#include "WXDbComm.h"
#include "WXBNSComm.h"


NAMESPACE_BNS_BEGIN


//员工对应数据
struct BNSEmployeeData
{
	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(BNSEmployeeData, 8);

	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _id, 0);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _companyBaseID, 1);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _name, 2);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _sex, 3);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(DATE, _birthday, 4);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _mobile, 5, "");
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(std::string, _phone, 6, "");
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _position, 7);
	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _positionState, 8);


	BNSEmployeeData()
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
	}
};


NAMESPACE_BNS_END
