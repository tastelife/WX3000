// DlgEmployeeAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployeeAdd.h"
#include "afxdialogex.h"

#include "WXComboBoxCtrl.h"

#include "UIControlProperties.h"
#include "UIEmployeeAdd.h"

#include "StaticDB.h"


// CDlgEmployeeAdd 对话框

IMPLEMENT_DYNAMIC(CDlgEmployeeAdd, CDialog)

CDlgEmployeeAdd::CDlgEmployeeAdd(int nEmployeeID, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEmployeeAdd::IDD, pParent)
	, m_nEmployeeID(nEmployeeID)
	, m_strEmployeeName(_T(""))
	, m_strEmployeeMobile(_T(""))
	, m_strEmployeePhone(_T(""))
	, m_dtBirthday(COleDateTime::GetCurrentTime())
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
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_dtBirthday);
}


BEGIN_MESSAGE_MAP(CDlgEmployeeAdd, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgEmployeeAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlgEmployeeAdd::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CDlgEmployeeAdd::OnBnClickedMfcbutton2)
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
	CWXComboBoxCtrl(&m_cmbEmployeeSex).SelectFirstCmbBox();
	//职员状态
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePositionState(), m_cmbEmployeePositionState);
	CWXComboBoxCtrl(&m_cmbEmployeePositionState).SelectFirstCmbBox();
	//职位
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePosition(), m_cmbEmployeePosition);
	CWXComboBoxCtrl(&m_cmbEmployeePosition).SelectFirstCmbBox();
	//部门
	EnumFillCmbBox(BNS::CompanyBase()->GetEnumList(), m_cmbEmployeeCompanyBase);
	CWXComboBoxCtrl(&m_cmbEmployeeCompanyBase).SelectFirstCmbBox();

	if(m_nEmployeeID>=0)
	{
		InitByEmpID(m_nEmployeeID);
	}
	else
	{
		//修改按钮状态
		WXUI::SetControlProperties<CButton>(*((CButton*) this->GetDlgItem(IDOK)), 
			WXUI::ControlProperties(WXUI::ControlProperties::E_SHOWSTATE_HIDE));
	}
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


//修改
void CDlgEmployeeAdd::OnBnClickedOk()
{
	WXBNS::BNSEmployeeData bnsEmpData;
	BNS::Employee()->Edit(bnsEmpData);
	//保存相片
	if(m_strImagePath!=m_strImagePathOld)
	{
		BNS::ImageSave()->PutEmployeeImage(m_nEmployeeID, m_strImagePath.GetBuffer(0));
	}

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



//通过员工ID初始化界面，用于修改
void CDlgEmployeeAdd::InitByEmpID(int nEmpID)
{
	WXBNS::BNSEmployeeData empData;
	BNS::Employee()->GetInfo(nEmpID, empData);

	//编号状态
	WXUI::SetControlProperties<CEdit>(*((CEdit*) this->GetDlgItem(IDC_EDIT1)), 
		WXUI::CEmployeeAdd<false>().GetEmployeeIDProterty());
	//新建按钮状态
	WXUI::SetControlProperties<CButton>(*((CButton*) this->GetDlgItem(IDC_BUTTON10)), 
		WXUI::ControlProperties(WXUI::ControlProperties::E_SHOWSTATE_HIDE));
	
	//性别
	CWXComboBoxCtrl(&m_cmbEmployeeSex).SelectCmbBoxByItem(empData._sex);
	//职员状态
	CWXComboBoxCtrl(&m_cmbEmployeePositionState).SelectCmbBoxByItem(empData._positionState);
	//职位
	CWXComboBoxCtrl(&m_cmbEmployeePosition).SelectCmbBoxByItem(empData._position);
	//部门
	CWXComboBoxCtrl(&m_cmbEmployeeCompanyBase).SelectCmbBoxByItem(empData._companyBaseID);
	//生日
	this->m_dtBirthday = empData._birthday;
	this->m_strEmployeeName = empData._name.c_str();
	this->m_strEmployeeMobile = empData._mobile.c_str();
	this->m_strEmployeePhone = empData._phone.c_str();

	//图像
	std::string strImagePath;
	if(""!=(strImagePath=BNS::ImageSave()->DownLoadEmployeeImage(nEmpID)))
	{
		m_strImagePath = strImagePath.c_str();
		m_strImagePathOld = strImagePath.c_str();
		DisplayImage();
	}

	this->UpdateData(0);
}



//相片
void CDlgEmployeeAdd::OnBnClickedMfcbutton2()
{
	CString strFilter;
	strFilter = "位图文件|*.bmp|JPEG 图像文件|*.jpg|GIF 图像文件|*.gif|PNG 图像文件|*.png||";
	CFileDialog fd(true, strFilter);
	if(IDOK==fd.DoModal())
	{
		m_strImagePath = fd.GetPathName();
		DisplayImage();
	}
}


//显示相片
void CDlgEmployeeAdd::DisplayImage()
{
	if(""==m_strImagePath)
	{
		return;
	}
	if(!m_image.IsNull())
	{
		m_image.Detach();
	}
	m_btnEmployeePicture.SetImage(m_strImagePath);
}

