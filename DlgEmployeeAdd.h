#pragma once
#include "afxwin.h"
#include "afxbutton.h"


// CDlgEmployeeAdd 对话框

class CDlgEmployeeAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgEmployeeAdd)

public:
	CDlgEmployeeAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgEmployeeAdd();

// 对话框数据
	enum { IDD = IDD_DIALOG_EMPLOYEE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
	CMFCButton m_btnEmployeePicture;
};
