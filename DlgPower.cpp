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
END_MESSAGE_MAP()


// CDlgPower 消息处理程序
