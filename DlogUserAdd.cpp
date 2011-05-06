// DlogUserAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlogUserAdd.h"
#include "StaticDB.h"


// CDlogUserAdd 对话框

IMPLEMENT_DYNAMIC(CDlogUserAdd, CDialog)

CDlogUserAdd::CDlogUserAdd( CWnd* pParent /*=NULL*/)
	: CDialog(CDlogUserAdd::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPw1(_T(""))
	, m_strPw2(_T(""))
	, m_nID(0)
{

}

CDlogUserAdd::~CDlogUserAdd()
{
}

void CDlogUserAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_strUserName);
	DDX_Text(pDX, IDC_EDIT5, m_strPw1);
	DDX_Text(pDX, IDC_EDIT6, m_strPw2);
	DDX_Text(pDX, IDC_EDIT2, m_nID);
}


BEGIN_MESSAGE_MAP(CDlogUserAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CDlogUserAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CDlogUserAdd::OnBnClickedOk2)
END_MESSAGE_MAP()


// CDlogUserAdd 消息处理程序


BOOL CDlogUserAdd::OnInitDialog()
{
	CDialog::OnInitDialog();


	if(-1==this->m_nID)
	{
		this->GetDlgItem(IDOK2)->ShowWindow(0);
	}
	else
	{
		this->GetDlgItem(IDOK)->ShowWindow(0);
		((CEdit*)this->GetDlgItem(IDC_EDIT3))->SetReadOnly(TRUE);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CDlogUserAdd::OnBnClickedOk()
{
	this->UpdateData(TRUE);
	if(this->m_strPw1 != this->m_strPw2)
	{
		MessageBox("密码不一致");
		return;
	}

	if(!BNS::User()->Add(this->m_strUserName.GetBuffer(0), 
		this->m_strPw1.GetBuffer(0),
		-1))
	{
		MessageBox("用户已存在");
		return;
	}

	this->OnOK();
}

void CDlogUserAdd::OnBnClickedOk2()
{	
	this->UpdateData(TRUE);
	if(this->m_strPw1 != this->m_strPw2)
	{
		MessageBox("密码不一致");
		return;
	}

	BNS::User()->Edit(this->m_nID, 
		this->m_strPw1.GetBuffer(0),
		-1);

	this->OnOK();
}
