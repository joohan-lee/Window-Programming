
// ChildView.cpp : CChildView Ŭ������ ����
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
	//SetTimer(1, 3000, NULL);
	if (count < 5) {
		posX = rand() % 400;//�簢���� �׸� ��ġ�� ���Ǹ� ���� �������� �������� �����ϰ� ����.
		posY = rand() % 400;
		Invalidate(false);
		CPaintDC dc(this);
		dc.Rectangle(posX, posY, posX + 100, posY + 100);//�簢�� �׷���
	}
	else
	{
		clock_t end=clock();//������ �Ϸ�Ǿ��� �� �ð� ����.
		elapsedTime = (double)(end - start)/CLOCKS_PER_SEC;//���� ���� ���� ���� ���� ���� ����ð� ����.
		CString str;
		str.Format(_T("���� : %dȸ, ���� : %dȸ\n%d�� %d��\n�ٽ��ϰڽ��ϱ�?"), success, fail,(int)(elapsedTime/60),(int)elapsedTime-(int)(elapsedTime/60)*60);
		count = 0;//5���ݺ��Ϸ�Ǿ����Ƿ� ��� ������� �ʱ�ȭ.
		success = 0; fail = 0;
		elapsedTime = 0.0;
		Invalidate(true);
		if (MessageBox(str, _T("����޽���"), MB_ICONQUESTION | MB_YESNO) == IDNO) {//����޽��� ���
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//���α׷� ����
													//����;
		}
		start = clock();//�ٽ� �����ϹǷ� ���۽ð� ����.
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
		//TRACE(_T("���� = %d, ���� = %d\n��), bmpinfo.bmWidth, bmpinfo.bmHeight); 

		// �޸� DC�� ���� �� ��Ʈ���� ������ �ִ´�.
		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		// ��Ʈ���� ȭ�鿡 ����Ѵ�.
		dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight,
			&dcmem, 0, 0, SRCCOPY);

	

		break;
	}
	CWnd::OnTimer(nIDEvent);*/
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	pointX = point.x;//���콺 ��ġ ����.
	pointY = point.y;

	Invalidate(false);

	CPaintDC dc(this);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);//50*50�ȼ��� ���߾� ���� ����׸��� �ε�.
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	//TRACE(_T("���� = %d, ���� = %d\n��), bmpinfo.bmWidth, bmpinfo.bmHeight); 

	// �޸� DC�� ���� �� ��Ʈ���� ������ �ִ´�.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// ��Ʈ���� ȭ�鿡 ����Ѵ�.
	dc.BitBlt(pointX, pointY, bmpinfo.bmWidth, bmpinfo.bmHeight,
		&dcmem, 0, 0, SRCCOPY);//���콺��ġ�� ���� ���.

	count++;
	Invalidate(false);
	if (posX <= pointX&&pointX <= posX + 50 && posY <= pointY&&pointY <= posY + 50)//������ �簢�� ���� �ִ���Ȯ��.
	{
		success++;//�ȿ� ������ ������ ��������.
	}
	else
	{
		fail++;//������ ���Ϻ��� ����.
	}

	CWnd::OnLButtonDown(nFlags, point);
}
