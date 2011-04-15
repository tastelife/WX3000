// DlgPower.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgPower.h"


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
}


BOOL CDlgPower::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"用户名", LVCFMT_LEFT,60));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"组名", LVCFMT_LEFT,100));
	m_listGroupCtl.SetColTitle(vecTitle);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

