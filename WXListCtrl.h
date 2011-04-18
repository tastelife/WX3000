#pragma once

#include <vector>
#include <string>
#include <map>

struct SWXLISTCTROLCOLUMN
{
    int _nCol;
	std::string _strColumnHeading;
    int _nFormat;
    int _nWidth;
    int _nSubItem;


	SWXLISTCTROLCOLUMN(int nCol, std::string strColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1)
	{
		_nCol = nCol;
		_strColumnHeading = strColumnHeading;
		_nFormat = nFormat;
		_nWidth = nWidth;
		_nSubItem = nSubItem;
	}
};

class CWXListCtrl
{
public:
	CWXListCtrl(CListCtrl* pList);
	~CWXListCtrl();
private:
	CWXListCtrl();

public:
	//设定list列标题
	void SetColTitle(std::vector<SWXLISTCTROLCOLUMN>& vecTitle);
	//添加一行数据
	int AddItems(std::vector<std::string>& vecItem, DWORD dwItemData=0);
	//选择指定行，且可见
	bool Select(int nIndex);
	//获得第一个选择行
	int GetFirstSelected();
	//通过关联数据获得所在行的索引
	template<class _Pr>
	int GetIndexByData(_Pr pr);
	//添加关联数据
	template<class T>
	bool SetMapItemData(int nPos, T& tItemData);
	//获得关联数据
	template<class T>
	T GetMapItemData(int nPos);
public:
	//操作List
	CListCtrl* m_pList;
private:
	//插入标题内容
	static void InsertColumn(SWXLISTCTROLCOLUMN ctlCol, CListCtrl* listCtrl);
	//关联的数据
	void *pMapItemData;
};

//通过关联数据获得所在行的索引
template<class _Pr>
int CWXListCtrl::GetIndexByData(_Pr pr)
{
	int nRtn = -1;

	for(int i=0; i<m_pList->GetItemCount(); ++i)
	{
		if(pr(m_pList->GetItemData(i)))
		{
			nRtn = i;
			break;
		}
	}

	return nRtn;
}

//添加关联数据
template<class T>
bool CWXListCtrl::SetMapItemData(int nPos, T& tItemData)
{
	if(NULL==pMapItemData)
	{
		pMapItemData = new std::map<int, T>;
	}

	(*((std::map<int, T>*)pMapItemData))[nPos] = tItemData;

	return true;
}
//获得关联数据
template<class T>
T CWXListCtrl::GetMapItemData(int nPos)
{
	return (*((std::map<int, T>*)pMapItemData))[nPos];
}

	//std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	//vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"ID", LVCFMT_LEFT,60));
	//vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"NAME", LVCFMT_LEFT,100));
	//vecTitle.push_back(SWXLISTCTROLCOLUMN(2,"EmpName", LVCFMT_LEFT,150));
	//CWXListCtrl m_listCtrl(&this->m_list)
	//m_listCtrl.SetColTitle(vecTitle);

	//std::vector<std::string> vecItem;
	//vecItem.push_back("1");
	//vecItem.push_back("name 1");
	//vecItem.push_back("emp 1");
	//m_listCtrl.AddItems(vecItem, 1);

	//vecItem.clear();
	//vecItem.push_back("2");
	//vecItem.push_back("name 2");
	//vecItem.push_back("emp 2");
	//m_listCtrl.AddItems(vecItem);

	//vecItem.clear();
	//vecItem.push_back("3");
	//vecItem.push_back("name 3");
	//vecItem.push_back("emp 3");
	//m_listCtrl.AddItems(vecItem, 3);

	//int n = m_listCtrl.GetFirstSelected();
	//m_listCtrl.Select(1);
	//n = m_listCtrl.GetFirstSelected();

	//int nIndex = m_listCtrl.GetIndexByData(isDataDule);
	//m_listCtrl.Select(nIndex);

	//std::pair<int, int> pair(1, 1*10);
	//m_listCtrl.SetMapItemData<std::pair<int, int> >(1, pair);
	//
	//std::pair<int, int> pair = m_listCtrl.GetMapItemData<std::pair<int, int> >(1);