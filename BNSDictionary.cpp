#include "StdAfx.h"
#include "BNSDictionary.h"

#include "StaticDB.h"
#include <functional>


NAMESPACE_BNS_BEGIN



CDictionary::CDictionary(void)
{
}

CDictionary::~CDictionary(void)
{
}


//获得所有数据保存在内存数据中
bool CDictionary::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Dictionary()->GetAllList(this->m_memDataVec);

	return true;
}


//获得指定类型的列表 枚举值、对应名称
CDictionary::LIST CDictionary::GetListByType(std::string strType)
{
	CDictionary::LIST list;

	for(auto it=m_memDataVec.begin(); it<m_memDataVec.end(); ++it)
	{
		if(it->_type==strType)
		{
			list[it->_enum] = it->_name;
		}
	}

	return std::move(list);
}

//通过枚举值获得名称
std::string CDictionary::GetName(std::string strType, int nEnum)
{
	WXDB::DBDictionaryData dictionaryData;
	if(this->m_memDataVec.Find(
		std::bind2nd(std::ptr_fun(WXDB::CDictionary::IsTypeEnumDue), std::pair<std::string,int>(strType, nEnum)), 
		dictionaryData))
	{
		return dictionaryData._name;
	}

	return "";
}
//通过枚举值设定名称
void CDictionary::SetName(std::string strType, int nEnum, std::string strName, 	
	std::string strManual, int nOperator)
{
	WXDB::DBDictionaryData data;
	data._type = strType;
	data._enum = nEnum;
	data._name = strName;
	data._operator = nOperator;

	DB::Dictionary()->Edit(data);
}

//通过枚举值获得 记录状态名
std::string CDictionary::GetRecordName(int nEnum)
{
	return this->GetName("recordState", nEnum);
}

//通过枚举值获得 性别名
std::string CDictionary::GetSexName(int nEnum)
{
	return this->GetName("sex", nEnum);
}


//通过枚举值获得 员工.职位名
std::string CDictionary::GetEmployeePositionName(int nEnum)
{
	return this->GetName("employee.position", nEnum);
}
//通过枚举值设定 员工.职位名
void  CDictionary::SetEmployeePositionName(int nEnum, std::string strName, int nOperator)
{
	SetName("employee.position", nEnum, strName, "", nOperator);
}

//通过枚举值获得 员工.在职状态 正式、临时、离职、休假
std::string CDictionary::GetEmployeePositionState(int nEnum)
{
	return this->GetName("employee.positionState", nEnum);
}


//获得性别的列表 枚举值、对应名称 
CDictionary::LIST CDictionary::GetListByTypeSex()
{
	return this->GetListByType("sex");
}

//获得职位状态的列表 枚举值、对应名称 
CDictionary::LIST CDictionary::GetListByTypePositionState()
{
	return this->GetListByType("employee.positionState");
}

//获得职位状态的列表 枚举值、对应名称 
CDictionary::LIST CDictionary::GetListByTypePosition()
{
	return this->GetListByType("employee.position");
}

NAMESPACE_BNS_END

