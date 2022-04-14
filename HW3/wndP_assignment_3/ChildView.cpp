
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "wndP_assignment_3.h"
#include "ChildView.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()//������
{
	srand((unsigned)time(NULL));
	score = 0.0;
	avg = 0.0;
	absent = 0;
	numOfTouch = 0;
	playing = false;//ȭ�� ù ��½� ���������� �����Ƿ� false.
	checking_absent=false;//�Ἦ3ȸ�� �޽����ڽ� ����� ���� ��������ʵ����ϴ� ����.
	playingTime = 0.0;
}

void CChildView::DrawScoreUnit(CDC* pDC) {//���� ���� �׸���
	auto& e = e_unit;
	for (auto& elem : e) {
		elem.Draw(pDC);
	}
}
void CChildView::DrawCharacter(CDC* pDC) {//ĳ���� �׸���
	this->c.Draw(pDC);
}

void CChildView::DrawInfo(CDC* pDC) {//������ �׸���
	CRect info,r;//����������
	GetClientRect(&r);
	CRect character, a, b, c, d, f, abs;//�������� �� ��ġ
	int left = r.Width()-180;
	int top=r.Height()-300;
	info.SetRect(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10);
	//pDC->RoundRect(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10,r.Width()-30,r.Height()-300);
	pDC->Rectangle(r.Width() - 180, r.Height() - 300, r.Width() - 30, r.Height() - 10);
	pDC->DrawText(_T("����"), info, DT_TOP|DT_CENTER);
	//ĳ���� ������
	character.SetRect(left + 20, top + 30, left + 40, top + 50);
	CBrush brush(RGB(0, 0, 0));
	CBrush *pOldBrush = pDC->SelectObject(&brush);;
	pDC->Ellipse(character);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(left + 60, top + 30, CString("ĳ����"));

	//A�� ������
	a.SetRect(left + 20, top + 70, left + 40, top + 90);
	pDC->Ellipse(a);
	pDC->DrawText(_T("A"), a, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 70, CString("A ���"));

	//B�� ������
	b.SetRect(left + 20, top + 110, left + 40, top + 130);
	pDC->Ellipse(b);
	pDC->DrawText(_T("B"), b, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 110, CString("B ���"));

	//C�� ������
	c.SetRect(left + 20, top + 150, left + 40, top + 170);
	pDC->Ellipse(c);
	pDC->DrawText(_T("C"), c, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 150, CString("C ���"));

	//D�� ������
	d.SetRect(left + 20, top + 190, left + 40, top + 210);
	pDC->Ellipse(d);
	pDC->DrawText(_T("D"), d, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 190, CString("D ���"));

	//F�� ������
	f.SetRect(left + 20, top + 230, left + 40, top + 250);
	pDC->Ellipse(f);
	pDC->DrawText(_T("F"), f, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
	pDC->TextOutW(left + 60, top + 230, CString("F ���"));

	//�Ἦ ������
	abs.SetRect(left + 20, top + 265, left + 40, top + 285);
	CBrush brush_abs(RGB(0,152,0));
	CBrush *pOldBrush_abs = pDC->SelectObject(&brush_abs);
	pDC->Ellipse(abs);
	pDC->SelectObject(pOldBrush_abs);
	pDC->TextOutW(left + 60, top + 265, CString("�Ἦ"));

}



void CChildView::StartGame() {//30���� ���ӽ���
	SetTimer(ELAPSE_TIMER, ELAPSE_TIMER_CLOCK, NULL);//����ð�
	//startTime = CTime::GetCurrentTime();
	playing = true;
	//init timer
	SetTimer(DROP_TIMER, DROP_TIMER_CLOCK, NULL);//�� �������� Ÿ�̸�
	SetTimer(MAKEUNIT_TIMER, MAKEUNIT_TIMER_CLOCK, NULL);//�� ���� Ÿ�̸�
	SetTimer(GAME_TIMER, GAME_TIMER_CLOCK, NULL);//30�� ���� �ð� Ÿ�̸�

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

void CChildView::AddScoreUnit() {//�� ���� Ÿ�̸ӿ��� ȣ��Ǵ� �Լ�. �����ϰ� �� ���� ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	CDC* pDC = GetDC();
	CRect r, r1, r2;
	GetClientRect(&r);
	r1.SetRect(r.left, r.top, r.Width() * 4 / 5, r.bottom);
	r2.SetRect(r.Width() * 4 / 5, r.top, r.right, r.bottom);
	CDC memDC;//������۸�
	CBitmap* pOldBitmap, bitmap;
	memDC.CreateCompatibleDC(pDC);
	bitmap.CreateCompatibleBitmap(pDC, r1.Width(), r1.Height());
	pOldBitmap = (CBitmap*)memDC.SelectObject(&bitmap);
	memDC.PatBlt(0, 0, r1.Width(), r1.Height(), WHITENESS);


	//using memDC to draw
	this->DrawScoreUnit(&memDC);

	this->DrawCharacter(&memDC);

	memDC.MoveTo(r1.Width()-1, 0);
	memDC.LineTo(r1.Width()-1, r1.Height());//���������� ���� ���߱�
	CString str_time,str_score,str_absent;
	str_time.Format(_T("�ð� : %.1f��"),playingTime);
	str_score.Format(_T("���� : %.2f��"), avg);
	str_absent.Format(_T("�Ἦ : %dȸ"), absent);
	dc.TextOutW(r1.Width()+30, 50, str_time);//�ð����
	dc.TextOutW(r1.Width() + 30, 70, str_score);//�������
	dc.TextOutW(r1.Width() + 30, 90, str_absent);//�Ἦ���
	DrawInfo(pDC);

	dc.BitBlt(0, 0, r1.Width(), r1.Height(), &memDC, 0, 0, SRCCOPY);
	//free memory
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect r,r1;
	GetClientRect(&r);
	r1.SetRect(r.left,r.top, r.right*4/5, r.bottom);
	if (nIDEvent == ELAPSE_TIMER) {//0.1�ʸ��� Ÿ�̸�ȣ��,����ð� ����
		playingTime += 0.11;

		//if (playingTime > 30.0)
	}
	if (nIDEvent == DROP_TIMER) {
		//drop enemy unit
		auto& e = e_unit;
		for (vector<ScoreUnit>::iterator i = e.begin(); i != e.end();) {
			i->Drop();
			if (i->CheckTouch(c.loc) == TRUE) {
				if (i->type!=ABSENT) {//�����̸�
					score += i->score;
					numOfTouch++;
					avg = score / numOfTouch;
					i = e.erase(i);
				}
				else {//�Ἦ�̸�
					absent++;
					i = e.erase(i);
					if (absent == 3) {
						EndGame();
						checking_absent = true;
						CString str;
						str.Format(_T("�ٽ��ϰڽ��ϱ�?"));
						int replay = MessageBox(str, _T("����޽���"), MB_ICONQUESTION | MB_YESNO);
						if (replay == IDNO) {//����޽��� ���
							AfxGetMainWnd()->PostMessageW(WM_CLOSE);//���α׷� ����
							return;						//����;
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
		str.Format(_T("�ٽ��ϰڽ��ϱ�?"));
		int replay = MessageBox(str, _T("����޽���"), MB_ICONQUESTION | MB_YESNO);
		if (replay == IDNO) {//����޽��� ���
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//���α׷� ����
			return;						//����;
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CWnd::OnEraseBkgnd(pDC);
}
