
// MFC_4_paintView.h : CMFC_4_paintView Ŭ������ �������̽�
//

#pragma once
#include<vector>
using namespace std;

#define nMaxPoints 1000

class Figure
{
public:
	CPoint m_ptStart;//���콺 ������ �����ϴ� ��
	CPoint m_ptEnd;//���콺 �� �� �� ��.
	
	int m_figureMode;//�׸��� �ִ� ���õ� ���� ���.
	int m_colorMode;//����
	int m_thicknessMode;//�β�

	COLORREF m_lineColor;//�� �÷�
	int m_lineSize;//�� �β�
	
	//vector<CPoint> e_polyPoint;
	CPoint figPolyPt[nMaxPoints];
	int figIdx_poly;

public:
	void Draw(CDC *pDC) {//���� �׸��� �Լ�
		CPen pen;
		pen.CreatePen(PS_SOLID, m_lineSize, m_lineColor);
		pDC->SelectObject(&pen);
		pDC->SelectStockObject(NULL_BRUSH);
		//auto& e = e_polyPoint;
		if (m_ptEnd.x != 0 && m_ptEnd.y != 0)
		{
			switch (m_figureMode) {
			case ID_SLINE:
				pDC->MoveTo(m_ptStart);
				pDC->LineTo(m_ptEnd);
				break;
			case ID_POLYLINE:
				pDC->Polyline(figPolyPt, figIdx_poly+1);
				/*if (e_polyPoint.size() >= 2) {
					for (vector<CPoint>::iterator i = e.begin(); i != e.end();) {
						pDC->MoveTo(*i);
						pDC->LineTo(*(++i));
						i--;
						//pDC->LineTo(e_polyPoint.at(e_polyPoint.size() - 1));
					}
				}*/
				break;
			case ID_RECTANGLE:
				pDC->Rectangle(m_ptStart.x,m_ptStart.y, m_ptEnd.x,m_ptEnd.y);
				break;
			case ID_CIRCLE:
				pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
				break;
			case ID_TRIANGLE:
				pDC->MoveTo((m_ptStart.x + m_ptEnd.x) / 2, m_ptStart.y);
				pDC->LineTo(m_ptStart.x, m_ptEnd.y);
				pDC->MoveTo(m_ptStart.x, m_ptEnd.y);
				pDC->LineTo(m_ptEnd);
				pDC->MoveTo(m_ptEnd);
				pDC->LineTo((m_ptStart.x + m_ptEnd.x) / 2, m_ptStart.y);
				break;
			}
		}
	}

	void MoveDraw(CDC *pDC) {
		CPen pen;
		pen.CreatePen(PS_SOLID, m_lineSize, m_lineColor);
		pDC->SelectObject(&pen);
		//CBrush brush(NULL_BRUSH);
		pDC->SelectStockObject(NULL_BRUSH);//�κ귯�� ����. �� ���ٷ� ����!!
		switch (m_figureMode) {
		case ID_SLINE:
			pDC->MoveTo(m_ptStart);
			pDC->LineTo(m_ptEnd);
			break;
		case ID_POLYLINE:
			pDC->MoveTo(m_ptStart);
			pDC->LineTo(m_ptEnd);
			break;
		case ID_RECTANGLE:
			pDC->Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
			break;
		case ID_CIRCLE:
			pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
			break;
		case ID_TRIANGLE:
			pDC->MoveTo((m_ptStart.x + m_ptEnd.x) / 2, m_ptStart.y);
			pDC->LineTo(m_ptStart.x, m_ptEnd.y);
			pDC->MoveTo(m_ptStart.x, m_ptEnd.y);
			pDC->LineTo(m_ptEnd);
			pDC->MoveTo(m_ptEnd);
			pDC->LineTo((m_ptStart.x + m_ptEnd.x) / 2, m_ptStart.y);
			break;
		}
	}
};

class CMFC_4_paintView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_4_paintView();
	DECLARE_DYNCREATE(CMFC_4_paintView)

// Ư���Դϴ�.
public:
	CMFC_4_paintDoc* GetDocument() const;
	vector<Figure> e_fig;//�׸� ������ ���������� �׷��ֱ� ���� Figure ����

	Figure preview;//�̸����⸦ ���� ��ü.

	int m_btFigureMode;//�������ִ� ������ư�� ���� ����.
	int m_btColorMode;//���� ������ �������ִ°�.
	int m_btThicknessMode;//��� ���Ⱑ �������ִ°�.

	bool moving;//�����̰� �ִ��� ����.

	CPoint m_polyPt[nMaxPoints];
	int idx_poly=0;//�������� �迭 �ε���.
	bool polying=false;//�����׸���������.

	int nFigureSave=0;//����Ǵ� �ǱԾ��
	int num_of_loaded = 0;//�ε� �� ��ü ��

	bool loading=false;//�ε忡 ���� Ondraw���� Ȯ��.
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMFC_4_paintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSline();
	afx_msg void OnUpdateSline(CCmdUI *pCmdUI);
	afx_msg void OnPolyline();
	afx_msg void OnUpdatePolyline(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRed();
	afx_msg void OnUpdateRed(CCmdUI *pCmdUI);
	afx_msg void OnThickness1();
	afx_msg void OnUpdateThickness1(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnBlack();
	afx_msg void OnUpdateBlack(CCmdUI *pCmdUI);
	afx_msg void OnCircle();
	afx_msg void OnUpdateCircle(CCmdUI *pCmdUI);
	afx_msg void OnGreen();
	afx_msg void OnUpdateGreen(CCmdUI *pCmdUI);
	afx_msg void OnBlue();
	afx_msg void OnUpdateBlue(CCmdUI *pCmdUI);
	afx_msg void OnYellow();
	afx_msg void OnUpdateYellow(CCmdUI *pCmdUI);
	afx_msg void OnPurple();
	afx_msg void OnUpdatePurple(CCmdUI *pCmdUI);
	afx_msg void OnSkyblue();
	afx_msg void OnUpdateSkyblue(CCmdUI *pCmdUI);
	afx_msg void OnThickness3();
	afx_msg void OnUpdateThickness3(CCmdUI *pCmdUI);
	afx_msg void OnThickness5();
	afx_msg void OnUpdateThickness5(CCmdUI *pCmdUI);
	afx_msg void OnTriangle();
	afx_msg void OnUpdateTriangle(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC_4_paintView.cpp�� ����� ����
inline CMFC_4_paintDoc* CMFC_4_paintView::GetDocument() const
   { return reinterpret_cast<CMFC_4_paintDoc*>(m_pDocument); }
#endif

