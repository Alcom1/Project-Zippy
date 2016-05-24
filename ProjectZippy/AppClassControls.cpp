#include "AppClass.h"

MyBoundingObjectManager* BOMngr = MyBoundingObjectManager::GetInstance();

void AppClass::ProcessKeyboard(void)
{
	bool bModifier = false;
	float fSpeed = 0.1f;

#pragma region ON_KEY_PRESS_RELEASE
	static bool	bLastF1 = false, bLastF2 = false, bLastF3 = false, bLastF4 = false, bLastF5 = false,
				bLastF6 = false, bLastF7 = false, bLastF8 = false, bLastF9 = false, bLastF10 = false,
				bLastEscape = false, bLastF = false;
#define ON_KEY_PRESS_RELEASE(key, pressed_action, released_action){  \
			bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::key);			\
			if(pressed){											\
				if(!bLast##key) pressed_action;}/*Just pressed? */\
			else if(bLast##key) released_action;/*Just released?*/\
			bLast##key = pressed; } //remember the state
#pragma endregion

#pragma region Modifiers
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		bModifier = true;
#pragma endregion

#pragma region Camera Positioning
	if(bModifier)
		fSpeed *= 10.0f;

	//shoot
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		vector3 offset = glm::normalize(glm::cross(m_pCameraMngr->GetForward(), m_pCameraMngr->GetRightward())) * 0.5f;
		BTMngr->Fire(m_pCameraMngr->GetPosition() + offset, m_pCameraMngr->GetForward());
	}

	//Move forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player->MoveForward(fTimeSpan);
	}

	//Move backwards
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player->MoveBackwards(fTimeSpan);
	}

	//Move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->MoveLeft(fTimeSpan);

	//Move right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->MoveRight(fTimeSpan);

	//Jump!
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!pressedSpace)
			player->Jump();
		pressedSpace = true;
	}
	else
	{
		pressedSpace = false;
	}

	//Display BOs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		if (!pressedI)
		{
			BOMngr->FlipVisibility();
		}
		pressedI = true;
	}
	else
	{
		pressedI = false;
	}

	//Display octree
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		if (!pressedO)
		{
			toggleO = !toggleO;
		}
		pressedO = true;
	}
	else
	{
		pressedO = false;
	}

#pragma endregion

#pragma region Other Actions
	ON_KEY_PRESS_RELEASE(Escape, NULL, PostMessage(m_pWindow->GetHandler(), WM_QUIT, NULL, NULL));
	ON_KEY_PRESS_RELEASE(F1, NULL, m_pCameraMngr->SetCameraMode(CAMPERSP));
	ON_KEY_PRESS_RELEASE(F2, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOZ));
	ON_KEY_PRESS_RELEASE(F3, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOY));
	ON_KEY_PRESS_RELEASE(F4, NULL, m_pCameraMngr->SetCameraMode(CAMROTHOX));
	static bool bFPSControll = false;
	ON_KEY_PRESS_RELEASE(F, bFPSControll = !bFPSControll, m_pCameraMngr->SetFPS(bFPSControll));
#pragma endregion
}
void AppClass::ProcessMouse(void)
{
	m_bArcBall = false;
	m_bFPC = false;
#pragma region ON_MOUSE_PRESS_RELEASE
	static bool	bLastLeft = false, bLastMiddle = false, bLastRight = false;
#define ON_MOUSE_PRESS_RELEASE(key, pressed_action, released_action){  \
			bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::key);			\
			if(pressed){											\
				if(!bLast##key) pressed_action;}/*Just pressed? */\
			else if(bLast##key) released_action;/*Just released?*/\
			bLast##key = pressed; } //remember the state
#pragma endregion
	bool bLeft = false;
	ON_MOUSE_PRESS_RELEASE(Left, NULL, bLeft = true)
	if (bLeft)
	{
		//Turn off the visibility of all BOs for all instances
		m_pMeshMngr->SetVisibleBO(BD_NONE, "ALL", -1);
		//Get the Position and direction of the click on the screen
		std::pair<vector3, vector3> pair =
			m_pCameraMngr->GetClickAndDirectionOnWorldSpace(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		float fDistance = 0;//Stores the distance to the first colliding object
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
		m_bArcBall = true;
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		m_bFPC = true;
}