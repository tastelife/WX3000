#pragma once

#include "WXUIComm.h"

#include <vector>

NAMESPACE_UI_BEGIN



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
};


NAMESPACE_UI_END

