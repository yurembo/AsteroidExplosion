#include "stdafx.h"
#include "TextLabel.h"


CTextLabel::CTextLabel(void) : text(""), Xpos(0), Ypos(0), Yinc(0), size(0)
{
}

CTextLabel::CTextLabel(const string tex, const int x, const int y)
{
	text = tex;
	Xpos = x;
	Ypos = y;
	size = 0.2;
	Yinc = 0.5;
}

CTextLabel::CTextLabel(const CTextLabel& lab)
{
	text = lab.text;
	Xpos = lab.Xpos;
	Ypos = lab.Ypos;
	size = lab.size;
	Yinc = lab.Yinc;
}

CTextLabel& CTextLabel::operator=(const CTextLabel& lab)
{
	if (this == &lab) return *this;

	if (&lab != nullptr) {
		text = lab.text;
		Xpos = lab.Xpos;
		Ypos = lab.Ypos;
		size = lab.size;
		Yinc = lab.Yinc;
	}

	return *this;
}

CTextLabel::~CTextLabel(void)
{
	text = "";
	Xpos = Ypos = Yinc = size = 0;
}

void CTextLabel::Draw()
{
	if (text != "") {
		Render::BindFont("arial");
		Render::PrintString(Xpos, Ypos, text, size, CenterAlign);
	}
}

bool CTextLabel::Update()
{
	if (size > MAX_LABEL_SIZE) return true;
	size += STEP_LABEL_GROW;
	Ypos += Yinc;
	return false;
}

void CTextLabel::setSize(const float si)
{
	size = si;
}