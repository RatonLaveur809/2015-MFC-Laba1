
// lab1_gembitskayaDoc.cpp : реализация класса Clab1_gembitskayaDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "lab1_gembitskaya.h"
#endif

#include "lab1_gembitskayaDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clab1_gembitskayaDoc

IMPLEMENT_DYNCREATE(Clab1_gembitskayaDoc, CDocument)

BEGIN_MESSAGE_MAP(Clab1_gembitskayaDoc, CDocument)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, &Clab1_gembitskayaDoc::OnEditClearAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR_ALL, &Clab1_gembitskayaDoc::OnUpdateEditClearAll)
	ON_COMMAND(ID_EDIT_UNDO, &Clab1_gembitskayaDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &Clab1_gembitskayaDoc::OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_GREEN, &Clab1_gembitskayaDoc::OnEditGreen)
	ON_COMMAND(ID_EDIT_YELLOW, &Clab1_gembitskayaDoc::OnEditYellow)
END_MESSAGE_MAP()


// создание/уничтожение Clab1_gembitskayaDoc

Clab1_gembitskayaDoc::Clab1_gembitskayaDoc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

Clab1_gembitskayaDoc::~Clab1_gembitskayaDoc()
{
}

BOOL Clab1_gembitskayaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация Clab1_gembitskayaDoc

void Clab1_gembitskayaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void Clab1_gembitskayaDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void Clab1_gembitskayaDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void Clab1_gembitskayaDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика Clab1_gembitskayaDoc

#ifdef _DEBUG
void Clab1_gembitskayaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clab1_gembitskayaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды Clab1_gembitskayaDoc

void CCoolRect::Draw(CDC *PDC)
{
	CPen* oldPen=PDC->SelectObject(m_pen);
	CBrush* oldBrush = PDC->SelectObject(m_brush);
	PDC->Rectangle(m_X1,m_Y1,m_X2,m_Y2);
	PDC->SelectObject(oldPen);
	PDC->SelectObject(oldBrush);
}

void Clab1_gembitskayaDoc::AddRect(int X1, int Y1, int X2, int Y2,CPen *pen,CBrush *brush)
{
	CCoolRect *pRect=new CCoolRect(X1, Y1, X2, Y2,pen,brush);
	m_RectArray.Add(pRect);
}

CCoolRect* Clab1_gembitskayaDoc::GetRect(int Index)
{
	if(Index<0||Index>m_RectArray.GetUpperBound ())
	return 0;
	return m_RectArray.GetAt(Index);
}

int Clab1_gembitskayaDoc::GetNumRects()
{
	return (int)m_RectArray.GetSize();
}


void Clab1_gembitskayaDoc::DeleteContents()
{
	int Index=(int)m_RectArray.GetSize();
	while(Index--)
	delete m_RectArray.GetAt (Index);
	m_RectArray.RemoveAll();

	CDocument::DeleteContents();
}


void Clab1_gembitskayaDoc::OnEditClearAll()
{
	DeleteContents();
	UpdateAllViews(0);
}


void Clab1_gembitskayaDoc::OnUpdateEditClearAll(CCmdUI *pCmdUI)
{
	pCmdUI->Enable((int)m_RectArray.GetSize());
}


void Clab1_gembitskayaDoc::OnEditUndo()
{
	int Index=(int)m_RectArray.GetUpperBound();
	if (Index>-1)
	{
		delete m_RectArray.GetAt(Index);
		m_RectArray.RemoveAt(Index);
	}
	UpdateAllViews(0);

}


void Clab1_gembitskayaDoc::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	pCmdUI->Enable((int)m_RectArray.GetSize());
}


void Clab1_gembitskayaDoc::OnEditGreen()
{	
	int Index=(int)m_RectArray.GetSize();
	while(Index--)
	m_RectArray[Index]->m_brush=new CBrush(RGB(0, 255, 0));

	UpdateAllViews(0);
}


void Clab1_gembitskayaDoc::OnEditYellow()
{
	int Index=(int)m_RectArray.GetSize();
	while(Index--)
	m_RectArray[Index]->m_brush=new CBrush(RGB(255, 255, 0));

	UpdateAllViews(0);
}
