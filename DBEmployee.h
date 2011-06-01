#pragma once

#include "WXDbComm.h"
#include "WXMemDataVector.h"
#include "WXDbDataType.h"


NAMESPACE_DB_BEGIN



class CEmployee
{
public:
	CEmployee(CWXDBConnect* pDBCon);
	virtual ~CEmployee(void);
private:
	CEmployee(void);


public:
	//添加一条记录
	void Add(DBEmployeeData& data);

	//修改一条记录
	void Edit(DBEmployeeData& data);

	//删除一条记录
	void Delete(int nID, int nOpretor);

	//从数据库查找一条记录
	bool Find(int nID, DBEmployeeData& data);
	
	//员工是否存在,存在返回true
	bool IsBeingByID(int nID);

	//获得列表
	void GetAllList(CWXMemDataVector<DBEmployeeData>& memDataVec);

	//ID相等时返回true
	static bool IsIDDue(DBEmployeeData data, int nID);
private:
	//数据库句柄
	CWXDBConnect* m_pDBCon;
};




NAMESPACE_DB_END

