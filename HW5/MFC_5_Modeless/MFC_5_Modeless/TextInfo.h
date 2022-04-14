#pragma once

// TextInfo 명령 대상입니다.

class TextInfo : public CObject
{//벡터로 만들어 정보를 저장하고 그리고 하기위해 사용할 클래스
public:
	CString m_text;
	CPoint m_point;
	LOGFONT m_lf;//font 정보
	COLORREF m_color;
	int m_font_size;

public:
	TextInfo();
	virtual ~TextInfo();
	virtual void Serialize(CArchive& ar);
};


