#pragma once


#include "BNSUser.h"

// CDlogUserAdd �Ի���

class CDlogUserAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlogUserAdd)

public:
	CDlogUserAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlogUserAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG_USER_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	CString m_strUserName;

private:
	CString m_strPw1;
	CString m_strPw2;
public:
	int m_nID;
	afx_msg void OnBnClickedOk2();
};
