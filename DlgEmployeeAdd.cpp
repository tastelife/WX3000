// DlgEmployeeAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployeeAdd.h"
#include "afxdialogex.h"


// CDlgEmployeeAdd �Ի���

IMPLEMENT_DYNAMIC(CDlgEmployeeAdd, CDialog)

CDlgEmployeeAdd::CDlgEmployeeAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEmployeeAdd::IDD, pParent)
{

}

CDlgEmployeeAdd::~CDlgEmployeeAdd()
{
}

void CDlgEmployeeAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgEmployeeAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgEmployeeAdd::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgEmployeeAdd ��Ϣ�������


void CDlgEmployeeAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
