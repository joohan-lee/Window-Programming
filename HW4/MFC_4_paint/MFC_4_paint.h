
// MFC_4_paint.h : MFC_4_paint ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_4_paintApp:
// �� Ŭ������ ������ ���ؼ��� MFC_4_paint.cpp�� �����Ͻʽÿ�.
//

class CMFC_4_paintApp : public CWinApp
{
public:
	CMFC_4_paintApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_4_paintApp theApp;
