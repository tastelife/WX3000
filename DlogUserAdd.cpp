// DlogUserAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wx.h"
#include "DlogUserAdd.h"

#include "DlgEmployee.h"

#include "StaticDB.h"


// CDlogUserAdd �Ի���

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


// CDlogUserAdd ��Ϣ�������


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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CDlogUserAdd::OnBnClickedOk()
{
	this->UpdateData(TRUE);
	if(this->m_strPw1 != this->m_strPw2)
	{
		MessageBox("���벻һ��");
		return;
	}

	if(!BNS::User()->Add(this->m_strUserName.GetBuffer(0), 
		this->m_strPw1.GetBuffer(0),
		m_nRelevanceEmpID))
	{
		MessageBox("�û��Ѵ���");
		return;
	}

	this->OnOK();
}


void CDlogUserAdd::OnBnClickedOk2()
{	
	this->UpdateData(TRUE);
	if(this->m_strPw1 != this->m_strPw2)
	{
		MessageBox("���벻һ��");
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
		//��ʾԱ����
		this->m_strEmpName = empDlg.m_empSelected._name.c_str();
		//Ա����
		m_nRelevanceEmpID = empDlg.m_empSelected._id;

		UpdateData(FALSE);
	}
}
