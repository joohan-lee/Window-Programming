
// MFC_4_paintView.cpp : CMFC_4_paintView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC_4_paint.h"
#endif

#include "MFC_4_paintDoc.h"
#include "MFC_4_paintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_4_paintView

IMPLEMENT_DYNCREATE(CMFC_4_paintView, CView)

BEGIN_MESSAGE_MAP(CMFC_4_paintView, CView)
	ON_COMMAND(ID_SLINE, &CMFC_4_paintView::OnSline)
	ON_UPDATE_COMMAND_UI(ID_SLINE, &CMFC_4_paintView::OnUpdateSline)
	ON_COMMAND(ID_POLYLINE, &CMFC_4_paintView::OnPolyline)
	ON_UPDATE_COMMAND_UI(ID_POLYLINE, &CMFC_4_paintView::OnUpdatePolyline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_RED, &CMFC_4_paintView::OnRed)
	ON_UPDATE_COMMAND_UI(ID_RED, &CMFC_4_paintView::OnUpdateRed)
	ON_COMMAND(ID_THICKNESS1, &CMFC_4_paintView::OnThickness1)
	ON_UPDATE_COMMAND_UI(ID_THICKNESS1, &CMFC_4_paintView::OnUpdateThickness1)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_RECTANGLE, &CMFC_4_paintView::OnRectangle)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CMFC_4_paintView::OnUpdateRectangle)
	ON_COMMAND(ID_BLACK, &CMFC_4_paintView::OnBlack)
	ON_UPDATE_COMMAND_UI(ID_BLACK, &CMFC_4_paintView::OnUpdateBlack)
	ON_COMMAND(ID_CIRCLE, &CMFC_4_paintView::OnCircle)
	ON_UPDATE_COMMAND_UI(ID_CIRCLE, &CMFC_4_paintView::OnUpdateCircle)
	ON_COMMAND(ID_GREEN, &CMFC_4_paintView::OnGreen)
	ON_UPDATE_COMMAND_UI(ID_GREEN, &CMFC_4_paintView::OnUpdateGreen)
	ON_COMMAND(ID_BLUE, &CMFC_4_paintView::OnBlue)
	ON_UPDATE_COMMAND_UI(ID_BLUE, &CMFC_4_paintView::OnUpdateBlue)
	ON_COMMAND(ID_YELLOW, &CMFC_4_paintView::OnYellow)
	ON_UPDATE_COMMAND_UI(ID_YELLOW, &CMFC_4_paintView::OnUpdateYellow)
	ON_COMMAND(ID_PURPLE, &CMFC_4_paintView::OnPurple)
	ON_UPDATE_COMMAND_UI(ID_PURPLE, &CMFC_4_paintView::OnUpdatePurple)
	ON_COMMAND(ID_SKYBLUE, &CMFC_4_paintView::OnSkyblue)
	ON_UPDATE_COMMAND_UI(ID_SKYBLUE, &CMFC_4_paintView::OnUpdateSkyblue)
	ON_COMMAND(ID_THICKNESS3, &CMFC_4_paintView::OnThickness3)
	ON_UPDATE_COMMAND_UI(ID_THICKNESS3, &CMFC_4_paintView::OnUpdateThickness3)
	ON_COMMAND(ID_THICKNESS5, &CMFC_4_paintView::OnThickness5)
	ON_UPDATE_COMMAND_UI(ID_THICKNESS5, &CMFC_4_paintView::OnUpdateThickness5)
	ON_COMMAND(ID_TRIANGLE, &CMFC_4_paintView::OnTriangle)
	ON_UPDATE_COMMAND_UI(ID_TRIANGLE, &CMFC_4_paintView::OnUpdateTriangle)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FILE_SAVE, &CMFC_4_paintView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CMFC_4_paintView::OnFileOpen)
END_MESSAGE_MAP()

// CMFC_4_paintView ����/�Ҹ�

CMFC_4_paintView::CMFC_4_paintView()
{
	moving = false;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
}

CMFC_4_paintView::~CMFC_4_paintView()
{
}

BOOL CMFC_4_paintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}



// CMFC_4_paintView �׸���

void CMFC_4_paintView::OnDraw(CDC* pDC)
{
	CMFC_4_paintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	preview.MoveDraw(pDC);
	int num_of_painted;
	auto& e = e_fig;
	for (vector<Figure>::iterator i = e.begin(); i != e.end();) {
		//if (num_of_painted<=0&&loading) {
		//	loading = false;
		//	break;
		//}
		i->Draw(pDC);
		//if (e_fig.size() != 0)
		//	e_fig.back().Draw(pDC);
		i++;
		//num_of_loaded--;
	}
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}




// CMFC_4_paintView ����

#ifdef _DEBUG
void CMFC_4_paintView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_4_paintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_4_paintDoc* CMFC_4_paintView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_4_paintDoc)));
	return (CMFC_4_paintDoc*)m_pDocument;
}
#endif //_DEBUG



