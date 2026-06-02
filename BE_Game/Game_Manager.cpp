#include "precomp.h"
#include "Game_Manager.h"
#include "Player.h"
#include "Resource_Manager.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"
#include "Draft_Manager.h"

extern GLFWwindow* window;

Game_Manager::Game_Manager()
{
}

void Game_Manager::Update_Mouse_Pos(Player* player)
{
	double px = player->Get_Player_X();
	double py = player->Get_Player_Y();
	glfwGetCursorPos(window, &px, &py);
	player->Set_Player_Pos(px, py);
	return;
}

void Game_Manager::If_Clicked(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager)
{
	if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
	{
		if (!clicked)
		{
			Location_Buttons_Pressed(player, window_Manager);
			if (window_Manager->get_Active_Window() == "Forest")
			{
				Forest_Buttons(player, resource_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Forge")
			{
				Forge_Buttons(player, resource_Manager, window_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Player")
			{
				Player_Buttons(player, window_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Libary")
			{
				Libary_Buttons(player, window_Manager, item_Manager, resource_Manager, draft_Manager, blueprint_Manager);
			}

			if (window_Manager->get_Active_Window() == "Craftingtable 1")
			{
				Craftingtable_1_Window(player, craftingtable, window_Manager, blueprint_Manager, resource_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Lumberjack Tool")
			{
				Lumberjack_Tool_Window(player, window_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Blueprint Crafting")
			{
				Blueprint_Crafting_Window(player, window_Manager, item_Manager, blueprint_Manager, draft_Manager, resource_Manager);
			}
		}
		clicked = true;
	}
	else if (glfwGetMouseButton(window, 0) == GLFW_RELEASE)
	{
		clicked = false;
	}
}

bool Game_Manager::Is_Mouse_Over_Standard(Player* player, double x, double y)
{
	if (player->Get_Player_X() >= x &&
		player->Get_Player_X() <= x +110 &&
		player->Get_Player_Y() >= y &&
		player->Get_Player_Y() <= y + 50)
	{
		return true;
	}
	return false;
}

bool Game_Manager::Is_Mouse_Over_Location(Player* player, double x, double y, double z)
{
	if (player->Get_Player_X() >= x  &&
		player->Get_Player_X() <= x + 150 &&
		player->Get_Player_Y() >= 50 + SCRHEIGHT / 10 * z &&
		player->Get_Player_Y() <= 50 + SCRHEIGHT / 10 * z + SCRHEIGHT / 10)
	{
		return true;
	}
	return false;
}


void Game_Manager::Location_Buttons_Pressed(Player* player, Window_Manager* window_Manager)
{
	if (Is_Mouse_Over_Location(player, 0, 0, 0))
	{
		window_Manager->set_Active_Window("Forest");
	}
	else if (Is_Mouse_Over_Location(player, 0, 0, 1))
	{
		window_Manager->set_Active_Window("Forge");
	}
	else if (Is_Mouse_Over_Location(player, 0, 0, 2))
	{
		window_Manager->set_Active_Window("Player");
	}
	else if (Is_Mouse_Over_Location(player, 0, 0, 3))
	{
		window_Manager->set_Active_Window("Libary");
	}
}

void Game_Manager::Forest_Buttons(Player* player, Resource_Manager* resource_Manager, Item_Manager* item_Manager)
{
	auto softWood = resource_Manager->Get_Resource("SoftWood");
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto lumberjack = player->Get_Stats("Lumberjack");
	auto item = item_Manager->Get_Item(softWood->Get_Worker_Tool_Equiped());

	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		softWood->Add_Quantity(lumberjack->Get_Power());
		lumberjack->Add_Exp(1);
	}
	if (Is_Mouse_Over_Standard(player, 160, 230) &&
		softWood->Get_Worker_Cost() <= thalions->Get_Quantity())
	{

		if (softWood->Get_Worker_Tool_Equiped() != "None" &&
			item->Get_Quantity() >= 1)
		{

			softWood->Add_Workers(1);
			softWood->Update_Production_Rate();
			thalions->Sub_Quantity(softWood->Get_Worker_Cost());
			softWood->Set_Worker_Cost(softWood->Get_Worker_Cost() * 1.2);

			item->Sub_Quantity(1);
		}
		else if (softWood->Get_Worker_Tool_Equiped() == "None")
		{
			softWood->Add_Workers(1);
			softWood->Update_Production_Rate();
			thalions->Sub_Quantity(softWood->Get_Worker_Cost());
			softWood->Set_Worker_Cost(softWood->Get_Worker_Cost() * 1.2);
		}
	}
	if (Is_Mouse_Over_Standard(player, 160, 300))
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Name();
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > softWood->Get_Workers_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= softWood->Get_Workers())
			{
				sorted_Item[0]->Sub_Quantity(softWood->Get_Workers());
				softWood->Set_Workers_Tool_Power(sorted_Item[0]->Get_Power());
				softWood->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}
}

void Game_Manager::Forge_Buttons(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Item_Manager* item_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		window_Manager->set_Active_Window("Craftingtable 1");
	}

	if (Is_Mouse_Over_Standard(player, 160, 300))
	{
		resource_Manager->Get_Resource("Thalions")->Add_Quantity(item_Manager->Sell_All_Items());
	}
}

void Game_Manager::Player_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 60))
	{
		window_Manager->set_Active_Window("Lumberjack Tool");
	}
}

void Game_Manager::Libary_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager,Draft_Manager* draft_Manager, Blueprint_Manager* blueprint_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		auto softWood = resource_Manager->Get_Resource("SoftWood");
		auto paper = resource_Manager->Get_Resource("Paper");

		if (softWood->Get_Quantity() >= paper->Get_Hardness())
		{
			softWood->Sub_Quantity(paper->Get_Hardness());
			paper->Add_Quantity(1);
		}
	}

	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 + 80, 160))
	{
		window_Manager->set_Active_Window("Blueprint Crafting");
		draft_Manager->Draft_Blueprint_Cards(blueprint_Manager);
	}



}

