#include "StdAfx.h"
#include "WXListCtrl.h"

#include <algorithm>
#include <functional>


CWXListCtrl::CWXListCtrl()
{
}

CWXListCtrl::CWXListCtrl(CListCtrl* pList) : pMapItemData(NULL)
{
	m_pList = pList;
}

CWXListCtrl::~CWXListCtrl()
{
}

//�����������
void CWXListCtrl::InsertColumn(SWXLISTCTROLCOLUMN ctlCol, CListCtrl* listCtrl)
{	
	listCtrl->InsertColumn(ctlCol._nCol, ctlCol._strColumnHeading.c_str(), ctlCol._nFormat, ctlCol._nWidth, ctlCol._nSubItem);
}

//�趨list�б���
void CWXListCtrl::SetColTitle(std::vector<SWXLISTCTROLCOLUMN>& vecTitle)
{
	LONG lStyle;
	//��ȡ��ǰ����style
	lStyle = GetWindowLong(m_pList->m_hWnd, GWL_STYLE);
	 //�����ʾ��ʽλ
	lStyle &= ~LVS_TYPEMASK;
	 //����style
	lStyle |= LVS_REPORT;
	//����style
	SetWindowLong(m_pList->m_hWnd, GWL_STYLE, lStyle);

	DWORD dwStyle = m_pList->GetExtendedStyle();
	//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	dwStyle |= LVS_EX_FULLROWSELECT;
	//�����ߣ�ֻ������report����listctrl��
	dwStyle |= LVS_EX_GRIDLINES;

	//������չ���
	m_pList->SetExtendedStyle(dwStyle); 

	std::for_each(vecTitle.begin(), vecTitle.end(), std::bind2nd(std::ptr_fun(InsertColumn), m_pList));
}


//���һ������
int CWXListCtrl::AddItems(std::vector<std::string>& vecItem, DWORD dwItemData)
{
	int nRtn = -1;

	//�����б��������
	int nPos = m_pList->GetItemCount();

	nRtn = m_pList->InsertItem(nPos, vecItem.at(0).c_str());
	if(nRtn<0)
	{
		return -1;
	}

	//������
	for(unsigned int i=1; i<vecItem.size(); ++i)
	{
		//ʧ�ܴ���
		if(!m_pList->SetItemText(nRtn, i, vecItem.at(i).c_str()))
		{
			m_pList->DeleteItem(nRtn);
			return -1;
		}
	}

	//��������
	if(!m_pList->SetItemData(nRtn, dwItemData))
	{
		m_pList->DeleteItem(nRtn);
		return -1;
	}

	return nRtn;
}

//ѡ��ָ���У��ҿɼ�
bool CWXListCtrl::Select(int nIndex)
{
    //ѡ��
	if(!m_pList->SetItemState(nIndex, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED))
	{
		return false;
	}

	//ʹlistctrl��һ��ɼ���������������
	m_pList->EnsureVisible(nIndex, FALSE);

	return true;
}


//��õ�һ��ѡ����
int CWXListCtrl::GetFirstSelected()
{
	POSITION pos = m_pList->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		return -1;
	}
	else
	{
		return m_pList->GetNextSelectedItem(pos);
	}
}

