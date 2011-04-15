// DlgPower.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wx.h"
#include "DlgPower.h"


// CDlgPower �Ի���

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


// CDlgPower ��Ϣ�������

void CDlgPower::OnBnClickedOk()
{
}


BOOL CDlgPower::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"�û���", LVCFMT_LEFT,60));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"����", LVCFMT_LEFT,100));
	m_listGroupCtl.SetColTitle(vecTitle);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

