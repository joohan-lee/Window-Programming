
// wndP_assignment2.h : wndP_assignment2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CwndP_assignment2App:
// �� Ŭ������ ������ ���ؼ��� wndP_assignment2.cpp�� �����Ͻʽÿ�.
//

class CwndP_assignment2App : public CWinApp
{
public:
	CwndP_assignment2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CwndP_assignment2App theApp;
