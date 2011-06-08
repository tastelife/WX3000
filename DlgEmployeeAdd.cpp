// DlgEmployeeAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployeeAdd.h"
#include "afxdialogex.h"


// CDlgEmployeeAdd 对话框

IMPLEMENT_DYNAMIC(CDlgEmployeeAdd, CDialog)

CDlgEmployeeAdd::CDlgEmployeeAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEmployeeAdd::IDD, pParent)
	, m_nEmployeeID(0)
	, m_strEmployeeName(_T(""))
	, m_strEmployeeMobile(_T(""))
	, m_strEmployeePhone(_T(""))
{

}

CDlgEmployeeAdd::~CDlgEmployeeAdd()
{
}

void CDlgEmployeeAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nEmployeeID);
	DDX_Text(pDX, IDC_EDIT7, m_strEmployeeName);
	DDX_Text(pDX, IDC_EDIT13, m_strEmployeeMobile);
	DDX_Text(pDX, IDC_EDIT14, m_strEmployeePhone);
	DDX_Control(pDX, IDC_COMBO2, m_cmbEmployeeCompanyBase);
	DDX_Control(pDX, IDC_COMBO1, m_cmbEmployeePosition);
	DDX_Control(pDX, IDC_COMBO3, m_cmbEmployeePositionState);
	DDX_Control(pDX, IDC_COMBO4, m_cmbEmployeeSex);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_btnEmployeePicture);
}


BEGIN_MESSAGE_MAP(CDlgEmployeeAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgEmployeeAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlgEmployeeAdd::OnBnClickedButton10)
END_MESSAGE_MAP()


// CDlgEmployeeAdd 消息处理程序

//修改
void CDlgEmployeeAdd::OnBnClickedOk()
{
	CDialog::OnOK();
}

//新建
void CDlgEmployeeAdd::OnBnClickedButton10()
{
	CDialog::OnOK();
}
