#pragma once

#include "UIControlProperties.h"

#include "WXUIComm.h"

NAMESPACE_UI_BEGIN

	
template<bool isCreate>
class CEmployeeAdd;

template<>
class CEmployeeAdd<true>
{
public:
	CEmployeeAdd(void)
	{
	}
	virtual ~CEmployeeAdd(void)
	{
	}
};


template<>
class CEmployeeAdd<false>
{
public:
	CEmployeeAdd(void)
	{
	}
	virtual ~CEmployeeAdd(void)
	{
	}

	//���Ա��������������
	ControlProperties GetEmployeeIDProterty()
	{
		WXUI::ControlProperties ctrlProperty(WXUI::ControlProperties::E_SHOWSTATE_ENABLE);
		return ctrlProperty;
	}
};




NAMESPACE_UI_END

