
// lab1_gembitskaya.h : ������� ���� ��������� ��� ���������� lab1_gembitskaya
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Clab1_gembitskayaApp:
// � ���������� ������� ������ ��. lab1_gembitskaya.cpp
//

class Clab1_gembitskayaApp : public CWinAppEx
{
public:
	Clab1_gembitskayaApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clab1_gembitskayaApp theApp;
