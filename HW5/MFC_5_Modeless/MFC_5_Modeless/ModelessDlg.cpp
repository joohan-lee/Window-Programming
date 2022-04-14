// ModelessDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_5_Modeless.h"
#include "ModelessDlg.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include"MFC_5_ModelessView.h"
// ModelessDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(ModelessDlg, CDialog)

ModelessDlg::ModelessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MODELESSDLG, pParent)
{

}

ModelessDlg::~ModelessDlg()
{
}

void ModelessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDFONT, m_Btn_font);
	DDX_Control(pDX, IDSAVE, m_btn_save);
	DDX_Control(pDX, IDOPEN, m_btn_open);
}


BEGIN_MESSAGE_MAP(ModelessDlg, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, OnMyEditChange)
	ON_BN_CLICKED(IDOK, &ModelessDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDFONT, &ModelessDlg::OnBnClickedFont)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDSAVE, &ModelessDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDOPEN, &ModelessDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// ModelessDlg 메시지 처리기입니다.


void ModelessDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
}
void ModelessDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성

	UpdateData(true);
	//View 클래스 멤버 변수에 TextInput Dialog에 입력된 값을 대입

	if (!loading) {
		pView->m_str_text = m_dlg_str;
		pView->m_pt_text.x = m_str_point.x;
		pView->m_pt_text.y = m_str_point.y;
		pView->m_color_text = m_dlg_color;
		pView->m_fsize_text = m_dlg_fsize;
		pView->m_lf_text = m_dlg_lf;
	}
	UpdateData(false);

	//InfoText infotext;
	if (!storing) {
		pView->e_unit.back().m_color = m_dlg_color;
		pView->e_unit.back().m_font_size = m_dlg_fsize;
		pView->e_unit.back().m_lf = m_dlg_lf;
		pView->e_unit.back().m_point.x = m_str_point.x;
		pView->e_unit.back().m_point.y = m_str_point.y;
		pView->e_unit.back().m_text = m_dlg_str;
	}
	//pView->e_unit.push_back(infotext);

	pView->Invalidate();

	storing = loading = false;
	DestroyWindow();//생성한 자식창 확인 누르면 소멸. 재생성 불가.
					//CDialog::OnOK();주석표시 꼭해야함
}

void ModelessDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	DestroyWindow();//X를 눌러 창 닫을시에도 소멸시킴
	//CDialog::OnCancel();주석표시 꼭해야함
}

void ModelessDlg::OnSetFont(CFont* pFont)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialog::OnSetFont(pFont);
}


BOOL ModelessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString m_starting_point;

	SetDlgItemText(IDC_STATIC, point_str);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void ModelessDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDialog::PostNcDestroy();

	ModelessDlg *pMainWnd = (ModelessDlg *)AfxGetMainWnd();
	//pMainWnd->m_pDlg = NULL;
	delete this;
}


void ModelessDlg::OnMyEditChange() {

	GetDlgItemText(IDC_EDIT1, m_dlg_str);//적히는 텍스트를 얻어서 View로 보내주어 출력.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성

	UpdateData(true);
	//View 클래스 멤버 변수에 TextInput Dialog에 입력된 값을 대입

	pView->m_str_text = m_dlg_str;
	pView->m_pt_text.x = m_str_point.x;
	pView->m_pt_text.y = m_str_point.y;
	pView->m_color_text = m_dlg_color;
	pView->m_fsize_text = m_dlg_fsize;
	pView->m_lf_text = m_dlg_lf;
	UpdateData(false);

	pView->e_unit.back().m_color = m_dlg_color;
	pView->e_unit.back().m_font_size = m_dlg_fsize;
	pView->e_unit.back().m_lf = m_dlg_lf;
	pView->e_unit.back().m_point.x = m_str_point.x;
	pView->e_unit.back().m_point.y = m_str_point.y;
	pView->e_unit.back().m_text = m_dlg_str;

	pView->Invalidate();
}




