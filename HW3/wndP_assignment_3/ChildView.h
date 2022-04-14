
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include"time.h"

using namespace std;

typedef enum SCORE_TYPE { A=25, B=15, C=10, D=8, F=5,ABSENT=11 }SCORE_TYPE;


class Character {

public:
	CRect loc;
	void SetLocation(POINT p) {
		this->loc.SetRect(p.x - 10, p.y - 10, p.x + 10, p.y + 10);
	}
	void Move(int Arrow) {
		this->loc.OffsetRect(Arrow, 0);
	}
	void Draw(CDC* pDC) {
		CBrush brush(RGB(0, 0, 0));
		pDC->SelectObject(&brush);
		pDC->Ellipse(loc);

	}
};

class ScoreUnit {

public:
	SCORE_TYPE type;
	double score;
	CRect loc;
	void SetLocation(POINT p) {
		this->loc.SetRect(p.x - 15, p.y - 15, p.x + 15, p.y + 15);
	}
	void Drop() {
		this->loc.OffsetRect(0, this->type);
	}
	void Draw(CDC* pDC) {
		switch (type) {//������ �� type�� ���� A�� �� �׸���
		case A:
			pDC->Ellipse(loc);
			pDC->DrawText(_T("A"), loc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
			break;
		case B:
			pDC->Ellipse(loc);
			pDC->DrawText(_T("B"),loc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
			break;
		case C:
			pDC->Ellipse(loc);
			pDC->DrawText(_T("C"), loc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
			break;
		case D:
			pDC->Ellipse(loc);
			pDC->DrawText(_T("D"), &loc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
			break;
		case F:
			pDC->Ellipse(loc);
			pDC->DrawText(_T("F"), &loc, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
			break;
		case ABSENT:
			CBrush brush(RGB(0,152,0)); // �ʷϻ����� ĥ�ϱ�
			CBrush *pOldBrush = pDC->SelectObject(&brush);
			pDC->Ellipse(loc);
			pDC->SelectObject(pOldBrush);
			break;

		}
	}
	void CreateScoreUnit(int type) {
		switch (type) {
		case 0:
			this->score = 0.0;
			this->type = F;
			break;

		case 1:
			this->score = 1.0;
			this->type = D;
			break;

		case 2:
			this->score = 2.0;
			this->type = C;
			break;

		case 3:
			this->score = 3.0;
			this->type = B;
			break;

		case 4:
			this->score = 4.0;
			this->type = A;
			break;

		case 5:
			this->type = ABSENT;
			break;
		}
	}
	BOOL CheckTouch(CRect u) {//ĳ���Ͱ��� �������� ��Ҵ��� Ȯ��
		CRect check;
		if (check.IntersectRect(this->loc, u) == 1) return TRUE;
		else return FALSE;
	}
};

#define DROP_TIMER 0x1244
#define DROP_TIMER_CLOCK 150
#define MAKEUNIT_TIMER 0x1245
#define MAKEUNIT_TIMER_CLOCK 450
#define GAME_TIMER 0x1246
#define GAME_TIMER_CLOCK 30000
#define ELAPSE_TIMER 0x1247
#define ELAPSE_TIMER_CLOCK 100

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();
	
	Character c;
	vector<ScoreUnit> e_unit;

	void DrawScoreUnit(CDC* pDC);
	void DrawCharacter(CDC* pDC);
	void StartGame();
	void EndGame();
	void AddScoreUnit();
	void DrawInfo(CDC* pDC);
	void ElapsedTime(CDC* pDC);
// Ư���Դϴ�.
public:
	double score,avg;
	int numOfTouch;
	int absent;
	double playingTime;
	bool playing,checking_absent;
// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

