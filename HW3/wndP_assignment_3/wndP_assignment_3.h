
// wndP_assignment_3.h : wndP_assignment_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CwndP_assignment_3App:
// �� Ŭ������ ������ ���ؼ��� wndP_assignment_3.cpp�� �����Ͻʽÿ�.
//

class CwndP_assignment_3App : public CWinApp
{
public:
	CwndP_assignment_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CwndP_assignment_3App theApp;
