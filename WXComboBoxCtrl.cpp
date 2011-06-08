#include "StdAfx.h"
#include "WXComboBoxCtrl.h"


CWXComboBoxCtrl::CWXComboBoxCtrl(CComboBox* pList)
{
	m_pList = pList;
}


CWXComboBoxCtrl::~CWXComboBoxCtrl(void)
{
}

//ö�����ݼ�������������
void CWXComboBoxCtrl::EnumFillCmbBox(std::map<int, std::string>& enumList)
{

	std::map<int, std::string>::iterator it=enumList.begin();
	
	for( std::map<int, std::string>::size_type i=0;i<enumList.size(); ++it, ++i)
	{
		if(it->second!="")
		{
			m_pList->AddString(it->second.c_str());
			m_pList->SetItemData(i, it->first);
		}
	}
}
void CWXComboBoxCtrl::EnumFillCmbBox(std::map<int, std::string>&& enumList)
{
	EnumFillCmbBox(enumList);
}


//������Ĭ��ѡ�е�һ��
void CWXComboBoxCtrl::SelectFirstCmbBox()
{
	if(m_pList->GetCount()>0)
	{
		m_pList->SetCurSel(0);
	}
}
