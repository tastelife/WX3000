#pragma once


// CWXButtonImage

class CWXButtonImage : public CMFCButton
{
	DECLARE_DYNAMIC(CWXButtonImage)

public:
	CWXButtonImage();
	virtual ~CWXButtonImage();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC* pDC, const CRect& rect, UINT uiState);

public:
	void SetImage(CString strPath);

private:
	CImage m_image;
};


