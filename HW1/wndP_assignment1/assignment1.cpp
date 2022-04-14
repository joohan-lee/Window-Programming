#include <afxwin.h>
#include<string.h>

// 응용 프로그램 클래스를 선언한다.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// 메인 윈도우 클래스를 선언한다.
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

// 응용 프로그램 객체를 선언한다.
CHelloApp theApp;

// 응용 프로그램 클래스를 정의한다.
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->GetStyle();
	//m_pMainWnd *p_menu = this->GetSystemMenu(FALSE);

	//m_pMainWnd->(CS_NOCLOSE);
	return TRUE;
}

// 메인 윈도우 클래스를 정의한다.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("Assignment1"));
	// 현재 설정된 스타일을 얻는다.
	DWORD old_style = GetClassLong(m_hWnd, GCL_STYLE);

	// CS_NOCLOSE 속성을 추가하여 다시 설정한다.
	//SetClassLong(m_hWnd, GCL_STYLE, old_style | CS_NOCLOSE);//닫기버튼 비활성화
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	TCHAR *msg = _T("joohan");//화면에 내이름 출력.
	dc.TextOut(100, 100, msg, lstrlen(msg));
}


void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"), MB_ICONQUESTION | MB_YESNOCANCEL);
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	static char name[20];
	char me[20]="joohan";
	static int i = 0;//keydown발생시마다 i가 초기화되지 않도록 static사용.

	while (true) {
		if (nChar == me[i]-32) {//uint형과 char형 간의 차이.
			i++;
			break;
		}
		else {
			i=0;
			break;
		}
	}
	if (i == 6) {//내이름과 일치했을때 i가 6까지 증가되어 실행됨.
		if (MessageBox(_T("종료하시겠습니까?"), _T("종료메시지"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//프로그램 종료
			//종료;
		}
	}

}

void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) != SC_CLOSE)
	{
		//실행
	}
	else
		;//닫기 이벤트 무효화
}

// 메시지 맵을 선언한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()
