
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "wndP_assignment_3.h"
#include "ChildView.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()//생성자
{
	srand((unsigned)time(NULL));
	score = 0.0;
	avg = 0.0;
	absent = 0;
	numOfTouch = 0;
	playing = false;//화면 첫 출력시 게임중이지 않으므로 false.
	checking_absent=false;//결석3회라서 메시지박스 출력중 게임 실행되지않도록하는 변수.
	playingTime = 0.0;
}

void CChildView::DrawScoreUnit(CDC* pDC) {//점수 공들 그리기
	auto& e = e_unit;
	for (auto& elem : e) {
		elem.Draw(pDC);
	}
}
void CChildView::DrawCharacter(CDC* pDC) {//캐릭터 그리기
	this->c.Draw(pDC);
}

void CChildView::DrawInfo(CDC* pDC) {//정보란 그리기
	CRect info,r;//정보란생성
	GetClientRect(&r);
	CRect character, a, b, c, d, f, abs;//정보란의 공 위치
	int left = r.Width()-180;
	int top=r.Height()-300;
	info.SetRect(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10);
	//pDC->RoundRect(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10,r.Width()-30,r.Height()-300);
	pDC->Rectangle(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10);
	pDC->DrawText(_T("정보"), info, DT_TOP|DT_CENTER);
	//캐릭터 정보란
	character.SetRect(left + 20, top + 30, left + 40, top + 50);
	CBrush brush(RGB(0, 0, 0));
	CBrush *pOldBrush = pDC->SelectObject(&brush);;
	pDC->Ellipse(character);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(left + 60, top + 30, CString("캐릭터"));

	//A공 정보란
	a.SetRect(left + 20, top + 70, left + 40, top + 90);
	pDC->Ellipse(a);
	pDC->DrawText(_T("A"), a, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 70, CString("A 등급"));

	//B공 정보란
	b.SetRect(left + 20, top + 110, left + 40, top + 130);
	pDC->Ellipse(b);
	pDC->DrawText(_T("B"), b, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 110, CString("B 등급"));

	//C공 정보란
	c.SetRect(left + 20, top + 150, left + 40, top + 170);
	pDC->Ellipse(c);
	pDC->DrawText(_T("C"), c, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 150, CString("C 등급"));

	//D공 정보란
	d.SetRect(left + 20, top + 190, left + 40, top + 210);
	pDC->Ellipse(d);
	pDC->DrawText(_T("D"), d, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 190, CString("D 등급"));

	//F공 정보란
	f.SetRect(left + 20, top + 230, left + 40, top + 250);
	pDC->Ellipse(f);
	pDC->DrawText(_T("F"), f, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 230, CString("F 등급"));

	//결석 정보란
	abs.SetRect(left + 20, top + 265, left + 40, top + 285);
	CBrush brush_abs(RGB(0,152,0));
	CBrush *pOldBrush_abs = pDC->SelectObject(&brush_abs);
	pDC->Ellipse(abs);
	pDC->SelectObject(pOldBrush_abs);
	pDC->TextOutW(left + 60, top + 265, CString("결석"));

}



void CChildView::StartGame() {//30초의 게임시작
	SetTimer(ELAPSE_TIMER, ELAPSE_TIMER_CLOCK, NULL);//경과시간
	//startTime = CTime::GetCurrentTime();
	playing = true;
	//init timer
	SetTimer(DROP_TIMER, DROP_TIMER_CLOCK, NULL);//공 떨어지는 타이머
	SetTimer(MAKEUNIT_TIMER, MAKEUNIT_TIMER_CLOCK, NULL);//공 생성 타이머
	SetTimer(GAME_TIMER, GAME_TIMER_CLOCK, NULL);//30초 게임 시간 타이머

	//init usr unit
	CRect r;
	GetClientRect(&r);
	CPoint p;
	p.x = r.Width() / 2;
	p.y = r.Height() - 20;
	c.SetLocation(p);

	//init score
	score = 0.0;
	avg = 0.0;
	numOfTouch = 0;
	absent = 0;
	playingTime = 0.0;
	//startTime = CTime::GetCurrentTime();
}

void CChildView::EndGame() {
	KillTimer(DROP_TIMER);
	KillTimer(MAKEUNIT_TIMER);
	KillTimer(GAME_TIMER);
	KillTimer(ELAPSE_TIMER);
	e_unit.clear();
	playing = false;
}

void CChildView::AddScoreUnit() {//공 생성 타이머에서 호출되는 함수. 랜덤하게 공 유닛 생성
	ScoreUnit s;
	CRect r;
	GetClientRect(&r);
	POINT p;
	p.x = rand() % r.Width()-20;
	p.y = 0;

	int t = (rand() % 6);
	s.CreateScoreUnit(t);
	s.SetLocation(p);
	e_unit.push_back(s);
}


CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	if (!playing&&!checking_absent)
		StartGame();
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	CDC* pDC = GetDC();
	CRect r, r1, r2;
	GetClientRect(&r);
	r1.SetRect(r.left, r.top, r.Width() * 4 / 5, r.bottom);
	r2.SetRect(r.Width() * 4 / 5, r.top, r.right, r.bottom);
	CDC memDC;//더블버퍼링
	CBitmap* pOldBitmap, bitmap;
	memDC.CreateCompatibleDC(pDC);
	bitmap.CreateCompatibleBitmap(pDC, r1.Width(), r1.Height());
	pOldBitmap = (CBitmap*)memDC.SelectObject(&bitmap);
	memDC.PatBlt(0, 0, r1.Width(), r1.Height(), WHITENESS);


	//using memDC to draw
	this->DrawScoreUnit(&memDC);

	this->DrawCharacter(&memDC);

	memDC.MoveTo(r1.Width()-1, 0);
	memDC.LineTo(r1.Width()-1, r1.Height());//우측정보를 위한 선긋기
	CString str_time,str_score,str_absent;
	str_time.Format(_T("시간 : %.1f초"),playingTime);
	str_score.Format(_T("점수 : %.2f점"), avg);
	str_absent.Format(_T("결석 : %d회"), absent);
	dc.TextOutW(r1.Width()+30, 50, str_time);//시간출력
	dc.TextOutW(r1.Width() + 30, 70, str_score);//점수출력
	dc.TextOutW(r1.Width() + 30, 90, str_absent);//결석출력
	DrawInfo(pDC);

	dc.BitBlt(0, 0, r1.Width(), r1.Height(), &memDC, 0, 0, SRCCOPY);
	//free memory
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect r,r1;
	GetClientRect(&r);
	r1.SetRect(r.left,r.top, r.right*4/5, r.bottom);
	if (nIDEvent == ELAPSE_TIMER) {//0.1초마다 타이머호출,경과시간 더함
		playingTime += 0.11;

		//if (playingTime > 30.0)
	}
	if (nIDEvent == DROP_TIMER) {
		//drop enemy unit
		auto& e = e_unit;
		for (vector<ScoreUnit>::iterator i = e.begin(); i != e.end();) {
			i->Drop();
			if (i->CheckTouch(c.loc) == TRUE) {
				if (i->type!=ABSENT) {//점수이면
					score += i->score;
					numOfTouch++;
					avg = score / numOfTouch;
					i = e.erase(i);
				}
				else {//결석이면
					absent++;
					i = e.erase(i);
					if (absent == 3) {
						EndGame();
						checking_absent = true;
						CString str;
						str.Format(_T("다시하겠습니까?"));
						int replay = MessageBox(str, _T("종료메시지"), MB_ICONQUESTION | MB_YESNO);
						if (replay == IDNO) {//종료메시지 출력
							AfxGetMainWnd()->PostMessageW(WM_CLOSE);//프로그램 종료
							return;						//종료;
						}
						else if (replay == IDYES) {
							checking_absent = false;
							StartGame();
							return;
						}
					}
					
				}
			}
			else if (i->loc.CenterPoint().y > r1.Width()) i = e.erase(i);
			else ++i;
			this->Invalidate(false);
		}
	}
	if (nIDEvent == MAKEUNIT_TIMER) {
		//make enemy unit
		AddScoreUnit();
		//this->Invalidate();

	}
	if (nIDEvent == GAME_TIMER) {
		EndGame();
		checking_absent = true;
		CString str;
		str.Format(_T("다시하겠습니까?"));
		int replay = MessageBox(str, _T("종료메시지"), MB_ICONQUESTION | MB_YESNO);
		if (replay == IDNO) {//종료메시지 출력
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//프로그램 종료
			return;						//종료;
		}
		else if (replay == IDYES) {
			checking_absent = false;
			StartGame();
			return;
		}
	}

	CWnd::OnTimer(nIDEvent);
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect r;
	GetClientRect(&r);
	switch (nChar) {
	case VK_LEFT:
		if(c.loc.left>10)
			c.Move(-10);
		break;
	case VK_RIGHT:
		if (c.loc.right < r.Width()*4/5-10)
			c.Move(10);
		break;
	case 'A':
		if (c.loc.left>10)
			c.Move(-10);
		break;
	case 'D':
		if (c.loc.right < r.Width() * 4 / 5 - 10)
			c.Move(10);
		break;
	}

	this->Invalidate();

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CWnd::OnEraseBkgnd(pDC);
}
