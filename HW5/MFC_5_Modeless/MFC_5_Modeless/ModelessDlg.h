#pragma once
#include "afxwin.h"


// ModelessDlg ��ȭ �����Դϴ�.

class ModelessDlg : public CDialog
{
	DECLARE_DYNAMIC(ModelessDlg)
private:
	CFont m_dlg_font;
public:
	ModelessDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ModelessDlg();

public:
	CPoint m_str_point;//������ġ
	LOGFONT m_dlg_lf;//���õ� ��Ʈ
	COLORREF m_dlg_color;//��Ʈ ����
	CString m_dlg_str;//��ȭ���� �ؽ�Ʈ ����
	CString point_str;
	int m_dlg_fsize;
	
	bool storing=false, loading=false;
	
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODELESSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	void OnMyEditChange();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	virtual void OnSetFont(CFont* pFont);
	virtual BOOL OnInitDialog();
	CButton m_ok;
	virtual void PostNcDestroy();
	virtual void OnCancel();
	CEdit m_edit;
	CButton m_Btn_font;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedFont();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_btn_save;
	afx_msg void OnBnClickedSave();
	virtual void Serialize(CArchive& ar);
	CButton m_btn_open;
	afx_msg void OnBnClickedOpen();
};