void Game_Manager::Craftingtable_1_Window(Player* player, Craftingtable_Manager* craftingtable, Window_Manager* window_Manager, Blueprint_Manager* blueprint_Manager, Resource_Manager* resource_Manager)
{

	auto sorted_Resources = resource_Manager->Get_Sorted_Resources_Numbers();
	for (size_t i = 0; i < sorted_Resources.size(); i++)
	{
		int start_Y = 160;
		if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 1 - 120, start_Y + (i * 50)))
		{
			craftingtable->get_Craftingtable("Craftingtable 1")->Set_Resource(sorted_Resources[i]->Get_Name());
		}
	}
	auto sorted_Blueprints = blueprint_Manager->Get_Sorted_Blueprints_Numbers();
	for (size_t i = 0; i < sorted_Blueprints.size(); i++)
	{
		int start_Y = 160;
		if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 2 + 10, start_Y + (i * 50)))
		{
			craftingtable->get_Craftingtable("Craftingtable 1")->Set_Blueprint(sorted_Blueprints[i]->Get_Name());
		}
	}

	
	
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, 160))
	{
		window_Manager->set_Active_Window("Forge");
	}
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50) &&
		craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "none" &&
		craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "none" &&
		(blueprint_Manager->Get_Blueprints(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint())->Get_Cost() <= resource_Manager->Get_Resource(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource())->Get_Quantity() ||
		craftingtable->get_Craftingtable("Craftingtable 1")->Get_In_Use()))
	{
		player->Get_Stats("Crafting")->Add_Exp(1);
		craftingtable->get_Craftingtable("Craftingtable 1")->Add_Progress(player->Get_Stats("Crafting")->Get_Power());
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_In_Use() == false)
		{
			resource_Manager->Get_Resource(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource())->Sub_Quantity(blueprint_Manager->Get_Blueprints(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint())->Get_Cost());
		}
		craftingtable->get_Craftingtable("Craftingtable 1")->Set_In_Use(true);
	}
}

