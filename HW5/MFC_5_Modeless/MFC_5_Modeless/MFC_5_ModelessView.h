
// MFC_5_ModelessView.h : CMFC_5_ModelessView Ŭ������ �������̽�
//

#pragma once
#include<vector>
#include"MFC_5_Modeless.h"
#include"ModelessDlg.h"
#include"MFC_5_ModelessDoc.h"
using namespace std;


class InfoText{//���ͷ� ����� ������ �����ϰ� �׸��� �ϱ����� ����� Ŭ����
//CObject�� ����ϸ� �� ���Ϳ� ���Խ� ������ �Լ��� �����Ͽ��ٰ� ����?
public:
	CString m_text;
	CPoint m_point;
	LOGFONT m_lf;//font ����
	COLORREF m_color;
	int m_font_size;
public:
	virtual void Serialize(CArchive& ar);
};

class CMFC_5_ModelessView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_5_ModelessView();
	DECLARE_DYNCREATE(CMFC_5_ModelessView)

// Ư���Դϴ�.
public:
	CMFC_5_ModelessDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	ModelessDlg* m_pDlg;//����
	vector<InfoText> e_unit;

	CString m_str_text;
	CPoint m_pt_text;
	LOGFONT m_lf_text;
	COLORREF m_color_text;
	int m_fsize_text;

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMFC_5_ModelessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_5_ModelessView.cpp�� ����� ����
inline CMFC_5_ModelessDoc* CMFC_5_ModelessView::GetDocument() const
   { return reinterpret_cast<CMFC_5_ModelessDoc*>(m_pDocument); }
#endif

