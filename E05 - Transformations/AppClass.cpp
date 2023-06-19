#include "AppClass.h"
using namespace glm;
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Magnus Conneely- kc4025@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);
	
	//Allocate the memory for the Meshes
	m_uMeshCount = 46;
	for (int i = 0; i < m_uMeshCount; i++)
	{
		MyMesh* m_pMesh = new MyMesh();
		m_pMeshList.push_back(m_pMesh);
		m_pMesh->GenerateCube(1.0f, C_BLACK);
	}

		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();
	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	//set timer
	static float timer = 0;
	static uint clock = m_pSystem->GenClock();
	timer += static_cast<float>(m_pSystem->GetDeltaTime(clock));

	///drawing mesh
	int i = 0;
	static float moveDist = -10.0f;
	static vector3 v3Position = vector3(moveDist, 0.0f, 0.0f);
	v3Position.x = moveDist + timer;
	matrix4 m4Position = translate(vector3(-5.0f, -5.0f, -10.0f)) * translate(v3Position);
	
	
	//c1
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-5.0f, 1.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-5.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-5.0f, 3.0f, 0.0f))); i++;

	//c2
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-4.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-4.0f, 4.0f, 0.0f))); i++;

	//c3
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 1.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 4.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 5.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-3.0f, 7.0f, 0.0f))); i++;

	//c4
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-2.0f, 0.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-2.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-2.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-2.0f, 5.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-2.0f, 6.0f, 0.0f))); i++;

	//c5
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-1.0f, 0.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-1.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-1.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-1.0f, 4.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(-1.0f, 5.0f, 0.0f))); i++;

	//c6
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(0.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(0.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(0.0f, 4.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(0.0f, 5.0f, 0.0f))); i++;

	//c7
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(1.0f, 0.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(1.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(1.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(1.0f, 4.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(1.0f, 5.0f, 0.0f))); i++;

	//c8
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(2.0f, 0.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(2.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(2.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(2.0f, 5.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(2.0f, 6.0f, 0.0f))); i++;

	//c10
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 1.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 4.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 5.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(3.0f, 7.0f, 0.0f))); i++;

	//c11
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(4.0f, 3.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(4.0f, 4.0f, 0.0f))); i++;

	//c12
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(5.0f, 1.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(5.0f, 2.0f, 0.0f))); i++;
	m_pMeshList[i]->Render(m4Projection, m4View, translate(m4Position, vector3(5.0f, 3.0f, 0.0f))); i++;




	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	vector<MyMesh*>m_pMeshList;
	int size = m_pMeshList.size();
	for (int i = 0; i < size; i++)
	{
		if (m_pMeshList[i] != nullptr)
		{
			delete m_pMeshList[i];
			m_pMeshList[i] = nullptr;
		}
	}

	//release GUI
	ShutdownGUI();
}