#pragma once


// GraphBoard

class GraphBoard : public CStatic
{
	DECLARE_DYNAMIC(GraphBoard)

public:
	GraphBoard();
	virtual ~GraphBoard();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


