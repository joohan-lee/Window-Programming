
// MFC_5_ModelessView.cpp : CMFC_5_ModelessView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_5_Modeless.h"
#endif

#include "MFC_5_ModelessDoc.h"
#include "MFC_5_ModelessView.h"
#include"MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_5_ModelessView

IMPLEMENT_DYNCREATE(CMFC_5_ModelessView, CView)

BEGIN_MESSAGE_MAP(CMFC_5_ModelessView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_5_ModelessView 생성/소멸

CMFC_5_ModelessView::CMFC_5_ModelessView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_pDlg = NULL;

}

CMFC_5_ModelessView::~CMFC_5_ModelessView()
{
}

BOOL CMFC_5_ModelessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC_5_ModelessView 그리기

void CMFC_5_ModelessView::OnDraw(CDC* pDC)
{
	CMFC_5_ModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	auto& e = e_unit;
	for (vector<InfoText>::iterator i = e.begin(); i != e.end();) {
		pDC->SetTextColor(i->m_color);
		CFont font;
		font.CreateFontIndirectW(&i->m_lf);
		pDC->SelectObject(&font);
		pDC->TextOut(i->m_point.x, i->m_point.y, 
			i->m_text, i->m_text.GetLength());
		font.DeleteObject();
		i++;
	}
	pDC->SetTextColor(m_color_text);
	CFont font;
	font.CreateFontIndirectW(&m_lf_text);
	pDC->SelectObject(&font);
	pDC->TextOut(m_pt_text.x, m_pt_text.y,
		m_str_text, m_str_text.GetLength());
	font.DeleteObject();
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFC_5_ModelessView 진단

#ifdef _DEBUG
void CMFC_5_ModelessView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_5_ModelessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_5_ModelessDoc* CMFC_5_ModelessView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_5_ModelessDoc)));
	return (CMFC_5_ModelessDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_5_ModelessView 메시지 처리기


void CMFC_5_ModelessView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//if (m_pDlg != NULL) {
	//	m_pDlg->SetFocus();//이미 출력되어있음.
	//}
	//else
	int ptx=point.x, pty=point.y;
	CString starting_str;
	
	m_pDlg = new ModelessDlg;
	
	m_pDlg->m_str_point = point;
	starting_str.Format(_T("시작위치 : x= %d, y= %d"), ptx,pty);
	m_pDlg->point_str = starting_str;

	m_pDlg->Create(IDD_MODELESSDLG, this);
	m_pDlg->ShowWindow(SW_SHOW);

	InfoText infotext;
	e_unit.push_back(infotext);



	CView::OnLButtonDown(nFlags, point);
}


void InfoText::Serialize(CArchive& ar)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성

	if (ar.IsStoring())
	{	// storing code
		/*ar << m_color << m_font_size << m_point.x << m_point.y << m_text;
		//색,크기,x위치,y위치,내용 순으로 저장
		ar << m_lf.lfCharSet << m_lf.lfClipPrecision << m_lf.lfEscapement
			<< m_lf.lfFaceName << m_lf.lfHeight << m_lf.lfItalic
			<< m_lf.lfOrientation << m_lf.lfOutPrecision << m_lf.lfPitchAndFamily
			<< m_lf.lfQuality << m_lf.lfStrikeOut << m_lf.lfUnderline
			<< m_lf.lfWeight << m_lf.lfWidth;//폰트 저장
			*/
	}
	else
	{	// loading code
		/*
		ar >> m_color >> m_font_size >> m_point.x >> m_point.y >> m_text;
		ar << m_lf.lfCharSet << m_lf.lfClipPrecision << m_lf.lfEscapement
			<< m_lf.lfFaceName << m_lf.lfHeight << m_lf.lfItalic
			<< m_lf.lfOrientation << m_lf.lfOutPrecision << m_lf.lfPitchAndFamily
			<< m_lf.lfQuality << m_lf.lfStrikeOut << m_lf.lfUnderline
			<< m_lf.lfWeight << m_lf.lfWidth;//폰트 저장*/
	}
}
