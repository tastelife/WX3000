// DlgEmployee.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployee.h"
#include "afxdialogex.h"

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "StaticDB.h"
#include "WXCommFun.h"

// CDlgEmployee �Ի���

IMPLEMENT_DYNAMIC(CDlgEmployee, CDialog)

CDlgEmployee::CDlgEmployee(E_START_TYPE startType, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEmployee::IDD, pParent),
	m_listCtrl(&m_list),
	m_eStartType(startType)
{

}

CDlgEmployee::~CDlgEmployee()
{
}

void CDlgEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
}


BEGIN_MESSAGE_MAP(CDlgEmployee, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgEmployee::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgEmployee::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgEmployee::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDlgEmployee::OnBnClickedButton9)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &CDlgEmployee::OnLvnItemchangedList3)
END_MESSAGE_MAP()


// CDlgEmployee ��Ϣ�������

BOOL CDlgEmployee::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"Ա����", LVCFMT_LEFT, 50));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"����", LVCFMT_LEFT, 74));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(2,"����", LVCFMT_LEFT, 100));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(3,"�Ա�", LVCFMT_LEFT, 50));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(4,"����", LVCFMT_LEFT, 110));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(5,"�ֻ�", LVCFMT_LEFT, 80));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(6,"����", LVCFMT_LEFT, 80));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(7,"ְλ", LVCFMT_LEFT, 60));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(8,"��ǰ״̬", LVCFMT_LEFT, 60));
	CWXListCtrl(&this->m_list).SetColTitle(vecTitle);

	
	List();

	if(E_START_TYPE_SELECTION==m_eStartType)
	{
		this->GetDlgItem(IDC_BUTTON1)->ShowWindow(0);
		this->GetDlgItem(IDC_BUTTON8)->ShowWindow(0);
		this->GetDlgItem(IDC_BUTTON9)->ShowWindow(0);
		
		EnabaleOk();
	}
	else
	{	
		this->GetDlgItem(IDOK)->ShowWindow(0);

		if(!BNS::Power()->GetEmployeePower(BNS::Login()->GetLoginID()).IsCreatePower())
		{
			this->GetDlgItem(IDC_BUTTON1)->ShowWindow(0);
		}
		if(!BNS::Power()->GetEmployeePower(BNS::Login()->GetLoginID()).IsEditPower())
		{
			this->GetDlgItem(IDC_BUTTON8)->ShowWindow(0);
		}
		if(!BNS::Power()->GetEmployeePower(BNS::Login()->GetLoginID()).IsDeletePower())
		{
			this->GetDlgItem(IDC_BUTTON9)->ShowWindow(0);
		}
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDlgEmployee::List()
{
	m_list.DeleteAllItems();

	BNS::Dictionary()->RefrushAll();
	BNS::CompanyBase()->RefrushAll();
	BNS::Employee()->RefrushAll();

	CWXMemDataVector<WXDB::DBEmployeeData> vecData;
	vecData = BNS::Employee()->m_memDataVec;

	CString str;

	for(unsigned int i=0; i<vecData.size(); ++i)
	{
		WXDB::DBEmployeeData data = vecData.at(i);		
		std::vector<std::string> vecItem;
		
		//Ա����
		vecItem.push_back(CWXConver::single2s(data._id));
		//����
		vecItem.push_back(data._name);
		//����
		WXDB::DBCompanyBaseData companyBaseData;
		BNS::CompanyBase()->GetInfo(data._companyBaseID, companyBaseData);
		vecItem.push_back(companyBaseData._companyName);
		//�Ա�
		vecItem.push_back(BNS::Dictionary()->GetSexName(data._sex));
		//����
		vecItem.push_back(CWXConver::date2s(data._birthday));
		//�ֻ�
		vecItem.push_back(data._mobile);
		//����
		vecItem.push_back(data._phone);
		//ְλ
		vecItem.push_back(BNS::Dictionary()->GetEmployeePositionName(data._position));
		//��ǰ״̬
		vecItem.push_back(BNS::Dictionary()->GetRecordName(data._recordStat));

		m_listCtrl.AddItems(vecItem, data._id);
	}
	
	m_listCtrl.Select(0);
}

//ȷ��
void CDlgEmployee::OnBnClickedOk()
{
	BNS::Employee()->GetInfo(m_list.GetItemData(m_listCtrl.GetFirstSelected()), m_empSelected);

	CDialog::OnOK();
}

//���
void CDlgEmployee::OnBnClickedButton1()
{
}

//�޸�
void CDlgEmployee::OnBnClickedButton8()
{
}

//ɾ��
void CDlgEmployee::OnBnClickedButton9()
{
}


void CDlgEmployee::OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	EnabaleOk();
	EnabaleEditDelete();

	*pResult = 0;
}


//ѡ��ʱ ��ȷ������ť�Ƿ���Ч
void CDlgEmployee::EnabaleOk()
{
	if(m_listCtrl.GetFirstSelected()>=0)
	{
		this->GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
	else
	{
		this->GetDlgItem(IDOK)->EnableWindow(FALSE);
	}
}

//���༭����ɾ������ť�Ƿ���Ч
void CDlgEmployee::EnabaleEditDelete()
{
	if(m_listCtrl.GetFirstSelected()>=0)
	{
		int nID = m_list.GetItemData(m_listCtrl.GetFirstSelected());
		
		this->GetDlgItem(IDC_BUTTON8)->EnableWindow(BNS::Employee()->IsPermitEdit(nID));		
		this->GetDlgItem(IDC_BUTTON9)->EnableWindow(BNS::Employee()->IsPermitEdit(nID));
	}
	else
	{
		this->GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);		
		this->GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	}
}