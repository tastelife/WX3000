#pragma once

#include "WXListCtrl.h"
#include "afxcmn.h"

// CDlgPower 对话框

class CDlgPower : public CDialog
{
	DECLARE_DYNAMIC(CDlgPower)

public:
	CDlgPower(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPower();

// 对话框数据
	enum { IDD = IDD_DIALOG_POWER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	void List(CListCtrl* pList);

private:
	CWXListCtrl m_listGroupCtl;
public:
	CListCtrl m_listGroup;
	afx_msg void OnBnClickedOk();
};
