
// wxView.cpp : CwxView ���ʵ��
//

#include "stdafx.h"
#include "wx.h"

#include "wxDoc.h"
#include "wxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwxView

IMPLEMENT_DYNCREATE(CwxView, CView)

BEGIN_MESSAGE_MAP(CwxView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CwxView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CwxView ����/����

CwxView::CwxView()
{
	// TODO: �ڴ˴���ӹ������

}

CwxView::~CwxView()
{
}

BOOL CwxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CwxView ����

void CwxView::OnDraw(CDC* /*pDC*/)
{
	CwxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CwxView ��ӡ


void CwxView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CwxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CwxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CwxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CwxView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CwxView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CwxView ���

#ifdef _DEBUG
void CwxView::AssertValid() const
{
	CView::AssertValid();
}

void CwxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CwxDoc* CwxView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwxDoc)));
	return (CwxDoc*)m_pDocument;
}
#endif //_DEBUG


// CwxView ��Ϣ�������
