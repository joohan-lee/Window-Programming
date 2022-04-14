
// MFC_6_mathGraphsView.cpp : CMFC_6_mathGraphsView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_6_mathGraphs.h"
#endif

#include "MFC_6_mathGraphsDoc.h"
#include "MFC_6_mathGraphsView.h"
#include <cmath>
#define _USE_MATH_DEFINES//파이값이용

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14

// CMFC_6_mathGraphsView

IMPLEMENT_DYNCREATE(CMFC_6_mathGraphsView, CFormView)

BEGIN_MESSAGE_MAP(CMFC_6_mathGraphsView, CFormView)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
ON_CBN_SELCHANGE(IDC_COMBO1, &CMFC_6_mathGraphsView::OnCbnSelchangeCombo1)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMFC_6_mathGraphsView::OnDeltaposSpin1)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMFC_6_mathGraphsView::OnDeltaposSpin2)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CMFC_6_mathGraphsView::OnDeltaposSpin3)
ON_EN_CHANGE(IDC_EDIT1, &CMFC_6_mathGraphsView::OnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT2, &CMFC_6_mathGraphsView::OnChangeEdit2)
ON_EN_CHANGE(IDC_EDIT3, &CMFC_6_mathGraphsView::OnChangeEdit3)
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CMFC_6_mathGraphsView 생성/소멸

CMFC_6_mathGraphsView::CMFC_6_mathGraphsView()
	: CFormView(IDD_MFC_6_MATHGRAPHS_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC_6_mathGraphsView::~CMFC_6_mathGraphsView()
{
}

void CMFC_6_mathGraphsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BOARD1, m_board1);
	DDX_Control(pDX, IDC_COMBO1, m_typeComb);
	DDX_Control(pDX, IDC_EDIT1, m_editA);
	DDX_Control(pDX, IDC_EDIT2, m_editB);
	DDX_Control(pDX, IDC_EDIT3, m_editC);
	DDX_Control(pDX, IDC_STRC, m_staticStrC);
	DDX_Control(pDX, IDC_SPIN3, m_spinC);
	DDX_Control(pDX, IDC_SPIN1, m_spinA);
	DDX_Control(pDX, IDC_SPIN2, m_spinB);
	DDX_Control(pDX, IDC_EQUATION, m_staticEquation);
}

BOOL CMFC_6_mathGraphsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFC_6_mathGraphsView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	//picture control처리
	m_board1.MoveWindow(10, 10, 364, 364);

	//static text처리
	m_staticEquation.SetWindowText(_T("ax^2+bx+c"));

	//콤보박스 처리
	m_typeComb.AddString(_T("2차 함수"));
	m_typeComb.AddString(_T("로그 함수"));
	m_typeComb.AddString(_T("sin함수"));
	m_typeComb.AddString(_T("cos함수"));
	m_typeComb.AddString(_T("tan함수"));
	m_typeComb.AddString(_T("원 그래프"));
	m_typeComb.AddString(_T("지수 함수"));
	m_typeComb.SetCurSel(0);
	
	//스핀컨트롤 처리
	m_spinA.SetRange(-1000, 1000);
	m_spinB.SetRange(-1000, 1000);
	m_spinC.SetRange(-1000, 1000);
	UDACCEL accels[] = { { 0,-1 } }; //increment
	//m_spinA.SetAccel(1, accels);

}


// CMFC_6_mathGraphsView 진단

