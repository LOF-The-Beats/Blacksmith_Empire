#include "precomp.h"
#include "Game_Manager.h"
#include "Player.h"
#include "Resource_Manager.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"

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

void Game_Manager::If_Clicked(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable)
{
	if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
	{
		if (!clicked)
		{
			Location_Buttons_Pressed(player, window_Manager);
			if (window_Manager->get_Active_Window() == "Forest")
			{
				Forest_Buttons(player, resource_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Forge")
			{
				Forge_Buttons(player, resource_Manager, window_Manager);
			}

			if (window_Manager->get_Active_Window() == "Craftingtable 1")
			{
				Craftingtable_1_Window(player, craftingtable, window_Manager);
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
	if (player->Get_Player_X() >= x &&
		player->Get_Player_X() <= x + 150 &&
		player->Get_Player_Y() >= y &&
		player->Get_Player_Y() <= y + SCRHEIGHT / 10 * z)
	{
		return true;
	}
	return false;
}


void Game_Manager::Location_Buttons_Pressed(Player* player, Window_Manager* window_Manager)
{
	if (Is_Mouse_Over_Location(player, 0, 50, 1))
	{
		window_Manager->set_Active_Window("Forest");
	}
	else if (Is_Mouse_Over_Location(player, 0, SCRHEIGHT / 10 * 1, 2))
	{
		window_Manager->set_Active_Window("Forge");
	}
}

void Game_Manager::Forest_Buttons(Player* player, Resource_Manager* resource_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		resource_Manager->Add_Resource_Quantity("SoftWood", player->Get_Stats("Lumberjack")->Get_Power());
		player->Get_Stats("Lumberjack")->Add_Exp(1);
	}
	if (Is_Mouse_Over_Standard(player, 160, 230) &&
		resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost() <= resource_Manager->Get_Resource_Quantity("SoftWood"))
	{
		resource_Manager->Get_Resource("SoftWood")->Add_Workers(1);
		resource_Manager->Get_Resource("SoftWood")->Update_Production_Rate();
		resource_Manager->Sub_Resource_Quantity("SoftWood", resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost());
		resource_Manager->Get_Resource("SoftWood")->Set_Worker_Cost(resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost() * 1.2);
	}
}

void Game_Manager::Forge_Buttons(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		window_Manager->set_Active_Window("Craftingtable 1");
	}
}

void Game_Manager::Craftingtable_1_Window(Player* player, Craftingtable_Manager* craftingtable, Window_Manager* window_Manager)
{
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 1 - 120, 160))
	{
		craftingtable->get_Craftingtable("Craftingtable 1")->Set_Resource("SoftWood");
	}
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 2 + 10, 160))
	{
		craftingtable->get_Craftingtable("Craftingtable 1")->Set_Blueprint("Axe");
	}
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, 160))
	{
		window_Manager->set_Active_Window("Forge");
	}
}

void Game_Manager::Check_All_Updates(double deltatime, Player* player, Resource_Manager* resource_Manager)
{
	Update_All_Per_Seccond_Events(deltatime, player, resource_Manager);
	Check_Level_Up(player);
	Check_Player_Stats(player);
}

void Game_Manager::Update_All_Per_Seccond_Events(double deltaTime, Player* player, Resource_Manager* resource_Manager)
{
	resource_Manager->Add_Resource_Quantity("SoftWood", resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate()* (deltaTime / 1000));
}

void Game_Manager::Check_Level_Up(Player* player)
{
	if (player->Get_Stats("Lumberjack")->Get_Exp() >= player->Get_Stats("Lumberjack")->Get_Exp_Needed())
	{
		player->Get_Stats("Lumberjack")->Add_Level(1);
		player->Get_Stats("Lumberjack")->Add_Exp_Needed(50);
		player->Get_Stats("Lumberjack")->Set_Exp(0);
	}
	if (player->Get_Stats("Crafting")->Get_Exp() >= player->Get_Stats("Crafting")->Get_Exp_Needed())
	{
		player->Get_Stats("Crafting")->Add_Level(1);
		player->Get_Stats("Crafting")->Add_Exp_Needed(50);
		player->Get_Stats("Crafting")->Set_Exp(0);
	}
}

void Game_Manager::Check_Player_Stats(Player* player)
{
	player->Get_Stats("Lumberjack")->Set_Power(player->Get_Stats("Lumberjack")->Get_Level());
	player->Get_Stats("Crafting")->Set_Power(player->Get_Stats("Crafting")->Get_Level());
}
