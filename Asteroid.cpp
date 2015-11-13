#include "stdafx.h"
#include "Asteroid.h"
#include "Utils/random.hpp"


CAsteroid::CAsteroid(void) : angle(0), Xpos(GAME_WINDOW_WIDTH / 2), Ypos (GAME_WINDOW_HEIGHT / 2), _eff(nullptr)
{
	//Xpos = math::random(0.0, GAME_WINDOW_WIDTH); 
	//Ypos = math::random(0.0, GAME_WINDOW_HEIGHT);
	timer = 0;
	size = math::random(0.2f, 0.35f);
	Xinc = math::random(-0.5f, 0.5f) * math::random(2, 7);
	Yinc = math::random(-0.5f, 0.5f) * math::random(2, 7);
	_img = Core::resourceManager.Get<Render::Texture>("asteroid");
}


CAsteroid::~CAsteroid(void)
{
	_img = nullptr;
	_eff = nullptr;
	Xpos = Ypos = angle = size = Xinc = Yinc = timer = 0;
}

CAsteroid::CAsteroid(const CAsteroid& ast)
{
	_img = ast._img;
	size = ast.size;
	Xpos = ast.Xpos;
	Ypos = ast.Ypos;
	Xinc = ast.Xinc;
	Yinc = ast.Yinc;
	angle = ast.angle;
	_eff = ast._eff;
}

CAsteroid& CAsteroid::operator=(const CAsteroid& ast)
{
	if (this == &ast) return *this;

	if (&ast != nullptr) {
		_img = ast._img;
		size = ast.size;
		Xpos = ast.Xpos;
		Ypos = ast.Ypos;
		Xinc = ast.Xinc;
		Yinc = ast.Yinc;
		angle = ast.angle;
		_eff = ast._eff;
	}

	return *this;
}

bool CAsteroid::Update(const float dt)
{
	float h = _img->getBitmapRect().Height() / 2;
	float w = _img->getBitmapRect().Width() / 2;
	if (Xpos > GAME_WINDOW_WIDTH) {
		Xpos = GAME_WINDOW_WIDTH;
		Xinc = -Xinc;
	}
	if (Ypos > GAME_WINDOW_HEIGHT) {
		Ypos = GAME_WINDOW_HEIGHT;
		Yinc = -Yinc;
	}
	if (Xpos < 0) {
		Xpos = 0;
		Xinc = -Xinc;
	}
	if (Ypos < 0) {
		Ypos = 0;
		Yinc = -Yinc;
	}
	timer += dt;
	if (timer >= MAX_TIME) {
		Xpos += Xinc;
		Ypos += Yinc;
		timer = 0;
	}
	if (angle > 360) angle = 0;
	angle += 5.0;

	if (_eff != nullptr) {
		_eff->posX = Xpos;
		_eff->posY = Ypos;
	}
	return false;
}

void CAsteroid::Draw()
{
	if (_img != nullptr) {
		float h = _img->getBitmapRect().Height();
		float w = _img->getBitmapRect().Width();
		Render::device.PushMatrix();
		Render::device.MatrixTranslate(math::Vector3(Xpos, Ypos, 0));
		Render::device.MatrixRotate(math::Vector3(0, 0, 1), angle);
		Render::device.MatrixTranslate(math::Vector3(-w / 2.f, -h / 2.f, 0));
		_img->Draw();
		Render::device.PopMatrix();
	}
}

float CAsteroid::getRadius()
{
	if (_img != nullptr) {
		float f = _img->getBitmapRect().Width() / 2;
		return _img->getBitmapRect().Width() / 2;
	}

	return 0;
}

IPoint CAsteroid::getLocation()
{
	IPoint p;
	p.x = Xpos;
	p.y = Ypos;

	return p;
}

void CAsteroid::setEffect(EffectsContainer *cont)
{
	_eff = cont->AddEffect("FireTail");
	_eff->posX = Xpos;
	_eff->posY = Ypos;
	_eff->Reset();
}

void CAsteroid::FinishEffect()
{
	_eff->Finish();
	_eff = nullptr;
}