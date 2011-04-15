
// wxDoc.cpp : CwxDoc 类的实现
//

#include "stdafx.h"
#include "wx.h"

#include "wxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwxDoc

IMPLEMENT_DYNCREATE(CwxDoc, CDocument)

BEGIN_MESSAGE_MAP(CwxDoc, CDocument)
END_MESSAGE_MAP()


// CwxDoc 构造/析构

CwxDoc::CwxDoc()
{
	// TODO: 在此添加一次性构造代码

}

CwxDoc::~CwxDoc()
{
}

BOOL CwxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CwxDoc 序列化

void CwxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CwxDoc 诊断

#ifdef _DEBUG
void CwxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CwxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CwxDoc 命令
