// TextInfo.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_5_Modeless.h"
#include "TextInfo.h"
#include"MFC_5_ModelessView.h"

// TextInfo

TextInfo::TextInfo()
{
}

TextInfo::~TextInfo()
{
}


// TextInfo 멤버 함수


void TextInfo::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		
	}
	else
	{	// loading code
	}
}
