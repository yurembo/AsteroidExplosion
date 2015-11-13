#pragma once

#include "consts.h"
#include <string>

using namespace std;

class CTextLabel
{
private:
	string text;
	float Xpos, Ypos, Yinc, size;

public:
	CTextLabel(void);
	CTextLabel(const string tex, const int x, const int y);
	CTextLabel(const CTextLabel& lab);
	CTextLabel& operator=(const CTextLabel& lab);

	virtual ~CTextLabel(void);

	void setSize(const float si);
	void Draw();
	bool Update();
};