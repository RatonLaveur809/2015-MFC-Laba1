
// lab1_gembitskayaView.h : интерфейс класса Clab1_gembitskayaView
//

#pragma once


class Clab1_gembitskayaView : public CView
{
protected: // создать только из сериализации
	Clab1_gembitskayaView();
	CString m_ClassName;
	int m_Dragging;
	HCURSOR m_HCursor;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
	
	DECLARE_DYNCREATE(Clab1_gembitskayaView)

// Атрибуты
public:
	Clab1_gembitskayaDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~Clab1_gembitskayaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // отладочная версия в lab1_gembitskayaView.cpp
inRect Clab1_gembitskayaDoc* Clab1_gembitskayaView::GetDocument() const
   { return reinterpret_cast<Clab1_gembitskayaDoc*>(m_pDocument); }
#endif

