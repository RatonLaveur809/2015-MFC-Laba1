
// lab1_gembitskayaDoc.h : интерфейс класса Clab1_gembitskayaDoc
//
#include "Afxtempl.h"

#pragma once

class CCoolRect : public CObject
{
public :
	int m_X1, m_Y1, m_X2 , m_Y2;
	CPen *m_pen;
	CBrush *m_brush;

	CCoolRect (int X1, int Y1, int X2, int Y2, CPen *pen, CBrush *brush)
	{
		m_pen=pen;
		m_brush=brush;
		m_X1 = X1; m_Y1 = Y1; m_X2 = X2; m_Y2 = Y2;
		
	}
	void Draw (CDC *PDC) ;
};



class Clab1_gembitskayaDoc : public CDocument
{
	protected :
	CTypedPtrArray<CObArray , CCoolRect*> m_RectArray;
public :
	void AddRect (int X1, int Y1, int X2, int Y2,CPen *pen, CBrush *brush) ;
	CCoolRect *GetRect (int Index) ;
	int GetNumRects () ;

protected: // создать только из сериализации
	Clab1_gembitskayaDoc();
	DECLARE_DYNCREATE(Clab1_gembitskayaDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~Clab1_gembitskayaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
	afx_msg void OnEditClearAll();
	afx_msg void OnUpdateEditClearAll(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditGreen();
	afx_msg void OnEditYellow();
};
