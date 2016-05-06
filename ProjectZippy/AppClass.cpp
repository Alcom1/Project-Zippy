#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Project Zippy"); // Window Name

	//Set the clear color based on Microsoft's CornflowerBlue (default in XNA)
	//if this line is in Init Application it will depend on the .cfg file, if it
	//is on the InitVariables it will always force it regardless of the .cfg
	m_v4ClearColor = vector4(0.4f, 0.6f, 0.9f, 0.0f);
}

void AppClass::InitVariables(void)
{
	//Reset the selection to -1, -1
	m_selection = std::pair<int, int>(-1, -1);

	//Set the camera position
	m_pCameraMngr->SetPositionTargetAndView(
		vector3(0.0f, 2.5f, 15.0f),//Camera position
		vector3(0.0f, 2.5f, 0.0f),//What Im looking at
		REAXISY);//What is up

	//Load a model onto the Mesh manager
	spawner1 = new EnemyManager(vector3(0.0f, 2.0f, -30.0f));
	spawner2 = new EnemyManager(vector3(0.0f, 2.0f, 30.0f));
	spawner3 = new EnemyManager(vector3(-30.0f, 2.0f, 0.0f));
	spawner4 = new EnemyManager(vector3(30.0f, 2.0f, 0.0f));

	GOMngr->SetGO(
		"MainCube",
		"CenterFloorCube.obj",
		"wall",
		glm::translate(vector3(0.0f, 0.0f, 0.0f)) * glm::scale(vector3(42.0f, 1.0f, 42.0f)));
	GOMngr->SetGO(
		"TopPath",
		"FloorCube.obj",
		"wall",
		glm::translate(vector3(0.0f, 0.0f, -28.0f)) * glm::scale(vector3(14.0f, 1.0f, 14.0f)));
	GOMngr->SetGO(
		"BottomPath",
		"FloorCube.obj",
		"wall",
		glm::translate(vector3(0.0f, 0.0f, 28.0f)) * glm::scale(vector3(14.0f, 1.0f, 14.0f)));
	GOMngr->SetGO(
		"LeftPath",
		"FloorCube.obj",
		"wall",
		glm::translate(vector3(-28.0f, 0.0f, 0.0f)) * glm::scale(vector3(14.0f, 1.0f, 14.0f)));
	GOMngr->SetGO(
		"RightPath",
		"FloorCube.obj",
		"wall",
		glm::translate(vector3(28.0f, 0.0f, 0.0f)) * glm::scale(vector3(14.0f, 1.0f, 14.0f)));
	GOMngr->SetGO(
		"Tower1",
		"TowerWall.obj",
		"wall",
		glm::translate(vector3(-17.5f, 4.0f, -17.5f)) * glm::scale(vector3(7.0f, 7.0f, 7.0f)));
	GOMngr->SetGO(
		"Tower2",
		"TowerWall.obj",
		"wall",
		glm::translate(vector3(-17.5f, 4.0f, 17.5f)) * glm::scale(vector3(7.0f, 7.0f, 7.0f)));
	GOMngr->SetGO(
		"Tower3",
		"TowerWall.obj",
		"wall",
		glm::translate(vector3(17.5f, 4.0f, -17.5f)) * glm::scale(vector3(7.0f, 7.0f, 7.0f)));
	GOMngr->SetGO(
		"Tower4",
		"TowerWall.obj",
		"wall",
		glm::translate(vector3(17.5f, 4.0f, 17.5f)) * glm::scale(vector3(7.0f, 7.0f, 7.0f)));
	GOMngr->SetGO(
		"TopWall_1",
		"Wall.obj",
		"wall",
		glm::translate(vector3(-14.0f, 7.5f, -28.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"TopWall_2",
		"Wall.obj",
		"wall",
		glm::translate(vector3(14.0f, 7.5f, -28.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"BottomWall_1",
		"Wall.obj",
		"wall",
		glm::translate(vector3(-14.0f, 7.5f, 28.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"BottomWall_2",
		"Wall.obj",
		"wall",
		glm::translate(vector3(14.0f, 7.5f, 28.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"LeftWall_1",
		"Wall.obj",
		"wall",
		glm::translate(vector3(-28.0f, 7.5f, -14.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"LeftWall_2",
		"Wall.obj",
		"wall",
		glm::translate(vector3(28.0f, 7.5f, -14.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"RightWall_1",
		"Wall.obj",
		"wall",
		glm::translate(vector3(-28.0f, 7.5f, 14.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"RightWall_2",
		"Wall.obj",
		"wall",
		glm::translate(vector3(28.0f, 7.5f, 14.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"TopPathWall",
		"Wall.obj",
		"wall",
		glm::translate(vector3(0.0f, 7.5f, -42.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"BottomPathWall",
		"Wall.obj",
		"wall",
		glm::translate(vector3(0.0f, 7.5f, 42.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"LeftPathWall",
		"Wall.obj",
		"wall",
		glm::translate(vector3(-42.0f, 7.5f, 0.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"RightPathWall",
		"Wall.obj",
		"wall",
		glm::translate(vector3(42.0f, 7.5f, 0.0f)) * glm::scale(vector3(14.0f, 14.0f, 14.0f)));
	GOMngr->SetGO(
		"Roof",
		"CenterFloorCube.obj",
		"wall",
		glm::translate(vector3(0.0f, 15.0f, 0.0f)) * glm::scale(vector3(70.0f, 1.0f, 70.0f)));
	GOMngr->SetGO(
		"Core",
		"Core.obj",
		"wall",
		glm::translate(vector3(0.0f, 2.0f, 0.0f)) * glm::scale(vector3(3.0f, 3.0f, 3.0f)));

	state = GameState::start;
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update();

	if (state == GameState::start) {
		m_v4ClearColor = vector4(0.051f, 0.412f, 0.671f, 0.0f);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("                       Welcome to Project Zippy.", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("                          Press Space to play.", REBLUE);
	}

	if (state == GameState::pause) {
		m_v4ClearColor = vector4(0.051f, 0.412f, 0.671f, 0.0f);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("                             Game Paused.", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("                         Press P to continue.", REBLUE);
		m_pMeshMngr->PrintLine("                           Press X to quit.", REBLUE);
	}

	if (state == GameState::end) {
		m_v4ClearColor = vector4(0.051f, 0.412f, 0.671f, 0.0f);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("                              Game Over!", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("", REBLUE);
		m_pMeshMngr->PrintLine("               Press Space to return to the main screen.", REBLUE);
	}

	if (state == GameState::play) {

		//First person camera movement
		if (m_bFPC == true)
			CameraRotation();

		//Call the arcball method
		ArcBall();

		GOMngr->Render();

		//update enemies
		double fTimeSpan = m_pSystem->LapClock();

		spawner1->Update(fTimeSpan);
		spawner2->Update(fTimeSpan);
		spawner3->Update(fTimeSpan);
		spawner4->Update(fTimeSpan);

		BOMngr->CheckColissions();
		BOMngr->Render();
		//Indicate the FPS
		int nFPS = m_pSystem->GetFPS();

		//Print info on the screen
		m_pMeshMngr->PrintLine(m_pSystem->GetAppName(), REBLACK);
		m_pMeshMngr->Print("FPS: " + std::to_string(nFPS), REBLACK);
	}

	// End the game if the player's or the core's health drops to zero
	if (BOMngr->playerhealth <= 0 || BOMngr->coreHealth <= 0) {
		state = GameState::end;
	}
}

void AppClass::Display(void)
{
	//clear the screen
	ClearScreen();
	//Render the grid based on the camera's mode:
	/*switch (m_pCameraMngr->GetCameraMode())
	{
	default: //Perspective
	m_pMeshMngr->AddGridToQueue(1.0f, REAXIS::XY); //renders the XY grid with a 100% scale
	break;
	case CAMERAMODE::CAMROTHOX:
	m_pMeshMngr->AddGridToQueue(1.0f, REAXIS::YZ, RERED * 0.75f); //renders the YZ grid with a 100% scale
	break;
	case CAMERAMODE::CAMROTHOY:
	m_pMeshMngr->AddGridToQueue(1.0f, REAXIS::XZ, REGREEN * 0.75f); //renders the XZ grid with a 100% scale
	break;
	case CAMERAMODE::CAMROTHOZ:
	m_pMeshMngr->AddGridToQueue(1.0f, REAXIS::XY, REBLUE * 0.75f); //renders the XY grid with a 100% scale
	break;
	}*/
	m_pMeshMngr->Render(); //renders the render list

	m_pMeshMngr->ResetRenderList();

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}