// DlogUserAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlogUserAdd.h"



// CDlogUserAdd 对话框

IMPLEMENT_DYNAMIC(CDlogUserAdd, CDialog)

CDlogUserAdd::CDlogUserAdd(WXBNS::CUser* pBnsUser, CWnd* pParent /*=NULL*/)
	: CDialog(CDlogUserAdd::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPw1(_T(""))
	, m_strPw2(_T(""))
	, m_nID(0)
	, m_pBnsUser(pBnsUser)
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

void CDlogUserAdd::OnBnClickedOk()
{
	this->UpdateData(TRUE);

	m_pBnsUser->Add(this->m_strUserName.GetBuffer(0), 
		this->m_strPw1.GetBuffer(0),
		-1);

	this->OnOK();
}

void CDlogUserAdd::OnBnClickedOk2()
{
	
	this->UpdateData(TRUE);

	m_pBnsUser->Edit(this->m_nID, 
		this->m_strPw1.GetBuffer(0),
		-1);

	this->OnOK();
}
