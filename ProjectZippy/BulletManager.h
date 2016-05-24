#ifndef __BulletManager_H_
#define __BulletManager_H_

#include <SFML\Graphics.hpp>
#include "Bullet.h"

class BulletManager
{
	static BulletManager* instance;
public:
	int bulletCount;
	float bulletSpeed = 60.0f;
	float bulletLifeSpan = 1.0f;
	float bulletFireRate = 0.25f;
	float bulletFireRateCounter = 0.0f;

	std::vector<Bullet*> bullets;
	BulletManager();
	~BulletManager();

	void Setup();

	static BulletManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new BulletManager();
		}
		return instance;
	};

	static BulletManager* ReleaseInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
		return instance;
	};

	void Update(double dt);

	void Fire(vector3 pos, vector3 forward);

	void Render();
};
#endif