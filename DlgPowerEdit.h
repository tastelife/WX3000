#pragma once
#include "afxwin.h"


// CDlgPowerEdit 对话框

class CDlgPowerEdit : public CDialog
{
	DECLARE_DYNAMIC(CDlgPowerEdit)

public:
	CDlgPowerEdit(int nUserID, int nGroupID, int nUserGroupID,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPowerEdit();

// 对话框数据
	enum { IDD = IDD_DIALOG_POWER_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUserName;
	CString m_strGroupName;
private:
	int m_nUserID;
	int m_nGroupID;
	int m_nUserGroupID;
private:
	void List();
	int SeclecByItemData(int nData);

public:
	afx_msg void OnBnClickedOk();
	CComboBox m_cmbGroup;
};
