
// MFC_6_mathGraphsView.h : CMFC_6_mathGraphsView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


class CMFC_6_mathGraphsView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMFC_6_mathGraphsView();
	DECLARE_DYNCREATE(CMFC_6_mathGraphsView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_6_MATHGRAPHS_FORM };
#endif

// Ư���Դϴ�.
public:
	CMFC_6_mathGraphsDoc* GetDocument() const;
	CString a, b, c;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMFC_6_mathGraphsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CStatic m_board1;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CComboBox m_typeComb;
	afx_msg void OnCbnSelchangeCombo1();
	CEdit m_editA;
	CEdit m_editB;
	CEdit m_editC;
	CStatic m_staticStrC;
	CSpinButtonCtrl m_spinC;
	CSpinButtonCtrl m_spinA;
	CSpinButtonCtrl m_spinB;
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	CStatic m_staticEquation;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

#ifndef _DEBUG  // MFC_6_mathGraphsView.cpp�� ����� ����
inline CMFC_6_mathGraphsDoc* CMFC_6_mathGraphsView::GetDocument() const
   { return reinterpret_cast<CMFC_6_mathGraphsDoc*>(m_pDocument); }
#endif

