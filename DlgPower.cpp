// DlgPower.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgPower.h"
#include "StaticDB.h"
#include "DlgPowerEdit.h"


// CDlgPower 对话框

IMPLEMENT_DYNAMIC(CDlgPower, CDialog)

CDlgPower::CDlgPower(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPower::IDD, pParent)
	, m_listGroupCtl(&m_listGroup)
{

}

CDlgPower::~CDlgPower()
{
}

void CDlgPower::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listGroup);
}


BEGIN_MESSAGE_MAP(CDlgPower, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPower::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPower 消息处理程序

void CDlgPower::OnBnClickedOk()
{
	int nIndex =m_listGroupCtl.GetFirstSelected();
	if(nIndex<=-1)
	{
		return;
	}

	std::pair<int, int> intPair = m_listGroupCtl.GetMapItemData<std::pair<int, int> >(nIndex);

	CDlgPowerEdit edit(m_listGroupCtl.m_pList->GetItemData(nIndex), intPair.first, intPair.second);

	if(IDOK==edit.DoModal())
	{
		List(&m_listGroup);
	}
}


BOOL CDlgPower::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"用户名", LVCFMT_LEFT,100));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"组名", LVCFMT_LEFT,160));
	m_listGroupCtl.SetColTitle(vecTitle);

	List(&m_listGroup);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CDlgPower::List(CListCtrl* pList)
{
	pList->DeleteAllItems();

	BNS::Power()->RefrushAll();
	CWXMemDataVector<WXDB::DBUserGroupViewData> vecData;
	vecData = BNS::Power()->m_memDataVecUserGroupView;

	CString str;

	for(unsigned int i=0; i<vecData.size(); ++i)
	{
		WXDB::DBUserGroupViewData data = vecData.at(i);


		std::vector<std::string> vecItem;

		vecItem.push_back(data._loginName);

		vecItem.push_back(data._groupName);

		m_listGroupCtl.AddItems(vecItem, data._userID);
		m_listGroupCtl.SetMapItemData(i, std::pair<int, int>(data._groupID, data._groupUserID));
	}

}


