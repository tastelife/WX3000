#pragma once

#include "WXUIComm.h"

#include <vector>

NAMESPACE_UI_BEGIN


//控件的属性
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

	ControlProperties(E_SHOWSTATE showState)
	{
		_showState = showState;
	}
};

//设定控件的属性
template<class TCtrl>
class SetControlProperties
{
public:
	SetControlProperties(TCtrl& tCtrl, const ControlProperties& propertiies)
	{
		SetProperties(tCtrl, propertiies);
	}
	~SetControlProperties()
	{
	}

	void SetProperties(TCtrl& tCtrl, const ControlProperties& propertiies)
	{
		switch(propertiies._showState)
		{
		case ControlProperties::E_SHOWSTATE_HIDE:
			tCtrl.ShowWindow(SW_HIDE);
			break;
		case ControlProperties::E_SHOWSTATE_ENABLE:
			tCtrl.ShowWindow(SW_SHOW);
			tCtrl.EnableWindow(TRUE);
			break;
		case ControlProperties::E_SHOWSTATE_DISBALIE:
			tCtrl.ShowWindow(SW_SHOW);
			tCtrl.EnableWindow(FALSE);
			break;
		default:
			break;
		}
	}
};


NAMESPACE_UI_END

