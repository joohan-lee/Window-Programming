
// MFC_5_ModelessView.cpp : CMFC_5_ModelessView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMFC_5_ModelessView ����/�Ҹ�

CMFC_5_ModelessView::CMFC_5_ModelessView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_pDlg = NULL;

}

CMFC_5_ModelessView::~CMFC_5_ModelessView()
{
}

BOOL CMFC_5_ModelessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC_5_ModelessView �׸���

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
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFC_5_ModelessView ����

#ifdef _DEBUG
void CMFC_5_ModelessView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_5_ModelessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_5_ModelessDoc* CMFC_5_ModelessView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_5_ModelessDoc)));
	return (CMFC_5_ModelessDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_5_ModelessView �޽��� ó����


void CMFC_5_ModelessView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//if (m_pDlg != NULL) {
	//	m_pDlg->SetFocus();//�̹� ��µǾ�����.
	//}
	//else
	int ptx=point.x, pty=point.y;
	CString starting_str;
	
	m_pDlg = new ModelessDlg;
	
	m_pDlg->m_str_point = point;
	starting_str.Format(_T("������ġ : x= %d, y= %d"), ptx,pty);
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
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����

	if (ar.IsStoring())
	{	// storing code
		/*ar << m_color << m_font_size << m_point.x << m_point.y << m_text;
		//��,ũ��,x��ġ,y��ġ,���� ������ ����
		ar << m_lf.lfCharSet << m_lf.lfClipPrecision << m_lf.lfEscapement
			<< m_lf.lfFaceName << m_lf.lfHeight << m_lf.lfItalic
			<< m_lf.lfOrientation << m_lf.lfOutPrecision << m_lf.lfPitchAndFamily
			<< m_lf.lfQuality << m_lf.lfStrikeOut << m_lf.lfUnderline
			<< m_lf.lfWeight << m_lf.lfWidth;//��Ʈ ����
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
			<< m_lf.lfWeight << m_lf.lfWidth;//��Ʈ ����*/
	}
}
