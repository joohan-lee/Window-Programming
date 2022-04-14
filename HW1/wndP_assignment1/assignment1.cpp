#include <afxwin.h>
#include<string.h>

// ���� ���α׷� Ŭ������ �����Ѵ�.
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// ���� ������ Ŭ������ �����Ѵ�.
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

// ���� ���α׷� ��ü�� �����Ѵ�.
CHelloApp theApp;

// ���� ���α׷� Ŭ������ �����Ѵ�.
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->GetStyle();
	//m_pMainWnd *p_menu = this->GetSystemMenu(FALSE);

	//m_pMainWnd->(CS_NOCLOSE);
	return TRUE;
}

// ���� ������ Ŭ������ �����Ѵ�.
CMainFrame::CMainFrame()
{
	Create(NULL, _T("Assignment1"));
	// ���� ������ ��Ÿ���� ��´�.
	DWORD old_style = GetClassLong(m_hWnd, GCL_STYLE);

	// CS_NOCLOSE �Ӽ��� �߰��Ͽ� �ٽ� �����Ѵ�.
	//SetClassLong(m_hWnd, GCL_STYLE, old_style | CS_NOCLOSE);//�ݱ��ư ��Ȱ��ȭ
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	TCHAR *msg = _T("joohan");//ȭ�鿡 ���̸� ���.
	dc.TextOut(100, 100, msg, lstrlen(msg));
}


void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"), MB_ICONQUESTION | MB_YESNOCANCEL);
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	static char name[20];
	char me[20]="joohan";
	static int i = 0;//keydown�߻��ø��� i�� �ʱ�ȭ���� �ʵ��� static���.

	while (true) {
		if (nChar == me[i]-32) {//uint���� char�� ���� ����.
			i++;
			break;
		}
		else {
			i=0;
			break;
		}
	}
	if (i == 6) {//���̸��� ��ġ������ i�� 6���� �����Ǿ� �����.
		if (MessageBox(_T("�����Ͻðڽ��ϱ�?"), _T("����޽���"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);//���α׷� ����
			//����;
		}
	}

}

void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) != SC_CLOSE)
	{
		//����
	}
	else
		;//�ݱ� �̺�Ʈ ��ȿȭ
}

// �޽��� ���� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()
