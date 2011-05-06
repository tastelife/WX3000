// DlgLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgLogin.h"

#include "StaticDB.h"

// CDlgLogin 对话框

IMPLEMENT_DYNAMIC(CDlgLogin, CDialog)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPassWord(_T(""))
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strUserName);
	DDX_Text(pDX, IDC_EDIT7, m_strPassWord);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgLogin 消息处理程序

void CDlgLogin::OnBnClickedOk()
{
	UpdateData();

	if(BNS::Login()->Login(m_strUserName.GetBuffer(0), m_strPassWord.GetBuffer()))
	{
		OnOK();
	}
	else
	{
		MessageBox("登录失败");
	}
}
