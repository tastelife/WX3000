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
END_MESSAGE_MAP()


// CDlgPower ��Ϣ�������
