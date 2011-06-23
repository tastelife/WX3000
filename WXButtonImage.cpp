// WXButtonImage.cpp : 实现文件
//

#include "stdafx.h"
#include "WXButtonImage.h"


// CWXButtonImage

IMPLEMENT_DYNAMIC(CWXButtonImage, CMFCButton)

CWXButtonImage::CWXButtonImage()
{

}

CWXButtonImage::~CWXButtonImage()
{
}


BEGIN_MESSAGE_MAP(CWXButtonImage, CMFCButton)
END_MESSAGE_MAP()



// CWXButtonImage 消息处理程序




void CWXButtonImage::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
{
	CMFCButton::OnDraw(pDC, rect, uiState);

	if(m_image.IsNull())
	{
		return;
	}
	m_image.StretchBlt(pDC->m_hDC,
		rect, 
		CRect(0,0,m_image.GetWidth(),m_image.GetHeight()));
}


void CWXButtonImage::SetImage(CString strPath)
{			
	if(!m_image.IsNull())
	{
		m_image.Destroy();
	}

	m_image.Load(strPath);

	this->Invalidate();
}