void Game_Manager::Lumberjack_Tool_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager)
{
	auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Name();
	double start_X = SCRWIDTH / 2 + 10;
	double start_Y = 115;
	double button_Hight = 55;

	for (double i = 0; i < sorted_Items.size(); i++)
	{
		Item* item = sorted_Items[i];

		if (Is_Mouse_Over_Standard(player, start_X, start_Y + i * button_Hight))
		{
			auto stats = player->Get_Stats("Lumberjack");
			string old_Tool = stats->Get_Tool_Name();
			stats->Set_Tool_Name(item->Get_Name());
			stats->Set_Tool_Power(item->Get_Power());
			item->Sub_Quantity(1);
			if (old_Tool != "Hands")
			{
				item_Manager->Get_Item(old_Tool)->Add_Quantity(1);
			}
		}
		
	}
}
void Game_Manager::Blueprint_Crafting_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager)
{
	if (Is_Mouse_Over_Standard(player, 380 + 0 * (((SCRWIDTH - 60 - 170) - 20 * 2) / 3), SCRHEIGHT / 2 + 400) &&
		resource_Manager->Get_Resource("Paper")->Get_Quantity() >= draft_Manager->Get_Cost())
	{
		blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_1())->Set_Unlocked(true);
		draft_Manager->Draft_Blueprint_Cards(blueprint_Manager);
		resource_Manager->Get_Resource("Paper")->Sub_Quantity(draft_Manager->Get_Cost());
		draft_Manager->Calculate_Cost();
	}
}

void Game_Manager::Check_All_Updates(double deltatime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager)
{
	Update_All_Per_Seccond_Events(deltatime, player, resource_Manager);
	Check_Level_Up(player);
	Check_Player_Stats(player);
	Check_Craftingtable_Progress(resource_Manager, craftingtable, blueprint_Manager, item_Manager);
}

void Game_Manager::Update_All_Per_Seccond_Events(double deltaTime, Player* player, Resource_Manager* resource_Manager)
{
	auto resource = resource_Manager->Get_Resource("SoftWood");
	resource->Update_Production_Rate();
	resource->Add_Quantity(resource->Get_Production_Rate() * (deltaTime / 1000));
	
}

void Game_Manager::Check_Level_Up(Player* player)
{

	auto lumberjack = player->Get_Stats("Lumberjack");
	auto crafting = player->Get_Stats("Crafting");

	if (lumberjack->Get_Exp() >= lumberjack->Get_Exp_Needed())
	{
		lumberjack->Add_Level(1);
		lumberjack->Add_Exp_Needed(50);
		lumberjack->Set_Exp(0);
	}
	if (crafting->Get_Exp() >= crafting->Get_Exp_Needed())
	{
		crafting->Add_Level(1);
		crafting->Add_Exp_Needed(50);
		crafting->Set_Exp(0);
	}
}

void Game_Manager::Check_Player_Stats(Player* player)
{
	auto lumberjack = player->Get_Stats("Lumberjack");
	auto crafting = player->Get_Stats("Crafting");

	lumberjack->Set_Power(lumberjack->Get_Level() * lumberjack->Get_Tool_Power());
	crafting->Set_Power(crafting->Get_Level());
}

void Game_Manager::Check_Craftingtable_Progress(Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager)
{
	auto table = craftingtable->get_Craftingtable("Craftingtable 1");
	auto blueprint = blueprint_Manager->Get_Blueprints(table->Get_Blueprint());
	auto resource = resource_Manager->Get_Resource(table->Get_Resource());

	if (resource && table->Get_Progress() >= resource->Get_Hardness())
	{
		table->Set_Progress(0);
		double level = blueprint->Get_Level();
		string combined_Name = table->Get_Resource() + " " + table->Get_Blueprint() + " " + to_string(static_cast<int>(blueprint->Get_Level()));
		auto item = item_Manager->Get_Item(combined_Name);
		if (item)
		{
			item->Add_Quantity(1);
			table->Set_In_Use(false);
		}
		else
		{
			item_Manager->Add_Item(combined_Name, table->Get_Resource(), table->Get_Blueprint(), blueprint->Get_Equip_Slot(), blueprint->Get_Level(), resource->Get_Hardness() * blueprint->Get_Level(), resource->Get_Hardness() * blueprint->Get_Conversion_Rate());
			table->Set_In_Use(false);
		}
	}
}
