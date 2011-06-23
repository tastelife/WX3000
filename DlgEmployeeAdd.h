#pragma once
#include "afxwin.h"
#include "afxbutton.h"

#include <map>
#include "atlcomtime.h"
#include "WXButtonImage.h"

// CDlgEmployeeAdd �Ի���

class CDlgEmployeeAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgEmployeeAdd)

public:
	CDlgEmployeeAdd(int nEmployeeID=-1, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgEmployeeAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG_EMPLOYEE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	
	//��Ƭ·��
	CString m_strImagePath;
	//ԭ��Ƭ·��
	CString m_strImagePathOld;

private:
	//ö�����ݼ�������������
	void EnumFillCmbBox(std::map<int, std::string>& enumList, CComboBox& cmbBox);
	void EnumFillCmbBox(std::map<int, std::string>&& enumList, CComboBox& cmbBox);

	//ͨ��Ա��ID��ʼ�����棬�����޸�
	void InitByEmpID(int nEmpID);

	//��ʾ��Ƭ
	void DisplayImage();
private:
	CImage m_image;

public:
	COleDateTime m_dtBirthday;
	afx_msg void OnBnClickedMfcbutton2();
};
