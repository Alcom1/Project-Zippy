#include "Player.h"

//Move
void Player::MoveForward(double dt)
{
	vector3 move = glm::normalize(vector3(m_pCameraMngr->GetForward().x, 0, m_pCameraMngr->GetForward().z)) * speed * static_cast<float>(dt);
	m_pCameraMngr->SetPositionTargetAndView(
		m_pCameraMngr->GetPosition() + move,
		m_pCameraMngr->GetForward() + m_pCameraMngr->GetPosition() + move,
		m_pCameraMngr->GetUpward());

	transform = glm::translate(m_pCameraMngr->GetPosition());
	EstablishModelMatrix();
}

//Move
void Player::MoveBackwards(double dt)
{
	vector3 move = glm::normalize(vector3(m_pCameraMngr->GetForward().x, 0, m_pCameraMngr->GetForward().z)) * -speed * static_cast<float>(dt);
	m_pCameraMngr->SetPositionTargetAndView(
		m_pCameraMngr->GetPosition() + move,
		m_pCameraMngr->GetForward() + m_pCameraMngr->GetPosition() + move,
		m_pCameraMngr->GetUpward());

	transform = glm::translate(m_pCameraMngr->GetPosition());
	EstablishModelMatrix();
}

//Move
void Player::MoveLeft(double dt)
{
	m_pCameraMngr->MoveSideways(speed * -0.75 * static_cast<float>(dt));
	
	transform = glm::translate(m_pCameraMngr->GetPosition());
	EstablishModelMatrix();
}

//Move
void Player::MoveRight(double dt)
{
	m_pCameraMngr->MoveSideways(speed * 0.75 * static_cast<float>(dt));
	
	transform = glm::translate(m_pCameraMngr->GetPosition());
	EstablishModelMatrix();
}

//Jump
void Player::Jump()
{
	vel.y = 12;
}

//Translate the player in a direction
void Player::Translate(vector3 dir)
{
	m_pCameraMngr->SetPositionTargetAndView(
		m_pCameraMngr->GetPosition() + dir,
		m_pCameraMngr->GetForward() + m_pCameraMngr->GetPosition() + dir,
		m_pCameraMngr->GetUpward());

	transform = glm::translate(m_pCameraMngr->GetPosition());
	EstablishModelMatrix();
}

//Perform physics calculations on the player
void Player::MovePhysics(double dt)
{
	vel += acc * static_cast<float>(dt);			//Acceleration
	vel.x -= vel.x * static_cast<float>(dt) * 6.0f;	//Horizontal friction
	vel.z -= vel.z * static_cast<float>(dt) * 6.0f;	//Horizontal friction
	Translate(vel * static_cast<float>(dt));		//Physics movement
}