// GraphBoard.cpp : ���� �����Դϴ�.
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



// GraphBoard �޽��� ó�����Դϴ�.




void GraphBoard::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	/*dc.MoveTo(0, 0);
	dc.LineTo(100, 100);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc); //�̰� �������� �Ƹ� �ȱ׷�����? memDC ����

	CRect rcClip, rcClient;
	dc.GetClipBox(&rcClip); //GetClipBox�� �ٽ� �׷��� �ϴ� ������ ���� �ش�. ���� ����.
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	memDC.SelectObject(&bitmap); //rcClient�� �Ȱ��� ������ ��Ʈ�� ���� �׸� �غ�

	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, 0);
	//��� ȣ���� �ָ�! ���� Ŭ������ WM_PAINT ó�� ����� memDC�� ���� �� �ִ�
	//�� ���� ��Ʈ���� �׷��ְ� �ִ� �͵��� memDC�� �׷�����


	//���⼭ ������� �ð� ��� ������ ����
	dc.MoveTo(rcClient.left, rcClient.top);
	dc.LineTo(rcClient.right / 2, rcClient.right / 2);

	dc.BitBlt(rcClip.left, rcClip.top, rcClip.Width(), rcClip.Height(), &memDC,
		rcClip.left, rcClip.top, SRCCOPY);
	//�ʿ��� ��ŭ(rcClip)�� ������ �ָ� �ȴ� 

	memDC.DeleteDC();	   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	*/				   // �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
}
