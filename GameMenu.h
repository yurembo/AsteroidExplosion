#pragma once

#include "Utils/IRect.h"
#include "Utils/Color.h"
#include "TextLabel.h"
#include "consts.h"

class CGameMenu
{
private:
	std::shared_ptr<CTextLabel> _lab1, _lab2;

public:
	CGameMenu(void);
	CGameMenu(const int countAst, const int totalAst);
	CGameMenu(const CGameMenu&);
	CGameMenu& operator=(const CGameMenu&);
	~CGameMenu();

	void Draw();
};