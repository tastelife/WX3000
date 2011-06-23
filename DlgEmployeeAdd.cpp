// DlgEmployeeAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wx.h"
#include "DlgEmployeeAdd.h"
#include "afxdialogex.h"

#include "WXComboBoxCtrl.h"

#include "UIControlProperties.h"
#include "UIEmployeeAdd.h"

#include "StaticDB.h"


// CDlgEmployeeAdd �Ի���

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


// CDlgEmployeeAdd ��Ϣ�������

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
	
	//�����Ա�����������
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypeSex(), m_cmbEmployeeSex);
	CWXComboBoxCtrl(&m_cmbEmployeeSex).SelectFirstCmbBox();
	//ְԱ״̬
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePositionState(), m_cmbEmployeePositionState);
	CWXComboBoxCtrl(&m_cmbEmployeePositionState).SelectFirstCmbBox();
	//ְλ
	EnumFillCmbBox(BNS::Dictionary()->GetListByTypePosition(), m_cmbEmployeePosition);
	CWXComboBoxCtrl(&m_cmbEmployeePosition).SelectFirstCmbBox();
	//����
	EnumFillCmbBox(BNS::CompanyBase()->GetEnumList(), m_cmbEmployeeCompanyBase);
	CWXComboBoxCtrl(&m_cmbEmployeeCompanyBase).SelectFirstCmbBox();

	if(m_nEmployeeID>=0)
	{
		InitByEmpID(m_nEmployeeID);
	}
	else
	{
		//�޸İ�ť״̬
		WXUI::SetControlProperties<CButton>(*((CButton*) this->GetDlgItem(IDOK)), 
			WXUI::ControlProperties(WXUI::ControlProperties::E_SHOWSTATE_HIDE));
	}
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


//�޸�
void CDlgEmployeeAdd::OnBnClickedOk()
{
	WXBNS::BNSEmployeeData bnsEmpData;
	BNS::Employee()->Edit(bnsEmpData);
	//������Ƭ
	if(m_strImagePath!=m_strImagePathOld)
	{
		BNS::ImageSave()->PutEmployeeImage(m_nEmployeeID, m_strImagePath.GetBuffer(0));
	}

	CDialog::OnOK();
}

//�½�
void CDlgEmployeeAdd::OnBnClickedButton10()
{
	CDialog::OnOK();
}

//ö�����ݼ�������������
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



//ͨ��Ա��ID��ʼ�����棬�����޸�
void CDlgEmployeeAdd::InitByEmpID(int nEmpID)
{
	WXBNS::BNSEmployeeData empData;
	BNS::Employee()->GetInfo(nEmpID, empData);

	//���״̬
	WXUI::SetControlProperties<CEdit>(*((CEdit*) this->GetDlgItem(IDC_EDIT1)), 
		WXUI::CEmployeeAdd<false>().GetEmployeeIDProterty());
	//�½���ť״̬
	WXUI::SetControlProperties<CButton>(*((CButton*) this->GetDlgItem(IDC_BUTTON10)), 
		WXUI::ControlProperties(WXUI::ControlProperties::E_SHOWSTATE_HIDE));
	
	//�Ա�
	CWXComboBoxCtrl(&m_cmbEmployeeSex).SelectCmbBoxByItem(empData._sex);
	//ְԱ״̬
	CWXComboBoxCtrl(&m_cmbEmployeePositionState).SelectCmbBoxByItem(empData._positionState);
	//ְλ
	CWXComboBoxCtrl(&m_cmbEmployeePosition).SelectCmbBoxByItem(empData._position);
	//����
	CWXComboBoxCtrl(&m_cmbEmployeeCompanyBase).SelectCmbBoxByItem(empData._companyBaseID);
	//����
	this->m_dtBirthday = empData._birthday;
	this->m_strEmployeeName = empData._name.c_str();
	this->m_strEmployeeMobile = empData._mobile.c_str();
	this->m_strEmployeePhone = empData._phone.c_str();

	//ͼ��
	std::string strImagePath;
	if(""!=(strImagePath=BNS::ImageSave()->DownLoadEmployeeImage(nEmpID)))
	{
		m_strImagePath = strImagePath.c_str();
		m_strImagePathOld = strImagePath.c_str();
		DisplayImage();
	}

	this->UpdateData(0);
}



//��Ƭ
void CDlgEmployeeAdd::OnBnClickedMfcbutton2()
{
	CString strFilter;
	strFilter = "λͼ�ļ�|*.bmp|JPEG ͼ���ļ�|*.jpg|GIF ͼ���ļ�|*.gif|PNG ͼ���ļ�|*.png||";
	CFileDialog fd(true, strFilter);
	if(IDOK==fd.DoModal())
	{
		m_strImagePath = fd.GetPathName();
		DisplayImage();
	}
}


//��ʾ��Ƭ
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

