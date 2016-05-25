#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
private:
	float speed;
	float lifeSpan;
	float lifeSpanCounter;
public:
	Bullet(int num, float inspeed, float inlifeSpan) : GameObject(
		"Bullet_" + num,
		"Bullet.obj",
		"bull",
		glm::translate(vector3(0.0f, 1.0f, 0.0f)))
	{
		speed = inspeed;
		acc = vector3(0.0f);
		active = false;
		lifeSpan = inlifeSpan;
		lifeSpanCounter = inlifeSpan;
	}

	void Spawn(vector3 pos, vector3 forward);

	void Update(double dt);

	void Render();
};