
// wxDoc.cpp : CwxDoc ���ʵ��
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


// CwxDoc ����/����

CwxDoc::CwxDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CwxDoc::~CwxDoc()
{
}

BOOL CwxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CwxDoc ���л�

void CwxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CwxDoc ���

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


// CwxDoc ����
