// ModelessDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_5_Modeless.h"
#include "ModelessDlg.h"
#include "afxdialogex.h"
#include"MainFrm.h"
#include"MFC_5_ModelessView.h"
// ModelessDlg ��ȭ �����Դϴ�.

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


// ModelessDlg �޽��� ó�����Դϴ�.


void ModelessDlg::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
}
void ModelessDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����

	UpdateData(true);
	//View Ŭ���� ��� ������ TextInput Dialog�� �Էµ� ���� ����

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
	DestroyWindow();//������ �ڽ�â Ȯ�� ������ �Ҹ�. ����� �Ұ�.
					//CDialog::OnOK();�ּ�ǥ�� ���ؾ���
}

void ModelessDlg::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	DestroyWindow();//X�� ���� â �����ÿ��� �Ҹ��Ŵ
	//CDialog::OnCancel();�ּ�ǥ�� ���ؾ���
}

void ModelessDlg::OnSetFont(CFont* pFont)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CDialog::OnSetFont(pFont);
}


BOOL ModelessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString m_starting_point;

	SetDlgItemText(IDC_STATIC, point_str);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void ModelessDlg::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CDialog::PostNcDestroy();

	ModelessDlg *pMainWnd = (ModelessDlg *)AfxGetMainWnd();
	//pMainWnd->m_pDlg = NULL;
	delete this;
}


void ModelessDlg::OnMyEditChange() {

	GetDlgItemText(IDC_EDIT1, m_dlg_str);//������ �ؽ�Ʈ�� �� View�� �����־� ���.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����

	UpdateData(true);
	//View Ŭ���� ��� ������ TextInput Dialog�� �Էµ� ���� ����

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
	
	if (result == IDOK) {//���� ���̾�α��� ��Ʈ������ ������Ʈ�Ѵ�.
		//���õ� ������ �˾Ƴ���.
		COLORREF color = font_dlg.GetColor();
		m_dlg_color = color;

		//���õ� ��Ʈ�� �˾Ƴ���.
		LOGFONT lf;
		font_dlg.GetCurrentFont(&lf);
		m_dlg_lf = lf;
		m_dlg_fsize = font_dlg.GetSize();

		
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


void ModelessDlg::OnBnClickedSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//viewŬ������ ���͸� �����ͼ� file��� �����ϱ�.
	//infotextŬ���� �ݺ������� serialize�Ͽ� ��������� ����.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//file���� Ŭ������ serialize�� ��������� �����ͼ� view���Ϳ� �ϳ��� ����.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����
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
	//MainFrame ��ü�� ����Ű�� ���� pFrame ����

	CMFC_5_ModelessView *pView = (CMFC_5_ModelessView*)pFrame->GetActiveView();
	//View ��ü�� ����Ű�� ���� pView ����

	if (ar.IsStoring())
	{	// storing code
		storing = true;
		int totalSize = pView->e_unit.size();
		ar << totalSize;//���ڿ��� ���� ����.
		//for (; totalSize > 0; totalSize--) {
			//���� iterator�� ���� ����
		//}
		auto& e = pView->e_unit;
		for (vector<InfoText>::iterator i = e.begin(); i != e.end();) {
			ar << i->m_color << i->m_font_size << i->m_point.x << i->m_point.y 
				<< i->m_text;
			//��,ũ��,x��ġ,y��ġ,���� ������ ����
			ar << i->m_lf.lfCharSet << i->m_lf.lfClipPrecision << i->m_lf.lfEscapement
				<< (CString)i->m_lf.lfFaceName << i->m_lf.lfHeight << i->m_lf.lfItalic
				<< i->m_lf.lfOrientation << i->m_lf.lfOutPrecision << i->m_lf.lfPitchAndFamily
				<< i->m_lf.lfQuality << i->m_lf.lfStrikeOut << i->m_lf.lfUnderline
				<< i->m_lf.lfWeight << i->m_lf.lfWidth;//��Ʈ ����
			i++;
		}
		AfxMessageBox(_T("����Ϸ�"));
	}
	else
	{	// loading code
		loading = true;
		pView->e_unit.clear();//�ҷ��������� ���� �����.
		int totalSize;
		ar >> totalSize;//��ü ����� �޴´�.

		for (; totalSize > 0; totalSize--) {
			InfoText load;
			ar >> load.m_color >> load.m_font_size
				>> load.m_point.x >> load.m_point.y
				>> load.m_text;
			
			ar >> load.m_lf.lfCharSet >> load.m_lf.lfClipPrecision >> load.m_lf.lfEscapement 
				>> (CString)load.m_lf.lfFaceName >> load.m_lf.lfHeight >> load.m_lf.lfItalic
				>> load.m_lf.lfOrientation >> load.m_lf.lfOutPrecision >> load.m_lf.lfPitchAndFamily
				>> load.m_lf.lfQuality >> load.m_lf.lfStrikeOut >> load.m_lf.lfUnderline
				>> load.m_lf.lfWeight >> load.m_lf.lfWidth;//��Ʈ ����
			pView->e_unit.push_back(load);
		}
		AfxMessageBox(_T("�ε�Ϸ�"));

	}
}


