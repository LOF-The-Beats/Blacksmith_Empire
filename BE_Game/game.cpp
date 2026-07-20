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
#include "Unlock_Manager.h"
#include "Tutorial.h"
#include "Ascension_Manager.h"
#include "Ascension_Upgrade_Screen.h"
#include "Smelter_Manager.h"



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
	m_Unlock_Manager = new Unlock_Manager;
	m_Tutorial = new Tutorial;
	m_Ascension_Manger = new Ascension_Manager;
	m_Ascension_Upgrade_Screen = new Ascension_Upgrade_Screen;
	m_Smelter_Manager = new Smelter_Manager;

	//Resources
	m_Resource_Manager->Add_Resource("Thalions", "Quantity", 0, 0, 20, 0, false, Resources::Resource_Type::Currency, Resources::Resource_Type::None);
	m_Resource_Manager->Add_Resource("Hourglass", "Quantity", 0, 0, 20, 0, false, Resources::Resource_Type::Currency, Resources::Resource_Type::None);
	m_Resource_Manager->Add_Resource("Paper", "Quantity", 0, 1000, 20, 0, false, Resources::Resource_Type::None, Resources::Resource_Type::None);

	m_Resource_Manager->Add_Resource("SoftWood", "Quantity", 0, 10, 20, 0, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::Fuel);
	m_Resource_Manager->Add_Resource("Tin Ore", "Quantity", 0, 10, 20, 0, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None);



	//Windows / Locations
	m_Window_Manager->add_Window("Forest", true);
	m_Window_Manager->add_Window("Forge", false);
	m_Window_Manager->add_Window("Player", false);
	m_Window_Manager->add_Window("Libary", false);
	m_Window_Manager->add_Window("Witch Hut", false);
	m_Window_Manager->add_Window("Mine", false);


	m_Window_Manager->add_Window("Craftingtable", false);
	m_Window_Manager->add_Window("Smelter", false);
	m_Window_Manager->add_Window("Lumberjack Tool", false);
	m_Window_Manager->add_Window("Crafting Tool", false);
	m_Window_Manager->add_Window("Mining Tool", false);
	m_Window_Manager->add_Window("Blueprint Crafting", false);
	m_Window_Manager->add_Window("Blueprint Upgrade", false);
	m_Window_Manager->add_Window("Ascension Upgrade", false);

	//Craftingtables
	m_Craftingtable_Manager->Add_Craftingtable("Master Craftingtable");
	m_Craftingtable_Manager->Add_Craftingtable("Craftingtable 1");
	m_Craftingtable_Manager->Add_Craftingtable("Craftingtable 2");

	m_Craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Set_Unlocked(true);

	//Smelters
	m_Smelter_Manager->Add_Smelter("Smelter 1");

	//Stats
	m_Player->Add_Stats("Lumberjack", 1);
	m_Player->Add_Stats("Crafting", 1);
	m_Player->Add_Stats("Mining", 1);
	m_Player->Add_Stats("Scribe", 1);

	//Blueprints
	m_Blueprint_Manager->Create_All_Blueprints();

	// all unlocks
	m_Unlock_Manager->Create_All_Unlocks();

	// all upgrades
	m_Ascension_Manger->Create_Upgrades();

	// Icons
	m_Resource_Icon_Sheet = new Surface("Assets/Crafting Materials Icons.png");


	// testing things
	if (true)
	{
		m_Resource_Manager->Add_Resource("Stone", "Mined", 0, 25, 20, 0, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None);
		vector all_Resources = m_Resource_Manager->Get_All_Resources();

		m_Unlock_Manager->Get_Unlocked("Forest")->Set_Unlocked(true);
		m_Unlock_Manager->Get_Unlocked("Forge")->Set_Unlocked(true);
		m_Unlock_Manager->Get_Unlocked("Player")->Set_Unlocked(true);
		m_Unlock_Manager->Get_Unlocked("Libary")->Set_Unlocked(true);
		m_Unlock_Manager->Get_Unlocked("Witch Hut")->Set_Unlocked(true);

		m_Smelter_Manager->Get_Smelter("Smelter 1")->Set_Unlocked(true);

		for (size_t i = 0; i < all_Resources.size(); i++)
		{
			all_Resources[i]->Set_Quantity(100000);
		}
	}
	m_Tutorial->Set_Enabled(false);
}

void Game::Tick(float deltaTime)
{
	screen->Clear(0);
	m_Game_Manager->Update_Mouse_Pos(m_Player);
	m_UI->Draw_UI(deltaTime ,screen, m_Resource_Icon_Sheet, m_Resource_Manager, m_Player, m_Window_Manager, m_Craftingtable_Manager, m_Blueprint_Manager, m_Item_Manager, m_Draft_Manager, m_Unlock_Manager, m_Tutorial, m_Ascension_Upgrade_Screen, m_Ascension_Manger,m_Smelter_Manager);
	m_Game_Manager->If_Clicked(m_Player, m_Resource_Manager, m_Window_Manager, m_Craftingtable_Manager, m_Blueprint_Manager, m_Item_Manager, m_Draft_Manager, m_Unlock_Manager, m_Tutorial, m_Ascension_Manger, m_Ascension_Upgrade_Screen, m_Smelter_Manager);

	//update per seccond events
	m_Game_Manager->Check_All_Updates(deltaTime, m_Player, m_Resource_Manager, m_Craftingtable_Manager, m_Blueprint_Manager ,m_Item_Manager, m_Unlock_Manager, m_Ascension_Manger, m_Smelter_Manager);


	//testing
	//printf("blueprint= %s\n", m_Blueprint_Manager->Get_Blueprints("Axe")->Get_Name().c_str());
	//printf("X= %f\n", m_Player->Get_Player_X());
	//printf("Y= %f\n", m_Player->Get_Player_Y());
	//printf("worker %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Workers());
	//printf("production rate %f\n", m_Resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate());
	//screen->Bar(0, 50 + SCRHEIGHT / 10 * 0, 150, 50 + SCRHEIGHT / 10 * 0 + SCRHEIGHT / 10, 0x00FF00);


}


