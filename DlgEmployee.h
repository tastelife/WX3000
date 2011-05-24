#pragma once
#include "afxcmn.h"

#include "WXDbDataType.h"
#include "WXListCtrl.h"

// CDlgEmployee �Ի���

class CDlgEmployee : public CDialog
{
	DECLARE_DYNAMIC(CDlgEmployee)
public:
	enum E_START_TYPE
	{
		E_START_TYPE_SELECTION,
		E_START_TYPE_FUNCTION,
	};
public:
	CDlgEmployee(E_START_TYPE startType, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgEmployee();

// �Ի�������
	enum { IDD = IDD_DIALOG_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	
	CWXListCtrl m_listCtrl;
	CListCtrl m_list;

	WXDB::DBEmployeeData m_empSelected;
private:
	void List();
	void EnabaleOk();

	E_START_TYPE m_eStartType;
public:
	afx_msg void OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult);
};
