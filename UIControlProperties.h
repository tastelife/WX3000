#pragma once

#include "WXUIComm.h"

#include <vector>

NAMESPACE_UI_BEGIN



struct ControlProperties
{
	//控件显示状态 隐藏、可用、不可用
	enum E_SHOWSTATE
	{
		E_SHOWSTATE_HIDE		= 1,
		E_SHOWSTATE_ENABLE		= 2,
		E_SHOWSTATE_DISBALIE	= 3,
	};
	
	//控件显示状态
	E_SHOWSTATE _showState;
	//控件ID
	int _id;
	//子控件
	std::vector<ControlProperties> constrolList;
};


NAMESPACE_UI_END

