#include "StdAfx.h"
#include "BNSGroup.h"

#include "StaticDB.h"


NAMESPACE_BNS_BEGIN



CGroup::CGroup(void)
{
}

CGroup::~CGroup(void)
{
}


//获得所有数据保存在内存数据中
bool CGroup::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Group()->GetAllList(this->m_memDataVec);

	return true;
}



NAMESPACE_DB_END

