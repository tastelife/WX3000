// DlgPowerEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgPowerEdit.h"

#include "StaticDB.h"


// CDlgPowerEdit 对话框

IMPLEMENT_DYNAMIC(CDlgPowerEdit, CDialog)

CDlgPowerEdit::CDlgPowerEdit(int nUserID, int nGroupID, int nUserGroupID, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPowerEdit::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strGroupName(_T(""))
	, m_nUserID(nUserID)
	, m_nGroupID(nGroupID)
	, m_nUserGroupID(nUserGroupID)
{

}

CDlgPowerEdit::~CDlgPowerEdit()
{
}

void CDlgPowerEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strUserName);
	DDX_CBString(pDX, IDC_COMBO1, m_strGroupName);
	DDX_Control(pDX, IDC_COMBO1, m_cmbGroup);
}


BEGIN_MESSAGE_MAP(CDlgPowerEdit, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPowerEdit::OnBnClickedOk)
END_MESSAGE_MAP()



BOOL CDlgPowerEdit::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::string strUserName;
	if(BNS::User()->FindUserName(m_nUserID, strUserName))
	{
		m_strUserName = strUserName.c_str();
		UpdateData(0);
	}

	List();

	SeclecByItemData(m_nGroupID);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


// CDlgPowerEdit 消息处理程序

void CDlgPowerEdit::OnBnClickedOk()
{
	if(m_cmbGroup.GetCurSel()<0)
	{
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
	if(BNS::UserGroup()->SetUserGroupByUserID(
		m_nUserID, 
		m_cmbGroup.GetItemData(m_cmbGroup.GetCurSel())
		))
	{
		OnOK();
	}
	else
	{
		MessageBox("设定组失败");
	}
}

void CDlgPowerEdit::List()
{
	BNS::Group()->RefrushAll();
	CWXMemDataVector<WXDB::DBGroupData> vecData;
	vecData = BNS::Group()->m_memDataVec;

	CString str;

	for(unsigned int i=0; i<vecData.size(); ++i)
	{
		WXDB::DBGroupData data = vecData.at(i);

		m_cmbGroup.AddString(data._name.c_str());
		m_cmbGroup.SetItemData(i, data._id);
	}

}

int CDlgPowerEdit::SeclecByItemData(int nData)
{
	for(int i=0; i<m_cmbGroup.GetCount(); i++)
	{
		if(m_cmbGroup.GetItemData(i)==(DWORD)nData)
		{
			return m_cmbGroup.SetCurSel(i);
		}
	}

	return -1;
}


