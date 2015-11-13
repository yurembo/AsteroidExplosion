#include "stdafx.h"
#include "GameMenu.h"

CGameMenu::CGameMenu(void)
{
	_lab1 = nullptr;
	_lab1 = nullptr;
}

CGameMenu::CGameMenu(const int countAst, const int totalAst)
{
	string s = "Asteroids were destroyed: " + utils::lexical_cast(countAst) + ", total " + utils::lexical_cast(totalAst);
	_lab1 = std::make_shared<CTextLabel>(s, GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2 + 25);
	_lab1->setSize(2.0);

	string t = "Click somewhere to restart a game";
	_lab2 = std::make_shared<CTextLabel>(t, GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2 - 25);
	_lab2->setSize(0.8);
}

CGameMenu::CGameMenu(const CGameMenu& menu)
{
	_lab1 = menu._lab1;
	_lab2 = menu._lab2;
}

CGameMenu& CGameMenu::operator=(const CGameMenu& menu)
{
	if (this == &menu) return *this;

	if (&menu != nullptr) {
		_lab1 = menu._lab1;
		_lab2 = menu._lab2;
	}

	return *this;
}

CGameMenu::~CGameMenu()
{
	_lab1 = nullptr;
	_lab2 = nullptr;
}

void CGameMenu::Draw()
{
	Render::device.SetTexturing(false);
	Render::BeginColor(Color(0, 0, 0, 255));
	Render::DrawRect(GAME_WINDOW_WIDTH / 2 - 400, GAME_WINDOW_HEIGHT / 2 - 50, 800, 80);
	Render::EndColor();
	Render::device.SetTexturing(true);
	
	if (_lab1 != nullptr) {
		_lab1->Draw();
	}

	if (_lab2 != nullptr) {
		_lab2->Draw();
	}
}