//�޽��� ó����

void CMFC_4_paintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	moving = true;
	//���� ����
	if (!polying&&m_btColorMode&&m_btFigureMode&&m_btThicknessMode) {
		if (m_btFigureMode == ID_POLYLINE)
			polying = true;
		Figure fig;//�׸��� ������ �� ���� ��ü ����.
		fig.m_ptStart = point;
		fig.m_figureMode = m_btFigureMode;//��ư ���¸� ��ü ���¿� ����.
		fig.m_colorMode = m_btColorMode;
		fig.m_thicknessMode = m_btThicknessMode;

		switch (fig.m_colorMode) {//��ü ���¿� ���� ���� �� ����.
		case ID_BLACK:
			fig.m_lineColor = RGB(0, 0, 0);
			break;
		case ID_RED:
			fig.m_lineColor = RGB(255, 0, 0);
			break;
		case ID_GREEN:
			fig.m_lineColor = RGB(0, 255, 0);
			break;
		case ID_BLUE:
			fig.m_lineColor = RGB(0, 0, 255);
			break;
		case ID_YELLOW:
			fig.m_lineColor = RGB(255, 255, 66);
			break;
		case ID_PURPLE:
			fig.m_lineColor = RGB(99, 00, 144);
			break;
		case ID_SKYBLUE:
			fig.m_lineColor = RGB(99, 255, 255);
			break;
		}

		switch (fig.m_thicknessMode) {//��ü ���¿� ���� �β� �� ����.
		case ID_THICKNESS1:
			fig.m_lineSize = 1;
			break;
		case ID_THICKNESS3:
			fig.m_lineSize = 3;
			break;
		case ID_THICKNESS5:
			fig.m_lineSize = 5;
			break;
		}

		e_fig.push_back(fig);//���� ���� �߰�.
	
	}
	//�̸����⸦ ���� ó��
	preview.m_ptStart = point;
	preview.m_figureMode = m_btFigureMode;//��ư ���¸� ��ü ���¿� ����.
	preview.m_colorMode = m_btColorMode;
	preview.m_thicknessMode = m_btThicknessMode;

	switch (preview.m_colorMode) {//��ü ���¿� ���� �� ����.
	case ID_BLACK:
		preview.m_lineColor = RGB(0, 0, 0);
		break;
	case ID_RED:
		preview.m_lineColor = RGB(255, 0, 0);
		break;
	case ID_GREEN:
		preview.m_lineColor = RGB(0, 255, 0);
		break;
	case ID_BLUE:
		preview.m_lineColor = RGB(0, 0, 255);
		break;
	case ID_YELLOW:
		preview.m_lineColor = RGB(255, 255, 66);
		break;
	case ID_PURPLE:
		preview.m_lineColor = RGB(99, 00, 144);
		break;
	case ID_SKYBLUE:
		preview.m_lineColor = RGB(99, 255, 255);
		break;
	}

	switch (preview.m_thicknessMode) {
	case ID_THICKNESS1:
		preview.m_lineSize = 1;
		break;
	case ID_THICKNESS3:
		preview.m_lineSize = 3;
		break;
	case ID_THICKNESS5:
		preview.m_lineSize = 5;
		break;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMFC_4_paintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_btFigureMode == ID_POLYLINE&&polying) {
		preview.m_ptStart = point;
		e_fig.back().m_ptEnd = point;
		e_fig.back().figPolyPt[idx_poly] = point;
		e_fig.back().figIdx_poly = idx_poly;
		idx_poly++;
		//m_polyPt[idx_poly].x = point.x;
		//m_polyPt[idx_poly].y = point.y;
		//e_fig.back().e_polyPoint.push_back(point);
		//e_fig.back().m_ptEnd = point;
		if (idx_poly > 1)
			Invalidate();
	}
	else {
		e_fig.back().m_ptEnd = point;
		moving = false;
		if(!loading)
			Invalidate();
	}

	CView::OnLButtonUp(nFlags, point);
}


void CMFC_4_paintView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (moving) {
		preview.m_ptEnd = point;
		Invalidate();
	}
	/*if(e_fig.size()!=0)
	e_fig.back().m_ptEnd = point;
	Invalidate();polyline�� ���*/
	CView::OnMouseMove(nFlags, point);
}








