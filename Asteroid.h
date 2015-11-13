#pragma once

#include "consts.h"

class CAsteroid 
{
private:
	float Xinc, Yinc;
	ParticleEffect *_eff;

protected:
	Render::Texture *_img;
	float size;
	float Xpos, Ypos;
	float angle;
	float timer;//накапливает тут время

public:
	CAsteroid(void);
	CAsteroid(const CAsteroid& ast);
	CAsteroid& operator=(const CAsteroid& ast);
	virtual ~CAsteroid(void);

	virtual void Draw();
	virtual bool Update(const float dt);

	float getRadius();
	IPoint getLocation();

	void setEffect(EffectsContainer *cont);
	void FinishEffect();
};

