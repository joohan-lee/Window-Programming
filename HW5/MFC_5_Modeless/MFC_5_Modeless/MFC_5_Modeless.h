
// MFC_5_Modeless.h : MFC_5_Modeless ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_5_ModelessApp:
// �� Ŭ������ ������ ���ؼ��� MFC_5_Modeless.cpp�� �����Ͻʽÿ�.
//

class CMFC_5_ModelessApp : public CWinApp
{
public:
	CMFC_5_ModelessApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_5_ModelessApp theApp;
