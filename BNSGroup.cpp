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


//����������ݱ������ڴ�������
bool CGroup::RefrushAll()
{
	this->m_memDataVec.clear();

	DB::Group()->GetAllList(this->m_memDataVec);

	return true;
}



NAMESPACE_DB_END

