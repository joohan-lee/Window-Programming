// GraphBoard.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_6_mathGraphs.h"
#include "GraphBoard.h"


// GraphBoard

IMPLEMENT_DYNAMIC(GraphBoard, CStatic)

GraphBoard::GraphBoard()
{

}

GraphBoard::~GraphBoard()
{
}


BEGIN_MESSAGE_MAP(GraphBoard, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// GraphBoard 메시지 처리기입니다.




void GraphBoard::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	/*dc.MoveTo(0, 0);
	dc.LineTo(100, 100);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc); //이거 빼먹으면 아마 안그려질걸? memDC 생성

	CRect rcClip, rcClient;
	dc.GetClipBox(&rcClip); //GetClipBox는 다시 그려야 하는 영역을 구해 준다. 절약 정신.
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	memDC.SelectObject(&bitmap); //rcClient랑 똑같은 넓이의 비트맵 만들어서 그릴 준비

	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, 0);
	//요걸 호출해 주면! 상위 클래스의 WM_PAINT 처리 결과를 memDC에 담을 수 있다
	//즉 원본 컨트롤이 그려주고 있는 것들이 memDC에 그려진다


	//여기서 내맘대로 씹고 뜯고 맛보고 즐기고
	dc.MoveTo(rcClient.left, rcClient.top);
	dc.LineTo(rcClient.right / 2, rcClient.right / 2);

	dc.BitBlt(rcClip.left, rcClip.top, rcClip.Width(), rcClip.Height(), &memDC,
		rcClip.left, rcClip.top, SRCCOPY);
	//필요한 만큼(rcClip)만 복사해 주면 된다 

	memDC.DeleteDC();	   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
	*/				   // 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
}
