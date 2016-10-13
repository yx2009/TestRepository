
// MFCAppTestView.cpp : CMFCAppTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCAppTest.h"
#endif

#include "MFCAppTestDoc.h"
#include "MFCAppTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppTestView

IMPLEMENT_DYNCREATE(CMFCAppTestView, CView)

BEGIN_MESSAGE_MAP(CMFCAppTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCAppTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCAppTestView ����/����

CMFCAppTestView::CMFCAppTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCAppTestView::~CMFCAppTestView()
{
}

BOOL CMFCAppTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCAppTestView ����

void CMFCAppTestView::OnDraw(CDC* /*pDC*/)
{
	CMFCAppTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCAppTestView ��ӡ


void CMFCAppTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCAppTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCAppTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCAppTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMFCAppTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppTestView ���

#ifdef _DEBUG
void CMFCAppTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppTestDoc* CMFCAppTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppTestDoc)));
	return (CMFCAppTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppTestView ��Ϣ�������
