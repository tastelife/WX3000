#pragma once

#include "WXListCtrl.h"
#include "afxcmn.h"

// CDlgPower �Ի���

class CDlgPower : public CDialog
{
	DECLARE_DYNAMIC(CDlgPower)

public:
	CDlgPower(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPower();

// �Ի�������
	enum { IDD = IDD_DIALOG_POWER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
