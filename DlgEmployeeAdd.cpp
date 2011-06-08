// DlgEmployeeAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployeeAdd.h"
#include "afxdialogex.h"

#include "StaticDB.h"


// CDlgEmployeeAdd 对话框

IMPLEMENT_DYNAMIC(CDlgEmployeeAdd, CDialog)

CDlgEmployeeAdd::CDlgEmployeeAdd(int nEmployeeID, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEmployeeAdd::IDD, pParent)
	, m_nEmployeeID(nEmployeeID)
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

BOOL CDlgEmployeeAdd::OnInitDialog()
{
	CDialog::OnInitDialog();


	if(-1==this->m_nEmployeeID)
	{
		this->GetDlgItem(IDOK)->ShowWindow(0);
	}
	else
	{
		this->GetDlgItem(IDC_BUTTON10)->ShowWindow(0);
	}
	
	//加入性别下拉框内容
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypeSex(), m_cmbEmployeeSex);
	SelectFirstCmbBox(m_cmbEmployeeSex);
	//职员状态
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePositionState(), m_cmbEmployeePositionState);
	SelectFirstCmbBox(m_cmbEmployeePositionState);
	//职位
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePosition(), m_cmbEmployeePosition);
	SelectFirstCmbBox(m_cmbEmployeePosition);
	//部门
	EnumFillCmbBox(BNS::CompanyBase()->GetEnumList(), m_cmbEmployeeCompanyBase);
	SelectFirstCmbBox(m_cmbEmployeeCompanyBase);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


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

//枚举数据加入下拉框内容
void CDlgEmployeeAdd::EnumFillCmbBox(std::map<int, std::string>& enumList, CComboBox& cmbBox)
{

	WXBNS::CDictionary::LIST::iterator it=enumList.begin();
	
	for( WXBNS::CDictionary::LIST::size_type i=0;i<enumList.size(); ++it, ++i)
	{
		if(it->second!="")
		{
			cmbBox.AddString(it->second.c_str());
			cmbBox.SetItemData(i, it->first);
		}
	}
}
void CDlgEmployeeAdd::EnumFillCmbBox(std::map<int, std::string>&& enumList, CComboBox& cmbBox)
{
	EnumFillCmbBox(enumList, cmbBox);
}


//下拉框默认选中第一行
void CDlgEmployeeAdd::SelectFirstCmbBox(CComboBox& cmbBox)
{
	if(cmbBox.GetCount()>0)
	{
		cmbBox.SetCurSel(0);
	}
}
