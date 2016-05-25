#include "Bullet.h"

void Bullet::Spawn(vector3 pos, vector3 forward)
{
	active = true;
	SetModelMatrix(glm::translate(pos));
	vel = forward * speed;
	lifeSpanCounter = 0.0f;
}

void Bullet::Update(double dt)
{
	if (active)
	{
		MovePhysics(dt);

		lifeSpanCounter += dt;
		if (lifeSpanCounter >= lifeSpan)
		{
			active = false;
		}
	}
}

void Bullet::Render()
{
	if (active)
	{
		GameObject::Render();
	}
}