void CMFC_4_paintView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_btFigureMode == ID_POLYLINE&&polying) {
		polying = false;
		idx_poly = 0;
		moving = false;
	}
	if(polying==true)
		Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMFC_4_paintView::OnFileSave()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("c:/temp/figures.dat"), CFile::modeWrite | CFile::modeCreate, &e))
	{
		e.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::store);

	int pos_x_start;// = e_fig.back().m_ptStart.x;
	int pos_y_start;//������
	int pos_x_end;
	int pos_y_end;// = e_fig.back().m_ptEnd.y;//����
	int m_storingColor;//��
	int m_storingLSize;//�β�
	int m_storingFMode;//���
	CPoint m_poly_point;

	auto& ei = e_fig;
	for (vector<Figure>::iterator i = ei.begin(); i != ei.end();) {
		pos_x_start = i->m_ptStart.x;
		pos_y_start = i->m_ptStart.y;
		pos_x_end = i->m_ptEnd.x;
		pos_y_end = i->m_ptEnd.y;
		m_storingFMode = i->m_figureMode;
		m_storingColor = i->m_colorMode;
		m_storingLSize = i->m_lineSize;
		

		ar << pos_x_start << pos_y_start;//������
		ar << pos_x_end << pos_y_end;//����
		
		ar << m_storingColor;//��
		ar << m_storingLSize;//�β�
		ar << m_storingFMode;//���
		nFigureSave++;
		i++;
	}
	//file.Close();
	//ar << e_fig.size();
	AfxMessageBox(_T("Store completed"));

	
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}



void CMFC_4_paintView::OnFileOpen()
{
	
	CFile file;
	CFileException e;
	if (!file.Open(_T("c:/temp/figures.dat"), CFile::modeRead , &e))
	{///Users/jooha/Documents/Visual Studio 2015/Projects/MFC_4_paint/MFC_4_paint
		e.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::load);

	int pos_x_start;// = e_fig.back().m_ptStart.x;
	int pos_y_start;//������
	int pos_x_end;
	int pos_y_end;// = e_fig.back().m_ptEnd.y;//����
	int m_storingColor;//��
	int m_storingLSize;//�β�
	int m_storingFMode;//���


	auto& ei = e_fig;
	for (vector<Figure>::iterator i = ei.begin(); i != ei.end();) {
		if (num_of_loaded >= nFigureSave)
			break;
		ar >> pos_x_start >> pos_y_start;//������
		ar >> pos_x_end >> pos_y_end;//����
		ar >> m_storingColor;//��
		ar >> m_storingLSize;//�β�
		ar >> m_storingFMode;//���
		
		i->m_ptStart.x= pos_x_start;
		i->m_ptStart.y = pos_y_start;
		i->m_ptEnd.x = pos_x_end;
		i->m_ptEnd.y = pos_y_end;
		i->m_figureMode = m_storingFMode;
		i->m_colorMode = m_storingColor;
		i->m_lineSize = m_storingLSize;

		i++;
		num_of_loaded++;
	}
	
	while (e_fig.size() - num_of_loaded > 0)
		e_fig.pop_back();
	//file.Close();
	loading = true;
	Invalidate(true);
	//AfxMessageBox(_T("Load completed"));
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

// CMFC_4_paintView �޽��� ó����


/*--------------���� ó��---------------------*/

void CMFC_4_paintView::OnSline()
{
	m_btFigureMode = ID_SLINE;
	polying = false;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateSline(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btFigureMode == ID_SLINE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnPolyline()
{
	m_btFigureMode = ID_POLYLINE;
	//polying = true;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdatePolyline(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btFigureMode == ID_POLYLINE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}

void CMFC_4_paintView::OnRectangle()
{
	m_btFigureMode = ID_RECTANGLE;
	polying = false;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btFigureMode == ID_RECTANGLE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnCircle()
{
	m_btFigureMode = ID_CIRCLE;
	polying = false;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btFigureMode == ID_CIRCLE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}



void CMFC_4_paintView::OnTriangle()
{
	m_btFigureMode = ID_TRIANGLE;
	polying = false;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateTriangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btFigureMode == ID_TRIANGLE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}

/*-------------------------���� ó��---------------------*/


void CMFC_4_paintView::OnBlack()
{
	m_btColorMode = ID_BLACK;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_BLACK);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnRed()
{
	m_btColorMode = ID_RED;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_RED);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnGreen()
{
	m_btColorMode = ID_GREEN;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_GREEN);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnBlue()
{
	m_btColorMode = ID_BLUE;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_BLUE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnYellow()
{
	m_btColorMode = ID_YELLOW;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateYellow(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_YELLOW);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnPurple()
{
	m_btColorMode = ID_PURPLE;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdatePurple(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_PURPLE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnSkyblue()
{
	m_btColorMode = ID_SKYBLUE;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateSkyblue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btColorMode == ID_SKYBLUE);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


/*-------------------------�β� ó��---------------------*/


void CMFC_4_paintView::OnThickness1()
{
	m_btThicknessMode = ID_THICKNESS1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateThickness1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btThicknessMode == ID_THICKNESS1);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnThickness3()
{
	m_btThicknessMode = ID_THICKNESS3;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateThickness3(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btThicknessMode == ID_THICKNESS3);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnThickness5()
{
	m_btThicknessMode = ID_THICKNESS5;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_4_paintView::OnUpdateThickness5(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_btThicknessMode == ID_THICKNESS5);
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
}


