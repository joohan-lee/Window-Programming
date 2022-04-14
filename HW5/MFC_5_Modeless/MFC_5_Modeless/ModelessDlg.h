#pragma once
#include "afxwin.h"


// ModelessDlg 대화 상자입니다.

class ModelessDlg : public CDialog
{
	DECLARE_DYNAMIC(ModelessDlg)
private:
	CFont m_dlg_font;
public:
	ModelessDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ModelessDlg();

public:
	CPoint m_str_point;//시작위치
	LOGFONT m_dlg_lf;//선택된 폰트
	COLORREF m_dlg_color;//폰트 색상
	CString m_dlg_str;//대화상자 텍스트 내용
	CString point_str;
	int m_dlg_fsize;
	
	bool storing=false, loading=false;
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODELESSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
