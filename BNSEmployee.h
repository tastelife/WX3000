#pragma once


#include "DBUser.h"
#include "WXBNSComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"
#include <string>
#include "WXBNSDataType.h"



NAMESPACE_BNS_BEGIN


class CEmployee
{
public:
	CEmployee(void);
	~CEmployee(void);

public:	
	//添加一个用户
	bool Add(const BNSEmployeeData& data);	
	//修改一个用户
	bool Edit(const BNSEmployeeData& data);
	//删除一个用户
	bool Delete(int nID);

	//获得所有数据保存在内存数据中
	bool RefrushAll();

	//通过员工ID获得员工信息 基础
	bool GetInfo(int nID, WXDB::DBEmployeeData &data);
	
	//通过员工ID获得员工信息 全部
	bool GetInfo(int nID, BNSEmployeeData& bnsData);
	
	//员工是否可以被修改
	bool IsPermitEdit(int nID);
	
private:
	//生成数据
	void CreateData(const BNSEmployeeData& bnsEmployeeData, WXDB::DBEmployeeData& dbEmpData) const;
	//添加一个用户
	bool Add(WXDB::DBEmployeeData& data);
	//修改一个用户
	bool Edit(WXDB::DBEmployeeData& data);
	//删除一个用户
	bool Delete(int nID, int nOpertor);

	//员工在内存
	bool CEmployee::IsBeingInMem(int nID);
	//用户在数据库
	bool IsBeingInDB(int nID);
public:
	//内存数据
	CWXMemDataVector<WXDB::DBEmployeeData> m_memDataVec;
};


NAMESPACE_BNS_END


