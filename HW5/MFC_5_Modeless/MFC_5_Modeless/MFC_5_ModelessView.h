
// MFC_5_ModelessView.h : CMFC_5_ModelessView 클래스의 인터페이스
//

#pragma once
#include<vector>
#include"MFC_5_Modeless.h"
#include"ModelessDlg.h"
#include"MFC_5_ModelessDoc.h"
using namespace std;


class InfoText{//벡터로 만들어 정보를 저장하고 그리고 하기위해 사용할 클래스
//CObject를 상속하면 왜 벡터에 삽입시 삭제된 함수를 참조하였다고 하지?
public:
	CString m_text;
	CPoint m_point;
	LOGFONT m_lf;//font 정보
	COLORREF m_color;
	int m_font_size;
public:
	virtual void Serialize(CArchive& ar);
};

class CMFC_5_ModelessView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC_5_ModelessView();
	DECLARE_DYNCREATE(CMFC_5_ModelessView)

// 특성입니다.
public:
	CMFC_5_ModelessDoc* GetDocument() const;

// 작업입니다.
public:
	ModelessDlg* m_pDlg;//생성
	vector<InfoText> e_unit;

	CString m_str_text;
	CPoint m_pt_text;
	LOGFONT m_lf_text;
	COLORREF m_color_text;
	int m_fsize_text;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFC_5_ModelessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_5_ModelessView.cpp의 디버그 버전
inline CMFC_5_ModelessDoc* CMFC_5_ModelessView::GetDocument() const
   { return reinterpret_cast<CMFC_5_ModelessDoc*>(m_pDocument); }
#endif

