#pragma once

// TextInfo ��� ����Դϴ�.

class TextInfo : public CObject
{//���ͷ� ����� ������ �����ϰ� �׸��� �ϱ����� ����� Ŭ����
public:
	CString m_text;
	CPoint m_point;
	LOGFONT m_lf;//font ����
	COLORREF m_color;
	int m_font_size;

public:
	TextInfo();
	virtual ~TextInfo();
	virtual void Serialize(CArchive& ar);
};


