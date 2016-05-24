#ifndef __BulletManager_H_
#define __BulletManager_H_

#include <SFML\Graphics.hpp>
#include "GameObject.h"

class BulletManager
{
	static BulletManager* instance;
public:
	int bulletCount = 0;
	float bulletVelocity = 3.0f;
	float bulletLifeSpan = 0.5f;

	std::vector<GameObject*> bullets;
	BulletManager();
	~BulletManager();

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

	//void SetGO(std::string objectName, std::string modelName, std::string colID, matrix4 intransform);

	void Render();
};

#endif