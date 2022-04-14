
// MFC_4_paintView.h : CMFC_4_paintView 클래스의 인터페이스
//

#pragma once
#include<vector>
using namespace std;

#define nMaxPoints 1000

class Figure
{
public:
	CPoint m_ptStart;//마우스 누르고 시작하는 점
	CPoint m_ptEnd;//마우스 뗄 떼 끝 점.
	
	int m_figureMode;//그리고 있는 선택된 도형 모드.
	int m_colorMode;//색깔
	int m_thicknessMode;//두께

	COLORREF m_lineColor;//펜 컬러
	int m_lineSize;//펜 두께
	
	//vector<CPoint> e_polyPoint;
	CPoint figPolyPt[nMaxPoints];
	int figIdx_poly;

public:
	void Draw(CDC *pDC) {//도형 그리는 함수
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
		pDC->SelectStockObject(NULL_BRUSH);//널브러쉬 적용. 단 한줄로 가능!!
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
protected: // serialization에서만 만들어집니다.
	CMFC_4_paintView();
	DECLARE_DYNCREATE(CMFC_4_paintView)

// 특성입니다.
public:
	CMFC_4_paintDoc* GetDocument() const;
	vector<Figure> e_fig;//그린 도형을 지속적으로 그려주기 위한 Figure 벡터

	Figure preview;//미리보기를 위한 객체.

	int m_btFigureMode;//눌려져있는 도형버튼에 대한 정보.
	int m_btColorMode;//무슨 색상이 눌러져있는가.
	int m_btThicknessMode;//어느 굵기가 눌러져있는가.

	bool moving;//움직이고 있는지 여부.

	CPoint m_polyPt[nMaxPoints];
	int idx_poly=0;//폴리라인 배열 인덱스.
	bool polying=false;//폴리그리는중인지.

	int nFigureSave=0;//저장되는 피규어수
	int num_of_loaded = 0;//로드 된 객체 수

	bool loading=false;//로드에 의한 Ondraw인지 확인.
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFC_4_paintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // MFC_4_paintView.cpp의 디버그 버전
inline CMFC_4_paintDoc* CMFC_4_paintView::GetDocument() const
   { return reinterpret_cast<CMFC_4_paintDoc*>(m_pDocument); }
#endif