void ModelessDlg::OnBnClickedFont()
{
	//HFONT hFont, OldFont;
	CFontDialog font_dlg;
	int result = font_dlg.DoModal();
	
	if (result == IDOK) {//현재 다이얼로그의 폰트정보를 업데이트한다.
		//선택된 색상을 알아낸다.
		COLORREF color = font_dlg.GetColor();
		m_dlg_color = color;

		//선택된 폰트를 알아낸다.
		LOGFONT lf;
		font_dlg.GetCurrentFont(&lf);
		m_dlg_lf = lf;
		m_dlg_fsize = font_dlg.GetSize();

		
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


HBRUSH ModelessDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_EDIT) {
		pDC->SetTextColor(m_dlg_color); 
		m_dlg_font.CreateFontIndirectW(&m_dlg_lf);
		pDC->SelectObject(&m_dlg_font);
		m_dlg_font.DeleteObject();
	}
	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void ModelessDlg::OnBnClickedSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//view클래스의 벡터를 가져와서 file열어서 저장하기.
	//infotext클래스 반복적으로 serialize하여 멤버변수들 저장.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성
	CFile file;
	CFileException e_file;

	if (!file.Open(_T("C:/download/mytest.dat")
		, CFile::modeWrite | CFile::modeCreate, &e_file))
	{
		e_file.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::store);

	this->Serialize(ar);

	ar.Close();
	file.Close();
	/*auto& e = pView->e_unit;
	for (vector<InfoText>::iterator i = e.begin(); i != e.end();) {
		i->Serialize(ar);
		i++;
	}*/
}

void ModelessDlg::OnBnClickedOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//file에서 클래스들 serialize로 멤버변수들 가져와서 view벡터에 하나씩 저장.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성
	CFile file;
	CFileException e_file;

	if (!file.Open(_T("C:/download/mytest.dat")
		, CFile::modeRead, &e_file))
	{
		e_file.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::load);

	
	
	this->Serialize(ar);
	
	ar.Close();
	file.Close();
}

void ModelessDlg::Serialize(CArchive& ar)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame 객체를 가르키는 변수 pFrame 생성

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View 객체를 가르키는 변수 pView 생성

	if (ar.IsStoring())
	{	// storing code
		storing = true;
		int totalSize = pView->e_unit.size();
		ar << totalSize;//문자열의 개수 저장.
		//for (; totalSize > 0; totalSize--) {
			//벡터 iterator를 통해 저장
		//}
		auto& e = pView->e_unit;
		for (vector<InfoText>::iterator i = e.begin(); i != e.end();) {
			ar << i->m_color << i->m_font_size << i->m_point.x << i->m_point.y 
				<< i->m_text;
			//색,크기,x위치,y위치,내용 순으로 저장
			ar << i->m_lf.lfCharSet << i->m_lf.lfClipPrecision << i->m_lf.lfEscapement
				<< (CString)i->m_lf.lfFaceName << i->m_lf.lfHeight << i->m_lf.lfItalic
				<< i->m_lf.lfOrientation << i->m_lf.lfOutPrecision << i->m_lf.lfPitchAndFamily
				<< i->m_lf.lfQuality << i->m_lf.lfStrikeOut << i->m_lf.lfUnderline
				<< i->m_lf.lfWeight << i->m_lf.lfWidth;//폰트 저장
			i++;
		}
		AfxMessageBox(_T("저장완료"));
	}
	else
	{	// loading code
		loading = true;
		pView->e_unit.clear();//불러오기전에 벡터 지우기.
		int totalSize;
		ar >> totalSize;//전체 사이즈를 받는다.

		for (; totalSize > 0; totalSize--) {
			InfoText load;
			ar >> load.m_color >> load.m_font_size
				>> load.m_point.x >> load.m_point.y
				>> load.m_text;
			
			ar >> load.m_lf.lfCharSet >> load.m_lf.lfClipPrecision >> load.m_lf.lfEscapement 
				>> (CString)load.m_lf.lfFaceName >> load.m_lf.lfHeight >> load.m_lf.lfItalic
				>> load.m_lf.lfOrientation >> load.m_lf.lfOutPrecision >> load.m_lf.lfPitchAndFamily
				>> load.m_lf.lfQuality >> load.m_lf.lfStrikeOut >> load.m_lf.lfUnderline
				>> load.m_lf.lfWeight >> load.m_lf.lfWidth;//폰트 저장
			pView->e_unit.push_back(load);
		}
		AfxMessageBox(_T("로드완료"));

	}
}