#ifdef _DEBUG
void CMFC_6_mathGraphsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC_6_mathGraphsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC_6_mathGraphsDoc* CMFC_6_mathGraphsView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_6_mathGraphsDoc)));
	return (CMFC_6_mathGraphsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_6_mathGraphsView 메시지 처리기


void CMFC_6_mathGraphsView::OnPaint()
{
	CPaintDC dc(this); // device context for painting	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CFormView::OnPaint()을(를) 호출하지 마십시오.

	//CDialogEx::OnPaint();
		CDC* p = m_board1.GetWindowDC();
		CRect rect;
		m_board1.GetClientRect(&rect);//360 360
		
		CBrush brush(RGB(255, 255, 255));
		CBrush *pOldBrush = p->SelectObject(&brush);
		p->SelectObject(&brush);
		p->Rectangle(rect);
		p->SelectObject(pOldBrush);

		p->MoveTo(0, rect.bottom / 2);
		p->LineTo(rect.right, rect.bottom / 2);
		p->MoveTo(rect.right / 2, 0);
		p->LineTo(rect.right / 2, rect.bottom);


		//CString str[11];//눈금자 숫자를 출력하기 위한 스트링.
		int idx = m_typeComb.GetCurSel();//선택된콤보박스

		if (idx != 1 &&idx!=2&&idx!=3 ) {//삼각함수가 아닐 때 눈금자.
			for (int j = 1; j < 12; j++) {
				//CString str;
				//str.Format(_T("%d"), rect.Width()*j / 8);
				p->MoveTo(rect.right*j/12, rect.bottom / 2 - 5);
				p->LineTo(rect.right*j/12, rect.bottom / 2 + 5);
			}
			p->SetBkMode(TRANSPARENT);
			p->TextOut(30, rect.bottom / 2 - 30, _T("-150"));
			p->TextOut(60, rect.bottom / 2 - 30, _T("-120"));
			p->TextOut(90, rect.bottom / 2 - 30, _T("-90"));
			p->TextOut(120, rect.bottom / 2 - 30, _T("-60"));
			p->TextOut(150, rect.bottom / 2 - 30, _T("-30"));
			p->TextOut(160, rect.bottom / 2 + 10, _T("0"));
			p->TextOut(210, rect.bottom / 2 - 30, _T("30"));
			p->TextOut(240, rect.bottom / 2 - 30, _T("60"));
			p->TextOut(270, rect.bottom / 2 - 30, _T("90"));
			p->TextOut(300, rect.bottom / 2 - 30, _T("120"));
			p->TextOut(330, rect.bottom / 2 - 30, _T("150"));

			for (int j = 1; j < 12; j++) {
				p->MoveTo(rect.right / 2 - 5, j * 30);
				p->LineTo(rect.right / 2 + 5, j * 30);
			}
			p->TextOut(rect.right / 2 + 10, 30, _T("150"));
			p->TextOut(rect.right / 2 + 10, 60, _T("120"));
			p->TextOut(rect.right / 2 + 10, 90, _T("90"));
			p->TextOut(rect.right / 2 + 10, 120, _T("60"));
			p->TextOut(rect.right / 2 + 10, 150, _T("30"));
			//p->TextOut(rect.right / 2 + 30, 180, _T("0"));
			p->TextOut(rect.right / 2 + 10, 210, _T("-30"));
			p->TextOut(rect.right / 2 + 10, 240, _T("-60"));
			p->TextOut(rect.right / 2 + 10, 270, _T("-90"));
			p->TextOut(rect.right / 2 + 10, 295, _T("-120"));
			p->TextOut(rect.right / 2 + 10, 320, _T("-150"));
		}
		else {//삼각함수일때 눈금자
			for (int j = 1; j < 10; j++) {
				p->MoveTo(j * 36, rect.bottom / 2 - 5);
				p->LineTo(j * 36, rect.bottom / 2 + 5);
			}
			p->SetBkMode(TRANSPARENT);
			p->TextOut(31, rect.bottom / 2 - 30, _T("-2π"));
			p->TextOut(65, rect.bottom / 2 + 10, _T("-3π/2"));
			p->TextOut(101, rect.bottom / 2 - 30, _T("-π"));
			p->TextOut(137, rect.bottom / 2 - 30, _T("-π/2"));
			p->TextOut(170, rect.bottom / 2 + 10, _T("0"));
			p->TextOut(210, rect.bottom / 2 + 10, _T("π/2"));
			p->TextOut(247, rect.bottom / 2 - 30, _T("π"));
			p->TextOut(282, rect.bottom / 2 + 10, _T("3π/2"));
			p->TextOut(318, rect.bottom / 2 - 30, _T("2π"));
			

			for (int j = 1; j < 9; j++) {
				p->MoveTo(rect.right / 2 - 5, rect.bottom*j/8);
				p->LineTo(rect.right / 2 + 5, rect.bottom*j/8);
			}
			p->TextOut(rect.right / 2 + 10,rect.bottom*1/8, _T("3"));
			p->TextOut(rect.right / 2 + 10, rect.bottom*2/8, _T("2"));
			p->TextOut(rect.right / 2 + 10, rect.bottom * 3 / 8, _T("1"));
			//p->TextOut(rect.right / 2 + 10, rect.bottom * 4 / 8, _T("0"));
			p->TextOut(rect.right / 2 + 10, rect.bottom * 5 / 8, _T("-1"));
			//p->TextOut(rect.right / 2 + 30, 180, _T("0"));
			p->TextOut(rect.right / 2 + 10, rect.bottom * 6 / 8, _T("-2"));
			p->TextOut(rect.right / 2 + 10, rect.bottom * 7 / 8, _T("-3"));
			
		}

	CArray<POINT, POINT&> array;//그래프 그리기위한 CArray
	const int nDeltaX = rect.right / 2;//x를 위한 중점위치
	const int nDeltaY = rect.bottom / 2;//y를 위한 중점위치

	switch (m_typeComb.GetCurSel()) {
	case 0://2차 함수일 때

		for (int i = 0; i < rect.right; i++) {

			POINT pt;
			pt.x = i;
			pt.y = (-1)*_ttoi(a)*(i-nDeltaX)*(i-nDeltaX)
				+(-1)*_ttoi(b)*(i-nDeltaX)
				+(-1)*_ttoi(c)+nDeltaY;
			
			array.Add(pt);
		}

		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 1://cos함수 일때
		for (int i = 0; i < rect.right; i++) {
			POINT pt;
			pt.x = i;
			//pt.y = 10*((-1)*_ttoi(a)*sin((i-nDeltaX))) + (-1)*_ttoi(b)+nDeltaY;//a,b는 스핀컨트롤에서 음수로 옴
			//pt.y = i*i;
			pt.y = nDeltaY - (LONG)(::_ttoi(a)*cos((double)(i - nDeltaX) / (7 * PI)) * (double)nDeltaY / 4) + (-1)*_ttoi(b)*(double)nDeltaY/4;
			array.Add(pt);
		}

		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 2://sin함수일 때
		/*int w = rect.Width();
		int h = rect.Height();
		CString str;
		str.Format(_T("%d %d"), w, h);
		AfxMessageBox(str);*/
		//for()

		//CArray<POINT, POINT&> array;
		for (int i = 0; i < rect.right; i++){
			POINT pt;
			pt.x = i;
			//pt.y = 10*((-1)*_ttoi(a)*sin((i-nDeltaX))) + (-1)*_ttoi(b)+nDeltaY;//a,b는 스핀컨트롤에서 음수로 옴
			//pt.y = i*i;
			pt.y = nDeltaY - (LONG)(::_ttoi(a)*sin((double)(i - nDeltaX) / (7*PI)) * (double)nDeltaY/4)+(-1)*_ttoi(b)*(double)nDeltaY / 4;
			array.Add(pt);
		}

		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 3://tan함수일 때
		for (int i = 0; i < rect.right; i++) {
			POINT pt;
			pt.x = i;
			//pt.y = 10*((-1)*_ttoi(a)*sin((i-nDeltaX))) + (-1)*_ttoi(b)+nDeltaY;//a,b는 스핀컨트롤에서 음수로 옴
			//pt.y = i*i;
			pt.y = nDeltaY - (LONG)(::_ttoi(a)*tan((double)(i - nDeltaX) / (7 * PI)) * (double)nDeltaY / 4) + (-1)*_ttoi(b)*(double)nDeltaY / 4;
			array.Add(pt);
		}

		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 4://로그함수 일 때
		for (int i = (int)rect.right/2+1; i < rect.right; i++) {

			int A = (1)*_ttoi(a);
			int B = (1)*_ttoi(b);
			int C = (-1)*_ttoi(c);
			POINT pt;
			pt.x = i;
			pt.y = nDeltaY-A*(double)log(i - nDeltaX) / log(B) + C ;
			array.Add(pt);
		}
		
		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 5://원그래프일 때
		for (int i = 0; i < rect.right; i++) {
			int A = (-1)*_ttoi(a),B=(-1)*_ttoi(b), C = (-1)*_ttoi(c);
			POINT pt;
			pt.x = i;
			double val_sqrt= B*(C - (double)((i - nDeltaX)*(i - nDeltaX)) / (double)A);
			pt.y = sqrt(val_sqrt)+(double)nDeltaY;
			if (val_sqrt >= 0)//y가 실수일때만 그림.
				array.Add(pt);
		}
		for (int i = rect.right; i >= 0; i--) {
			int A = (-1)*_ttoi(a), B = (-1)*_ttoi(b), C = (-1)*_ttoi(c);
			POINT pt;
			pt.x = i;
			double val_sqrt = B*(C - (double)(i - nDeltaX)*(i - nDeltaX) / (double)A);
			pt.y = -sqrt(val_sqrt)+(double)nDeltaY;
			if (val_sqrt >= 0)
				array.Add(pt);
		}
		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();
		break;
	case 6://지수함수일 때
		for (int i = 0; i < rect.right; i++) {

			POINT pt;
			pt.x = i;
			pt.y = (-1)*_ttoi(a)*exp((double)(i - nDeltaX)/16)*(double)nDeltaY/8 + 
				(-1)*_ttoi(b)+nDeltaY;
			array.Add(pt);
		}

		p->Polyline(array.GetData(), array.GetSize());
		array.RemoveAll();

		break;
		m_board1.ReleaseDC(p);
	}
}


//void CMFC_6_mathGraphsView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CDC* p = m_board1.GetWindowDC();
//	m_board1.Invalidate(true);
//
//	m_board1.ReleaseDC(p);
//	CFormView::OnLButtonDown(nFlags, point);
//}


void CMFC_6_mathGraphsView::OnCbnSelchangeCombo1()
{
	int index = m_typeComb.GetCurSel();
	switch (index) {
	case 0://2차함수일때
		//a,b,c값 받아서 그리기.
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("ax^2+bx+c"));
		m_editC.ShowWindow(SW_SHOW);
		m_staticStrC.ShowWindow(SW_SHOW);
		m_spinC.ShowWindow(SW_SHOW);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		m_editC.GetWindowText(c);
		Invalidate();
		break;
	case 1://cos함수일때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("acos(x)+b"));
		m_editC.ShowWindow(SW_HIDE);
		m_staticStrC.ShowWindow(SW_HIDE);
		m_spinC.ShowWindow(SW_HIDE);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		Invalidate();
		break;
	case 2://sin함수일때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("asin(x)+b"));
		m_editC.ShowWindow(SW_HIDE);
		m_staticStrC.ShowWindow(SW_HIDE);
		m_spinC.ShowWindow(SW_HIDE);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		Invalidate(); 
		break;
	case 3://tan함수일때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("atan(x)+b"));
		m_editC.ShowWindow(SW_HIDE);
		m_staticStrC.ShowWindow(SW_HIDE);
		m_spinC.ShowWindow(SW_HIDE);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		Invalidate(); 
		break;
	case 4://로그함수일때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("a(logx/logb)+c"));
		m_editC.ShowWindow(SW_SHOW);
		m_staticStrC.ShowWindow(SW_SHOW);
		m_spinC.ShowWindow(SW_SHOW);
		//m_editA.GetWindowText(a);
		//m_editB.GetWindowText(b);
		//m_editC.GetWindowText(c);
		Invalidate();
		break;
	case 5://원그래프일 때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("x^2/a + y^2/b=c"));
		m_editC.ShowWindow(SW_SHOW);
		m_staticStrC.ShowWindow(SW_SHOW);
		m_spinC.ShowWindow(SW_SHOW);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		m_editC.GetWindowText(c);
		Invalidate();
		break;
	case 6://지수함수일 때
		Invalidate(true);
		SetDlgItemText(IDC_EQUATION, _T("ae^x+b"));
		m_editC.ShowWindow(SW_HIDE);
		m_staticStrC.ShowWindow(SW_HIDE);
		m_spinC.ShowWindow(SW_HIDE);
		m_editA.GetWindowText(a);
		m_editB.GetWindowText(b);
		Invalidate();
		break;
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_6_mathGraphsView::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
	
	//m_editA.GetWindowText(a);
	//Invalidate();
}//이렇게하면 에딧컨트롤상의 숫자는 이미 바뀌었는데 그 전 숫자기준으로됨.


void CMFC_6_mathGraphsView::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	//m_editB.GetWindowText(b);
	//Invalidate();
}


void CMFC_6_mathGraphsView::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	//m_editC.GetWindowText(c);
	//Invalidate();
}


void CMFC_6_mathGraphsView::OnChangeEdit1()
{//에딧 박스의 텍스트가 변경된 후 보내짐.
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	GetDlgItemText(IDC_EDIT1,a);
	Invalidate();
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_6_mathGraphsView::OnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	GetDlgItemText(IDC_EDIT2, b);
	Invalidate();

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_6_mathGraphsView::OnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	GetDlgItemText(IDC_EDIT3, c);
	Invalidate();

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


HBRUSH CMFC_6_mathGraphsView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_BOARD1) {
		pDC->SetBkColor(RGB(255, 255, 255));
		pDC->SelectStockObject(NULL_BRUSH);
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
