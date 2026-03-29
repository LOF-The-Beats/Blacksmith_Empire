#include "precomp.h"
#include "game.h"
#include "UI.h"
#include "Game_Manager.h"
#include "Player.h"
#include "Resource_Manager.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"



extern GLFWwindow* window;


void Game::Init()
{
	// objects
	m_UI = new UI;
	m_Game_Manager = new Game_Manager;
	m_Player = new Player;
	m_Resource_Manager = new Resource_Manager;
	m_Window_Manager = new Window_Manager;
	m_Craftingtable_Manager = new Craftingtable_Manager;

	//Resources
	m_Resource_Manager->Add_Resource("SoftWood", 0);

	//Windows / Locations
	m_Window_Manager->add_Window("Forest", true);
	m_Window_Manager->add_Window("Forge", false);


	m_Window_Manager->add_Window("Craftingtable 1", false);

	//Craftingtables
	m_Craftingtable_Manager->Add_Craftingtable("Craftingtable 1");
}


void Game::Tick(float deltaTime)
{
	screen->Clear(0);
	m_Game_Manager->Update_Mouse_Pos(m_Player);
	m_UI->Draw_UI(screen, m_Resource_Manager, m_Player, m_Window_Manager, m_Craftingtable_Manager);
	m_Game_Manager->If_Clicked(m_Player, m_Resource_Manager, m_Window_Manager, m_Craftingtable_Manager);

	//update per seccond events
	m_Game_Manager->Check_All_Updates(deltaTime, m_Player, m_Resource_Manager);


	//testing
	//printf("X= %f\n", m_Player->Get_Player_X());
	//printf("Y= %f\n", m_Player->Get_Player_Y());
	//printf("worker %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Workers());
	//printf("production rate %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate());


}


