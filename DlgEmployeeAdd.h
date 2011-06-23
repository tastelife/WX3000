#pragma once
#include "afxwin.h"
#include "afxbutton.h"

#include <map>
#include "atlcomtime.h"
#include "WXButtonImage.h"

// CDlgEmployeeAdd 对话框

class CDlgEmployeeAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgEmployeeAdd)

public:
	CDlgEmployeeAdd(int nEmployeeID=-1, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgEmployeeAdd();

// 对话框数据
	enum { IDD = IDD_DIALOG_EMPLOYEE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton10();
	int m_nEmployeeID;
	CString m_strEmployeeName;
	CString m_strEmployeeMobile;
	CString m_strEmployeePhone;
	CComboBox m_cmbEmployeeCompanyBase;
	CComboBox m_cmbEmployeePosition;
	CComboBox m_cmbEmployeePositionState;
	CComboBox m_cmbEmployeeSex;
	CWXButtonImage m_btnEmployeePicture;
	
	//相片路径
	CString m_strImagePath;
	//原相片路径
	CString m_strImagePathOld;

private:
	//枚举数据加入下拉框内容
	void EnumFillCmbBox(std::map<int, std::string>& enumList, CComboBox& cmbBox);
	void EnumFillCmbBox(std::map<int, std::string>&& enumList, CComboBox& cmbBox);

	//通过员工ID初始化界面，用于修改
	void InitByEmpID(int nEmpID);

	//显示相片
	void DisplayImage();
private:
	CImage m_image;

public:
	COleDateTime m_dtBirthday;
	afx_msg void OnBnClickedMfcbutton2();
};
