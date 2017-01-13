
// lab1_gembitskaya.h : главный файл заголовка для приложения lab1_gembitskaya
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Clab1_gembitskayaApp:
// О реализации данного класса см. lab1_gembitskaya.cpp
//

class Clab1_gembitskayaApp : public CWinAppEx
{
public:
	Clab1_gembitskayaApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab1_gembitskayaApp theApp;
