#include "precomp.h"
#include "game.h"
#include "UI.h"
#include "Game_Manager.h"
#include "Player.h"
#include "Resource_Manager.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"
#include "Draft_Manager.h"



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
	m_Blueprint_Manager = new Blueprint_Manager;
	m_Item_Manager = new Item_Manager;
	m_Draft_Manager = new Draft_Manager;

	//Resources
	m_Resource_Manager->Add_Resource("Thalions", 1000, 0, 0, false);
	m_Resource_Manager->Add_Resource("SoftWood", 1000, 10, 0, true);
	m_Resource_Manager->Add_Resource("Paper", 10000, 1000, 0, false);

	//Windows / Locations
	m_Window_Manager->add_Window("Forest", true);
	m_Window_Manager->add_Window("Forge", false);
	m_Window_Manager->add_Window("Player", false);
	m_Window_Manager->add_Window("Libary", false);


	m_Window_Manager->add_Window("Craftingtable 1", false);
	m_Window_Manager->add_Window("Lumberjack Tool", false);
	m_Window_Manager->add_Window("Crafting Tool", false);
	m_Window_Manager->add_Window("Mining Tool", false);
	m_Window_Manager->add_Window("Blueprint Crafting", false);
	m_Window_Manager->add_Window("Blueprint Upgrade", false);

	//Craftingtables
	m_Craftingtable_Manager->Add_Craftingtable("Craftingtable 1");

	//Stats
	m_Player->Add_Stats("Lumberjack", 1);
	m_Player->Add_Stats("Crafting", 1);
	m_Player->Add_Stats("Mining", 1);
	m_Player->Add_Stats("Scribe", 1);

	//Blueprints
	m_Blueprint_Manager->Create_All_Blueprints();
}


void Game::Tick(float deltaTime)
{
	screen->Clear(0);
	m_Game_Manager->Update_Mouse_Pos(m_Player);
	m_UI->Draw_UI(screen, m_Resource_Manager, m_Player, m_Window_Manager, m_Craftingtable_Manager, m_Blueprint_Manager, m_Item_Manager, m_Draft_Manager);
	m_Game_Manager->If_Clicked(m_Player, m_Resource_Manager, m_Window_Manager, m_Craftingtable_Manager, m_Blueprint_Manager, m_Item_Manager, m_Draft_Manager);

	//update per seccond events
	m_Game_Manager->Check_All_Updates(deltaTime, m_Player, m_Resource_Manager, m_Craftingtable_Manager, m_Blueprint_Manager ,m_Item_Manager);


	//testing
	//printf("blueprint= %s\n", m_Blueprint_Manager->Get_Blueprints("Axe")->Get_Name().c_str());
	//printf("X= %f\n", m_Player->Get_Player_X());
	//printf("Y= %f\n", m_Player->Get_Player_Y());
	//printf("worker %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Workers());
	//printf("production rate %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate());
	//screen->Bar(0, 50 + SCRHEIGHT / 10 * 0, 150, 50 + SCRHEIGHT / 10 * 0 + SCRHEIGHT / 10, 0x00FF00);


}


