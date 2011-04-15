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

//插入标题内容
void CWXListCtrl::InsertColumn(SWXLISTCTROLCOLUMN ctlCol, CListCtrl* listCtrl)
{	
	listCtrl->InsertColumn(ctlCol._nCol, ctlCol._strColumnHeading.c_str(), ctlCol._nFormat, ctlCol._nWidth, ctlCol._nSubItem);
}

//设定list列标题
void CWXListCtrl::SetColTitle(std::vector<SWXLISTCTROLCOLUMN>& vecTitle)
{
	LONG lStyle;
	//获取当前窗口style
	lStyle = GetWindowLong(m_pList->m_hWnd, GWL_STYLE);
	 //清除显示方式位
	lStyle &= ~LVS_TYPEMASK;
	 //设置style
	lStyle |= LVS_REPORT;
	//设置style
	SetWindowLong(m_pList->m_hWnd, GWL_STYLE, lStyle);

	DWORD dwStyle = m_pList->GetExtendedStyle();
	//选中某行使整行高亮（只适用与report风格的listctrl）
	dwStyle |= LVS_EX_FULLROWSELECT;
	//网格线（只适用与report风格的listctrl）
	dwStyle |= LVS_EX_GRIDLINES;

	//设置扩展风格
	m_pList->SetExtendedStyle(dwStyle); 

	std::for_each(vecTitle.begin(), vecTitle.end(), std::bind2nd(std::ptr_fun(InsertColumn), m_pList));
}


//添加一行数据
int CWXListCtrl::AddItems(std::vector<std::string>& vecItem, DWORD dwItemData)
{
	int nRtn = -1;

	//加在列表的最下面
	int nPos = m_pList->GetItemCount();

	nRtn = m_pList->InsertItem(nPos, vecItem.at(0).c_str());
	if(nRtn<0)
	{
		return -1;
	}

	//列数据
	for(unsigned int i=1; i<vecItem.size(); ++i)
	{
		//失败处理
		if(!m_pList->SetItemText(nRtn, i, vecItem.at(i).c_str()))
		{
			m_pList->DeleteItem(nRtn);
			return -1;
		}
	}

	//关联数据
	if(!m_pList->SetItemData(nRtn, dwItemData))
	{
		m_pList->DeleteItem(nRtn);
		return -1;
	}

	return nRtn;
}

//选择指定行，且可见
bool CWXListCtrl::Select(int nIndex)
{
    //选中
	if(!m_pList->SetItemState(nIndex, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED))
	{
		return false;
	}

	//使listctrl中一项可见，即滚动滚动条
	m_pList->EnsureVisible(nIndex, FALSE);

	return true;
}


//获得第一个选择行
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

