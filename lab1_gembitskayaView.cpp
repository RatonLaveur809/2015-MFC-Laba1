
// lab1_gembitskayaView.cpp : реализация класса Clab1_gembitskayaView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lab1_gembitskaya.h"
#endif

#include "lab1_gembitskayaDoc.h"
#include "lab1_gembitskayaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag=0;
// Clab1_gembitskayaView

IMPLEMENT_DYNCREATE(Clab1_gembitskayaView, CView)

BEGIN_MESSAGE_MAP(Clab1_gembitskayaView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Clab1_gembitskayaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// создание/уничтожение Clab1_gembitskayaView

Clab1_gembitskayaView::Clab1_gembitskayaView()
{
	// TODO: добавьте код создания
	m_Dragging = 0;
	m_HCursor=AfxGetApp()->LoadStandardCursor(IDC_UPARROW);

}

Clab1_gembitskayaView::~Clab1_gembitskayaView()
{
}

BOOL Clab1_gembitskayaView::PreCreateWindow(CREATESTRUCT& cs)
{
	m_ClassName=AfxRegisterWndClass(
		CS_HREDRAW|CS_VREDRAW, // стили окна
		0,					  // без указателя;
		(HBRUSH)::GetStockObject (WHITE_BRUSH),
						  	  // задать чисто белый фон;
		0);					  //без значка
	cs.lpszClass = m_ClassName;

	return CView::PreCreateWindow(cs);
}

// рисование Clab1_gembitskayaView

void Clab1_gembitskayaView::OnDraw(CDC* pDC)
{
	
	Clab1_gembitskayaDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
		int Index=pDoc->GetNumRects();
	while(Index--)
		pDoc->GetRect (Index)->Draw (pDC);


	// TODO: добавьте здесь код отрисовки для собственных данных
}


// печать Clab1_gembitskayaView


void Clab1_gembitskayaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Clab1_gembitskayaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void Clab1_gembitskayaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void Clab1_gembitskayaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void Clab1_gembitskayaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Clab1_gembitskayaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика Clab1_gembitskayaView

#ifdef _DEBUG
void Clab1_gembitskayaView::AssertValid() const
{
	CView::AssertValid();
}

void Clab1_gembitskayaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab1_gembitskayaDoc* Clab1_gembitskayaView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab1_gembitskayaDoc)));
	return (Clab1_gembitskayaDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений Clab1_gembitskayaView


void Clab1_gembitskayaView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	m_PointOld=point;
	m_PointOrigin=point;

	SetCapture();
	m_Dragging=1;
	
RECT Rect;
	GetClientRect(&Rect);
	ClientToScreen(&Rect);
	::ClipCursor(&Rect);

	CView::OnLButtonDown(nFlags, point);
}


void Clab1_gembitskayaView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

		::SetCursor (m_HCursor);
		
	if (m_Dragging)
	{
		CWindowDC ClientDC(this);		
		flag=0;
		ClientDC.SelectObject(CBrush(RGB(255, 255,255 )));
		if (nFlags&MK_SHIFT)
		{
			ClientDC.SelectObject(CPen(PS_SOLID, 10, RGB(255, 0,0 )));
			flag=1;
		}

		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);

		m_PointOld = point;
	}
	CView::OnMouseMove(nFlags, point);
}


void Clab1_gembitskayaView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_Dragging)
	{
		m_Dragging = 0;
		::ReleaseCapture();
		::ClipCursor (NULL);
		CClientDC ClientDC (this);
		CPen* pen=NULL;
		CBrush* brush = NULL;
		brush=new CBrush(RGB(255, 255, 255));
		if(flag==1)
		pen  = new CPen(PS_SOLID, 10,RGB(255, 0, 0));
		else
			pen  = new CPen(PS_SOLID, 10,RGB(0, 0, 0));
		CPen* oldPen = ClientDC.SelectObject(pen);
		CBrush* oldBrush=ClientDC.SelectObject(brush);

		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		ClientDC.SelectObject(oldPen);
		ClientDC.SelectObject(oldBrush);

		Clab1_gembitskayaDoc* pDoc=GetDocument();
		pDoc->AddRect(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y,pen,brush);
	}

	CView::OnLButtonUp(nFlags, point);
}


void Clab1_gembitskayaView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
