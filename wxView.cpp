
// wxView.cpp : CwxView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CwxView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CwxView 构造/析构

CwxView::CwxView()
{
	// TODO: 在此处添加构造代码

}

CwxView::~CwxView()
{
}

BOOL CwxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CwxView 绘制

void CwxView::OnDraw(CDC* /*pDC*/)
{
	CwxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CwxView 打印


void CwxView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CwxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CwxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CwxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CwxView 诊断

#ifdef _DEBUG
void CwxView::AssertValid() const
{
	CView::AssertValid();
}

void CwxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CwxDoc* CwxView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwxDoc)));
	return (CwxDoc*)m_pDocument;
}
#endif //_DEBUG


// CwxView 消息处理程序
