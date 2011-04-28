#pragma once
#include "afxcmn.h"

#include "WXDBConnect.h"
#include "WXDbComm.h"
#include "WXListCtrl.h"

#include "BNSUser.h"

#ifdef _WIN32_WCE
#error "Windows CE 不支持 CDHtmlDialog。"
#endif 

// CDlg_User 对话框




//struct DBUserData
//{
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_USE(DBUserData, 3);
//
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(int, _ID, 0);
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _Name, 1);
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD(std::string, _PassWord, 2);
//	WX_COMM_STRUCT_MEM_VAR_SET_GET_ADD_DEFAULT(int, _EmpID, 3, -1);
//};



class CDlg_User : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CDlg_User)

public:
	CDlg_User(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg_User();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_DIALOG_USER, IDH = IDR_HTML_DLG_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
private:
	void List(CListCtrl* pList);
	int Add();
public:
	CListCtrl m_list;
	CWXListCtrl m_listCtrl;

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedOk2();
};
