// Dlg_User.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "Dlg_User.h"


#include "DlogUserAdd.h"


#include "StaticDB.h"

#include "WXListCtrl.h"
#include "WXDBConnect.h"
#include <algorithm>
#include <functional>



// CDlg_User 对话框

IMPLEMENT_DYNCREATE(CDlg_User, CDHtmlDialog)

CDlg_User::CDlg_User(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CDlg_User::IDD, CDlg_User::IDH, pParent),
	m_listCtrl(&m_list)
{
}

CDlg_User::~CDlg_User()
{
}

void CDlg_User::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
}


void CDlg_User::List(CListCtrl* pList)
{
	pList->DeleteAllItems();

	BNS::Dictionary()->RefrushAll();

	BNS::User()->RefrushAll();
	CWXMemDataVector<WXDB::DBUserData> vecData;
	vecData = BNS::User()->m_memDataVec;

	CString str;

	for(unsigned int i=0; i<vecData.size(); ++i)
	{
		WXDB::DBUserData data = vecData.at(i);


		std::vector<std::string> vecItem;

		str.Format(_T("%d"), data._id);
		vecItem.push_back(str.GetBuffer(0));

		vecItem.push_back(data._loginName);

		str.Format(_T("%d"), data._empId);
		vecItem.push_back(str.GetBuffer(0));

		vecItem.push_back(BNS::Dictionary()->GetRecordName(data._recordStat));

		m_listCtrl.AddItems(vecItem, data._id);

	}
	
	m_listCtrl.Select(0);
}

BOOL CDlg_User::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"ID", LVCFMT_LEFT,60));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"NAME", LVCFMT_LEFT,100));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(2,"EmpName", LVCFMT_LEFT,150));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(3,"record state", LVCFMT_LEFT,150));
	CWXListCtrl(&this->m_list).SetColTitle(vecTitle);

	
	List(&this->m_list);

	
	if(!BNS::Power()->GetUserPower(BNS::Login()->GetLoginID()).IsCreatePower())
	{
		this->GetDlgItem(IDOK)->ShowWindow(0);
	}

	if(!BNS::Power()->GetUserPower(BNS::Login()->GetLoginID()).IsEditPower())
	{
		this->GetDlgItem(IDOK2)->ShowWindow(0);
	}

	if(!BNS::Power()->GetUserPower(BNS::Login()->GetLoginID()).IsDeletePower())
	{
		this->GetDlgItem(IDC_BUTTON1)->ShowWindow(0);
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BEGIN_MESSAGE_MAP(CDlg_User, CDHtmlDialog)
	ON_BN_CLICKED(IDOK, &CDlg_User::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg_User::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK2, &CDlg_User::OnBnClickedOk2)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CDlg_User)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CDlg_User 消息处理程序

HRESULT CDlg_User::OnButtonOK(IHTMLElement* /*pElement*/)
{
	int index = m_listCtrl.GetFirstSelected();
	
	std::pair<int, int> pair = m_listCtrl.GetMapItemData<std::pair<int, int> >(index);

	CString str;
	str.Format(_T("%d   %d"), pair.first, pair.second);

	AfxMessageBox(str);

	return S_OK;

	OnOK();
	return S_OK;
}

HRESULT CDlg_User::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}




void CDlg_User::OnBnClickedOk()
{
	CDlogUserAdd dlgUserAdd;

	int index = m_listCtrl.GetFirstSelected();
	if(index>=0)
	{
		dlgUserAdd.m_nID = -1;
	}

	dlgUserAdd.DoModal();

	
	List(&this->m_list);
}

void CDlg_User::OnBnClickedButton1()
{	
	BNS::User()->Delete(m_list.GetItemData(m_listCtrl.GetFirstSelected()));
	List(&this->m_list);
}

void CDlg_User::OnBnClickedOk2()
{
	CDlogUserAdd dlgUserAdd;

	int index = m_listCtrl.GetFirstSelected();
	if(index>=0)
	{
		dlgUserAdd.m_nID = m_list.GetItemData(index);
		std::string strName;
		BNS::User()->FindUserName(dlgUserAdd.m_nID, strName);
		dlgUserAdd.m_strUserName = strName.c_str();
	}

	dlgUserAdd.DoModal();

	
	List(&this->m_list);
}
