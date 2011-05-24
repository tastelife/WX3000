#pragma once


// CDlogMain 对话框

class CDlogMain : public CDialog
{
	DECLARE_DYNAMIC(CDlogMain)

public:
	CDlogMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlogMain();

// 对话框数据
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

private:
	void EnableButton();
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton10();
};
