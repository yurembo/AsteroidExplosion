#pragma once

#include "Asteroid.h"

class CExplosion : public CAsteroid
{
private:
	int growLevel;//уровень роста
	float sizeInc;//шаг роста
	float lifeTime;//время жизни при максимальном размере

public:
	CExplosion(void);
	CExplosion(const int xpos, const int ypos);
	CExplosion(const CExplosion& exp);
	CExplosion& operator=(const CExplosion& exp);
	virtual ~CExplosion(void);

	virtual void Draw();
	virtual bool Update(const float dt);//возвращает true если можно удалить
	void setBornTime(const float bornTime);
	void setLifeTime(const float time);
	float getSize();
};

