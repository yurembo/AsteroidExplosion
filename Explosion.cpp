#include "stdafx.h"
#include "Explosion.h"


CExplosion::CExplosion(void) : growLevel(0), sizeInc(0)
{
	size = 0;
	Xpos = 0;
	Ypos = 0;
	angle = 0;
	timer = 0;
	_img = Core::resourceManager.Get<Render::Texture>("explosion");
}


CExplosion::CExplosion(const int xpos, const int ypos)
{
	size = 0;
	growLevel = 0;
	Xpos = xpos;
	Ypos = ypos;
	angle = 0;
	timer = 0;
	sizeInc = 0;
	_img = Core::resourceManager.Get<Render::Texture>("explosion");
}

CExplosion::CExplosion(const CExplosion& exp)
{
	_img = exp._img;
	Xpos = exp.Xpos;
	Ypos = exp.Ypos;
	size = exp.size;
	angle = exp.angle;
	timer = exp.timer;
	sizeInc = exp.sizeInc;
}

CExplosion& CExplosion::operator=(const CExplosion& exp)
{
	if (this == &exp) return *this;

	if (&exp != nullptr) {
		_img = exp._img;
		Xpos = exp.Xpos;
		Ypos = exp.Ypos;
		size = exp.size;
		angle = exp.angle;
		timer = exp.timer;
		sizeInc = exp.sizeInc;
	}

	return *this;
}

CExplosion::~CExplosion(void)
{
	size = Xpos = Ypos = growLevel = angle = timer = sizeInc = 0;
}

void CExplosion::Draw()
{
	if (_img != nullptr) {
		float h = _img->getBitmapRect().Height();
		float w = _img->getBitmapRect().Width();
		Render::device.PushMatrix();
		Render::device.MatrixTranslate(math::Vector3(Xpos, Ypos, 0));
		Render::device.MatrixRotate(math::Vector3(0, 0, 1), angle);
		Render::device.MatrixScale(size);
		Render::device.MatrixTranslate(math::Vector3(-w / 2.f, -h / 2.f, 0));
		_img->Draw();
		Render::device.PopMatrix();
	}
}

bool CExplosion::Update(const float dt)
{
	if (angle < -360) angle = 0;
	angle -= 1.0;

	if (growLevel == 0) {
		if (size < MAX_EXP_SIZE) {
			size += sizeInc;
		} else {
			growLevel = 1;
		}
	} else
	if (growLevel == 1) {
		timer += dt;
		if (timer > lifeTime) {
			growLevel = 2;
		}
	} else
	if (growLevel == 2) {
		if (size > 0.0) {
			size -= sizeInc;
		} else {
			growLevel = 0;
			timer = 0;
			return true;
		}
	}
	return false;
}

void CExplosion::setBornTime(const float bornTime) 
{ 
	sizeInc = MAX_EXP_SIZE / bornTime / 100;
}

void CExplosion::setLifeTime(const float time)
{
	lifeTime = time;
}

float CExplosion::getSize()
{
	return size * 50;
}