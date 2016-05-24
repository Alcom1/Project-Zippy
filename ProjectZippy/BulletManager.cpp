#include "BulletManager.h"

BulletManager* BulletManager::instance = nullptr;

BulletManager::BulletManager()
{
	bulletCount = ceilf(bulletLifeSpan / bulletFireRate);
}

BulletManager::~BulletManager()
{

}

void BulletManager::Setup()
{
	for (int i = 0; i < bulletCount; i++)
	{
		bullets.push_back(new Bullet(i, bulletSpeed, bulletLifeSpan));
	}
}

void BulletManager::Update(double dt)
{
	bulletFireRateCounter += static_cast<float>(dt);

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(dt);
	}
}

void BulletManager::Fire(vector3 pos, vector3 forward)
{
	if (bulletFireRateCounter > bulletFireRate)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			if (!bullets[i]->GetActive())
			{
				bullets[i]->Spawn(pos, forward);
				bulletFireRateCounter = 0;
				break;
			}
		}
	}
}

void BulletManager::Render()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Render();
	}
}
