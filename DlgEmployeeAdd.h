#pragma once


// CDlgEmployeeAdd �Ի���

class CDlgEmployeeAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgEmployeeAdd)

public:
	CDlgEmployeeAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgEmployeeAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG_EMPLOYEE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
