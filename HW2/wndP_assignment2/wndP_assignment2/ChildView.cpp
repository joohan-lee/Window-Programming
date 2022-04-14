
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "wndP_assignment2.h"
#include "ChildView.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	posX = 0;
	posY = 0;
	count = 0;
	success = 0;
	fail = 0;
	elapsedTime = 0.0;
	start = clock();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
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
	//SetTimer(1, 3000, NULL);
	if (count < 5) {
		posX = rand() % 400;//사각형을 그릴 위치를 편의를 위해 넓지않은 범위에서 랜덤하게 설정.
		posY = rand() % 400;
		Invalidate(false);
		CPaintDC dc(this);
		dc.Rectangle(posX, posY, posX + 100, posY + 100);//사각형 그려짐
	}
	else
	{
		clock_t end=clock();//수행이 완료되었을 때 시간 측정.
		elapsedTime = (double)(end - start)/CLOCKS_PER_SEC;//수행 끝과 시작 간의 차를 통해 수행시간 측정.
		CString str;
		str.Format(_T("성공 : %d회, 실패 : %d회\n%d분 %d초\n다시하겠습니까?"), success, fail,(int)(elapsedTime/60),(int)elapsedTime-(int)(elapsedTime/60)*60);
		count = 0;//5번반복완료되었으므로 모든 멤버변수 초기화.
		success = 0; fail = 0;
		elapsedTime = 0.0;
		Invalidate(true);
		if (MessageBox(str, _T("종료메시지"), MB_ICONQUESTION | MB_YESNO) == IDNO) {//종료메시지 출력
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//프로그램 종료
													//종료;
		}
		start = clock();//다시 수행하므로 시작시간 측정.
	}
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	/*switch (nIDEvent) {
	case 1:
		posX = rand() % 300;
		posY = rand() % 300;
		Invalidate(false);
		CPaintDC dc(this);
		dc.Rectangle(posX, posY, posX + 100, posY + 100);

		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP2);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);
		//TRACE(_T("가로 = %d, 세로 = %d\n“), bmpinfo.bmWidth, bmpinfo.bmHeight); 

		// 메모리 DC를 만든 후 비트맵을 선택해 넣는다.
		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		// 비트맵을 화면에 출력한다.
		dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
			&dcmem, 0, 0, SRCCOPY);

	

		break;
	}
	CWnd::OnTimer(nIDEvent);*/
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	pointX = point.x;//마우스 위치 저장.
	pointY = point.y;

	Invalidate(false);

	CPaintDC dc(this);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);//50*50픽셀로 맞추어 만든 도장그림을 로드.
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	//TRACE(_T("가로 = %d, 세로 = %d\n“), bmpinfo.bmWidth, bmpinfo.bmHeight); 

	// 메모리 DC를 만든 후 비트맵을 선택해 넣는다.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// 비트맵을 화면에 출력한다.
	dc.BitBlt(pointX, pointY, bmpinfo.bmWidth, bmpinfo.bmHeight,
		&dcmem, 0, 0, SRCCOPY);//마우스위치에 도장 찍기.

	count++;
	Invalidate(false);
	if (posX <= pointX&&pointX <= posX + 50 && posY <= pointY&&pointY <= posY + 50)//도장이 사각형 내에 있는지확인.
	{
		success++;//안에 있으면 석세스 변수증가.
	}
	else
	{
		fail++;//없으면 페일변수 증가.
	}

	CWnd::OnLButtonDown(nFlags, point);
}
