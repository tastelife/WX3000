#pragma once

#include "WXUIComm.h"

#include <vector>

NAMESPACE_UI_BEGIN


//�ؼ�������
struct ControlProperties
{
	//�ؼ���ʾ״̬ ���ء����á�������
	enum E_SHOWSTATE
	{
		E_SHOWSTATE_HIDE		= 1,
		E_SHOWSTATE_ENABLE		= 2,
		E_SHOWSTATE_DISBALIE	= 3,
	};
	
	//�ؼ���ʾ״̬
	E_SHOWSTATE _showState;
	//�ؼ�ID
	int _id;
	//�ӿؼ�
	std::vector<ControlProperties> constrolList;

	ControlProperties(E_SHOWSTATE showState)
	{
		_showState = showState;
	}
};

//�趨�ؼ�������
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

