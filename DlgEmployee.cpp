// DlgEmployee.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployee.h"
#include "afxdialogex.h"

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "StaticDB.h"
#include "WXCommFun.h"

// CDlgEmployee 对话框

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


// CDlgEmployee 消息处理程序

BOOL CDlgEmployee::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::vector<SWXLISTCTROLCOLUMN> vecTitle;
	vecTitle.push_back(SWXLISTCTROLCOLUMN(0,"员工号", LVCFMT_LEFT, 50));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(1,"姓名", LVCFMT_LEFT, 74));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(2,"部门", LVCFMT_LEFT, 100));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(3,"性别", LVCFMT_LEFT, 50));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(4,"生日", LVCFMT_LEFT, 110));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(5,"手机", LVCFMT_LEFT, 80));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(6,"座机", LVCFMT_LEFT, 80));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(7,"职位", LVCFMT_LEFT, 60));
	vecTitle.push_back(SWXLISTCTROLCOLUMN(8,"当前状态", LVCFMT_LEFT, 60));
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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
		
		//员工号
		vecItem.push_back(CWXConver::single2s(data._id));
		//姓名
		vecItem.push_back(data._name);
		//部门
		WXDB::DBCompanyBaseData companyBaseData;
		BNS::CompanyBase()->GetInfo(data._companyBaseID, companyBaseData);
		vecItem.push_back(companyBaseData._companyName);
		//性别
		vecItem.push_back(BNS::Dictionary()->GetSexName(data._sex));
		//生日
		vecItem.push_back(CWXConver::date2s(data._birthday));
		//手机
		vecItem.push_back(data._mobile);
		//座机
		vecItem.push_back(data._phone);
		//职位
		vecItem.push_back(BNS::Dictionary()->GetEmployeePositionName(data._position));
		//当前状态
		vecItem.push_back(BNS::Dictionary()->GetRecordName(data._recordStat));

		m_listCtrl.AddItems(vecItem, data._id);
	}
	
	m_listCtrl.Select(0);
}

//确定
void CDlgEmployee::OnBnClickedOk()
{
	BNS::Employee()->GetInfo(m_list.GetItemData(m_listCtrl.GetFirstSelected()), m_empSelected);

	CDialog::OnOK();
}

//添加
void CDlgEmployee::OnBnClickedButton1()
{
}

//修改
void CDlgEmployee::OnBnClickedButton8()
{
}

//删除
void CDlgEmployee::OnBnClickedButton9()
{
}


void CDlgEmployee::OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	EnabaleOk();
	EnabaleEditDelete();

	*pResult = 0;
}


//选择时 “确定”按钮是否有效
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

//“编辑”“删除”按钮是否有效
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