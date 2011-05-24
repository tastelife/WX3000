// DlogUserAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlogUserAdd.h"

#include "DlgEmployee.h"

#include "StaticDB.h"


// CDlogUserAdd 对话框

IMPLEMENT_DYNAMIC(CDlogUserAdd, CDialog)

CDlogUserAdd::CDlogUserAdd( CWnd* pParent /*=NULL*/)
	: CDialog(CDlogUserAdd::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPw1(_T(""))
	, m_strPw2(_T(""))
	, m_nID(0)
	, m_strEmpName(_T(""))
	, m_nRelevanceEmpID(-1)
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
	DDX_Text(pDX, IDC_EDIT4, m_strEmpName);
}


BEGIN_MESSAGE_MAP(CDlogUserAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CDlogUserAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CDlogUserAdd::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlogUserAdd::OnBnClickedButton1)
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


		if(BNS::User()->IsRelevanceEmployee(this->m_nID))
		{
			this->GetDlgItem(IDC_BUTTON1)->ShowWindow(0);
		}
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
		m_nRelevanceEmpID))
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
		m_nRelevanceEmpID);

	this->OnOK();
}


void CDlogUserAdd::OnBnClickedButton1()
{
	CDlgEmployee empDlg(CDlgEmployee::E_START_TYPE_SELECTION);
	if(IDOK==empDlg.DoModal())
	{
		//显示员工名
		this->m_strEmpName = empDlg.m_empSelected._name.c_str();
		//员工号
		m_nRelevanceEmpID = empDlg.m_empSelected._id;

		UpdateData(FALSE);
	}
}
