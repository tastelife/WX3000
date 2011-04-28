// DlogMain.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlogMain.h"

#include "StaticDB.h"
#include "MainFrm.h"
#include "Dlg_User.h"
#include "DlgLogin.h"
#include "DlgPower.h"

// CDlogMain 对话框

IMPLEMENT_DYNAMIC(CDlogMain, CDialog)

CDlogMain::CDlogMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlogMain::IDD, pParent)
{

}

CDlogMain::~CDlogMain()
{
}

void CDlogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlogMain, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlogMain::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlogMain::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlogMain::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CDlogMain::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlogMain::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlogMain::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlogMain::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDlogMain 消息处理程序

void CDlogMain::OnBnClickedButton1()
{
	try
	{ 
		CDlgLogin login;
		if(IDOK==login.DoModal())
		{
			this->GetDlgItem(IDC_BUTTON1)->EnableWindow(0);
			this->GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
			this->GetDlgItem(IDC_BUTTON3)->EnableWindow(1);
			this->GetDlgItem(IDC_BUTTON4)->EnableWindow(1);
			this->GetDlgItem(IDC_BUTTON5)->EnableWindow(1);
			this->GetDlgItem(IDC_BUTTON6)->EnableWindow(1);
		}
		else
		{			
			MessageBox("登录失败");
		}
	}
	catch(_com_error   e)
	{ 
		MessageBox(e.ErrorMessage());
	}
}

void CDlogMain::OnBnClickedButton2()
{
	CDlg_User user;
	user.DoModal();
}

void CDlogMain::OnBnClickedButton3()
{
	CDlgPower dlgPower;
	dlgPower.DoModal();
}

void CDlogMain::OnBnClickedOk()
{
}

void CDlogMain::OnBnClickedButton4()
{
}

void CDlogMain::OnBnClickedButton5()
{
}

void CDlogMain::OnBnClickedButton6()
{
}
