
// MFC_6_mathGraphs.h : MFC_6_mathGraphs ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_6_mathGraphsApp:
// �� Ŭ������ ������ ���ؼ��� MFC_6_mathGraphs.cpp�� �����Ͻʽÿ�.
//

class CMFC_6_mathGraphsApp : public CWinApp
{
public:
	CMFC_6_mathGraphsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_6_mathGraphsApp theApp;
