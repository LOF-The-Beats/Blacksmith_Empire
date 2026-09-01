#include "precomp.h"
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
#include "Ascension_Upgrades.h"
#include "Smelter_Manager.h"
#include "UI.h"

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

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void Game_Manager::If_Clicked(Player* player, UI* ui, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlock_Manager, Tutorial* tutorial, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Smelter_Manager* smelter_Manager)
{
	if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
	{
		if (!clicked)
		{
			Location_Buttons_Pressed(player, window_Manager, unlock_Manager);
			tutorial->Tutorial_Buttons(this, player, resource_Manager, craftingtable, unlock_Manager);
			
			if (window_Manager->get_Active_Window() == "Craftingtable")
			{
				Craftingtable_Window(player, craftingtable, window_Manager, blueprint_Manager, resource_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Lumberjack Tool" ||
				window_Manager->get_Active_Window() == "Crafting Tool" ||
				window_Manager->get_Active_Window() == "Mining Tool")
			{
				Lumberjack_Tool_Window(player, window_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Blueprint Crafting")
			{
				Blueprint_Crafting_Window(player, window_Manager, item_Manager, blueprint_Manager, draft_Manager, resource_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Blueprint Upgrade")
			{
				Blueprint_Upgrade_Window(player, window_Manager, item_Manager, blueprint_Manager, draft_Manager, resource_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Ascension Upgrade")
			{
				Ascension_Upgrade_Window(player, window_Manager, item_Manager, blueprint_Manager, draft_Manager, resource_Manager, ascension_Upgrade_Screen, ascension_Manager, craftingtable);
			}
			else if (window_Manager->get_Active_Window() == "Smelter")
			{
				Smelting_Window(player, window_Manager, item_Manager, blueprint_Manager, draft_Manager, resource_Manager, ascension_Upgrade_Screen, ascension_Manager, craftingtable, smelter_Manager);
			}

			if (window_Manager->get_Active_Window() == "Forest")
			{
				Forest_Buttons(player, resource_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Forge")
			{
				Forge_Buttons(player, resource_Manager, window_Manager, item_Manager, craftingtable, smelter_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Player")
			{
				Player_Buttons(player, window_Manager, item_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Libary")
			{
				Libary_Buttons(player, window_Manager, item_Manager, resource_Manager, draft_Manager, blueprint_Manager);
			}
			else if (window_Manager->get_Active_Window() == "Witch Hut")
			{
				Witch_Hut_Buttons(player, window_Manager, item_Manager, resource_Manager, craftingtable, draft_Manager, blueprint_Manager, ascension_Manager, ascension_Upgrade_Screen);
			}			
			else if (window_Manager->get_Active_Window() == "Mine")
			{
				Mine_Buttons(player, ui, resource_Manager, item_Manager);
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


void Game_Manager::Location_Buttons_Pressed(Player* player, Window_Manager* window_Manager, Unlock_Manager* unlock_Manager)
{
	if (unlock_Manager->Get_Unlocked("Forest")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 0))
	{
		window_Manager->set_Active_Window("Forest");
	}
	else if (unlock_Manager->Get_Unlocked("Forge")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 1))
	{
		window_Manager->set_Active_Window("Forge");
	}
	else if (unlock_Manager->Get_Unlocked("Player")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 2))
	{
		window_Manager->set_Active_Window("Player");
	}
	else if (unlock_Manager->Get_Unlocked("Libary")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 3))
	{
		window_Manager->set_Active_Window("Libary");
	}
	else if (unlock_Manager->Get_Unlocked("Witch Hut")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 4))
	{
		window_Manager->set_Active_Window("Witch Hut");
	}
	else if (unlock_Manager->Get_Unlocked("Mine")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 5))
	{
		window_Manager->set_Active_Window("Mine");
	}
	else if (unlock_Manager->Get_Unlocked("Dungeon")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 6))
	{
		window_Manager->set_Active_Window("Dungeon");
	}
	else if (unlock_Manager->Get_Unlocked("Settings")->Get_Unlocked() &&
		Is_Mouse_Over_Location(player, 0, 0, 7))
	{
		window_Manager->set_Active_Window("Settings");
	}
}

void Game_Manager::Forest_Buttons(Player* player, Resource_Manager* resource_Manager, Item_Manager* item_Manager)
{

	int x_Base = 150;
	int x_Increase = 425;
	int y_Base = 50;
	int increase_Multi = 0;
	string tekst;

	auto softWood = resource_Manager->Get_Resource("SoftWood");
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto lumberjack = player->Get_Stats("Lumberjack");
	
	auto all_Wood_Resources = resource_Manager->Get_All_Resources();

	for (size_t i = 0; i < all_Wood_Resources.size(); i++)
	{
		if (all_Wood_Resources[i]->Get_Name() == "SoftWood" ||
			all_Wood_Resources[i]->Get_Name() == "HardWood" ||
			all_Wood_Resources[i]->Get_Name() == "IronWood")
		{
			auto resource = all_Wood_Resources[i];
			auto item = item_Manager->Get_Item(resource->Get_Worker_Tool_Equiped());

			if (Is_Mouse_Over_Standard(player, x_Base + x_Increase / 2 + (x_Increase * increase_Multi), 160))
			{
				if (lumberjack->is_Crit())
				{
					resource->Add_Quantity(lumberjack->Get_Power() * lumberjack->Get_Crit_Power());
					lumberjack->Add_Exp(lumberjack->Get_Exp_Gain());
				}
				else
				{
					resource->Add_Quantity(lumberjack->Get_Power());
					lumberjack->Add_Exp(lumberjack->Get_Exp_Gain());
				}
			}

			if (Is_Mouse_Over_Standard(player, x_Base + x_Increase - 120 + (x_Increase * increase_Multi), 300) &&
					resource->Get_Worker_Cost() <= thalions->Get_Quantity())
			{

				if (resource->Get_Worker_Tool_Equiped() != "Tool" &&
					item->Get_Quantity() >= 1)
				{

					resource->Add_Workers(1);
					resource->Update_Production_Rate();
					thalions->Sub_Quantity(resource->Get_Worker_Cost());
					resource->Set_Worker_Cost(resource->Get_Worker_Cost() * 1.2);

					item->Sub_Quantity(1);
				}
				else if (resource->Get_Worker_Tool_Equiped() == "Tool")
				{
					resource->Add_Workers(1);
					resource->Update_Production_Rate();
					thalions->Sub_Quantity(resource->Get_Worker_Cost());
					resource->Set_Worker_Cost(resource->Get_Worker_Cost() * 1.2);
				}
			}

			if (Is_Mouse_Over_Standard(player, x_Base + x_Increase - 120 + (x_Increase * increase_Multi), 370))
			{
				auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Lumberjack");
				if (!sorted_Item.empty() &&
					sorted_Item[0]->Get_Power() > resource->Get_Workers_Tool_Power())
				{
					if (sorted_Item[0]->Get_Quantity() >= resource->Get_Workers())
					{
						sorted_Item[0]->Sub_Quantity(resource->Get_Workers());
						resource->Set_Workers_Tool_Power(sorted_Item[0]->Get_Power());
						resource->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

					}
				}
			}
			increase_Multi++;
		}
	}
}

void Game_Manager::Forge_Buttons(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Item_Manager* item_Manager, Craftingtable_Manager* craftingtable_Manager, Smelter_Manager* smelter_Manager)
{

	auto craftingtable = craftingtable_Manager->get_Craftingtable(craftingtable_Manager->Get_Active_Table());
	auto craftingtable1 = craftingtable_Manager->get_Craftingtable("Craftingtable 1");
	auto craftingtable2 = craftingtable_Manager->get_Craftingtable("Craftingtable 2");
	auto smelter1 = smelter_Manager->Get_Smelter("Smelter 1");
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto item_Craftingtable = item_Manager->Get_Item(craftingtable->Get_Worker_Tool_Equiped());
	auto item_Smelter = item_Manager->Get_Item(smelter1->Get_Worker_Tool_Equiped());
	if (Is_Mouse_Over_Standard(player, 160, 160) &&
		craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Unlocked())
	{
		window_Manager->set_Active_Window("Craftingtable");
		craftingtable_Manager->Set_Active_Table("Craftingtable 1");
	}

	if (Is_Mouse_Over_Standard(player, 340, 160) &&
		craftingtable2->Get_Unlocked())
	{
		window_Manager->set_Active_Window("Craftingtable");
		craftingtable_Manager->Set_Active_Table("Craftingtable 2");
	}

	if (Is_Mouse_Over_Standard(player, 160, 230) &&
		craftingtable1->Get_Worker_Cost() <= thalions->Get_Quantity())
	{
		
		if (craftingtable1->Get_Worker_Tool_Equiped() != "None" &&
			item_Craftingtable->Get_Quantity() >= 1)
		{

			craftingtable1->Add_Worker(1);
			craftingtable1->Update_Production_Rate();
			thalions->Sub_Quantity(craftingtable1->Get_Worker_Cost());
			craftingtable1->Set_Worker_Cost(craftingtable1->Get_Worker_Cost() * 1.2);

			item_Craftingtable->Sub_Quantity(1);
		}
		else if (craftingtable1->Get_Worker_Tool_Equiped() == "None")
		{
			craftingtable1->Add_Worker(1);
			craftingtable1->Update_Production_Rate();
			thalions->Sub_Quantity(craftingtable1->Get_Worker_Cost());
			craftingtable1->Set_Worker_Cost(craftingtable1->Get_Worker_Cost() * 1.2);
		}
	}

	if (Is_Mouse_Over_Standard(player, 340, 230) && craftingtable2->Get_Unlocked() &&
		craftingtable2->Get_Worker_Cost() <= thalions->Get_Quantity())
	{

		if (craftingtable2->Get_Worker_Tool_Equiped() != "None" &&
			item_Craftingtable->Get_Quantity() >= 1)
		{

			craftingtable2->Add_Worker(1);
			craftingtable2->Update_Production_Rate();
			thalions->Sub_Quantity(craftingtable2->Get_Worker_Cost());
			craftingtable2->Set_Worker_Cost(craftingtable2->Get_Worker_Cost() * 1.2);

			item_Craftingtable->Sub_Quantity(1);
		}
		else if (craftingtable2->Get_Worker_Tool_Equiped() == "None")
		{
			craftingtable2->Add_Worker(1);
			craftingtable2->Update_Production_Rate();
			thalions->Sub_Quantity(craftingtable2->Get_Worker_Cost());
			craftingtable2->Set_Worker_Cost(craftingtable2->Get_Worker_Cost() * 1.2);
		}
	}

	

	if (Is_Mouse_Over_Standard(player, 160, 300))
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Crafting");
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Worker_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Worker())
			{
				sorted_Item[0]->Sub_Quantity(craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Worker());
				craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Set_Worker_Tool_Power(sorted_Item[0]->Get_Power());
				craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}

	if (Is_Mouse_Over_Standard(player, 340, 300) && craftingtable2->Get_Unlocked())
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Crafting");
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Get_Worker_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Get_Worker())
			{
				sorted_Item[0]->Sub_Quantity(craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Get_Worker());
				craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Set_Worker_Tool_Power(sorted_Item[0]->Get_Power());
				craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 450))
	{
		window_Manager->set_Active_Window("Smelter");
		smelter_Manager->Set_Active_Smelter("Smelter 1");
	}

	if (Is_Mouse_Over_Standard(player, 160, 520) &&
		smelter1->Get_Worker_Cost() <= thalions->Get_Quantity())
	{
		if (smelter1->Get_Worker_Tool_Equiped() != "None" &&
			item_Smelter->Get_Quantity() >= 1)
		{

			smelter1->Add_Worker(1);
			smelter1->Update_Production_Rate();
			thalions->Sub_Quantity(smelter1->Get_Worker_Cost());
			smelter1->Set_Worker_Cost(smelter1->Get_Worker_Cost() * 1.2);

			item_Smelter->Sub_Quantity(1);
		}
		else if (smelter1->Get_Worker_Tool_Equiped() == "None")
		{
			smelter1->Add_Worker(1);
			smelter1->Update_Production_Rate();
			thalions->Sub_Quantity(smelter1->Get_Worker_Cost());
			smelter1->Set_Worker_Cost(smelter1->Get_Worker_Cost() * 1.2);
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 590))
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Crafting");
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > smelter1->Get_Worker_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= smelter1->Get_Workers())
			{
				sorted_Item[0]->Sub_Quantity(smelter1->Get_Workers());
				smelter1->Set_Worker_Tool_Power(sorted_Item[0]->Get_Power());
				smelter1->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 800))
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
	if (Is_Mouse_Over_Standard(player, 160, 120))
	{
		window_Manager->set_Active_Window("Crafting Tool");
	}
	if (Is_Mouse_Over_Standard(player, 160, 180))
	{
		window_Manager->set_Active_Window("Mining Tool");
	}
}

void Game_Manager::Libary_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager,Draft_Manager* draft_Manager, Blueprint_Manager* blueprint_Manager)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		auto softWood = resource_Manager->Get_Resource("SoftWood");
		auto paper = resource_Manager->Get_Resource("Paper");
		auto scribe = player->Get_Stats("Scribe");

		if (softWood->Get_Quantity() >= paper->Get_Hardness())
		{
			scribe->Add_Exp(scribe->Get_Exp_Gain());
			softWood->Sub_Quantity(paper->Get_Hardness());
			paper->Add_Quantity(1);
		}
	}

	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 + 80, 160))
	{
		window_Manager->set_Active_Window("Blueprint Crafting");
		draft_Manager->Draft_Blueprint_Cards(blueprint_Manager);
	}
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, 160))
	{
		window_Manager->set_Active_Window("Blueprint Upgrade");
	}



}

void Game_Manager::Witch_Hut_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable_Manager, Draft_Manager* draft_Manager, Blueprint_Manager* blueprint_Manager, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen)
{
	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		ascension_Manager->Ascend_Run(resource_Manager, blueprint_Manager, item_Manager, player, craftingtable_Manager, draft_Manager);
	}
	if (Is_Mouse_Over_Standard(player, 160, 220))
	{
		window_Manager->set_Active_Window("Ascension Upgrade");
		ascension_Upgrade_Screen->Set_Dragging(false);
		ascension_Upgrade_Screen->Set_Last_Mouse_X(player->Get_Player_X());
		ascension_Upgrade_Screen->Set_Last_Mouse_Y(player->Get_Player_Y());
		ascension_Upgrade_Screen->Center_On(500, 500);
	}
}

void Game_Manager::Mine_Buttons(Player* player, UI* ui, Resource_Manager* resource_Manager, Item_Manager* item_Manager)
{
	auto mining = player->Get_Stats("Mining");
	auto stone = resource_Manager->Get_Resource("Stone");
	auto tin = resource_Manager->Get_Resource("Tin Ore");
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto item = item_Manager->Get_Item(stone->Get_Worker_Tool_Equiped());

	if (Is_Mouse_Over_Standard(player, 1400, 160))
	{
		ui->currentPage++;

		if (ui->currentPage > ui->maxPage)
		{
			ui->currentPage = ui->maxPage;
		}
	}

	if (Is_Mouse_Over_Standard(player, 1400, 900))
	{
		ui->currentPage--;
		if (ui->currentPage < ui->minPage)
		{
			ui->currentPage = ui->minPage;
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 160))
	{
		if (mining->is_Crit())
		{
			stone->Add_Mined(mining->Get_Power() * mining->Get_Crit_Power() * stone->Get_Depth());
			mining->Add_Exp(mining->Get_Exp_Gain());
		}
		else
		{
			stone->Add_Mined(mining->Get_Power() * stone->Get_Depth());
			mining->Add_Exp(mining->Get_Exp_Gain());
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 230) &&
		stone->Get_Worker_Cost() <= thalions->Get_Quantity())
	{

		if (stone->Get_Worker_Tool_Equiped() != "Tool" &&
			item->Get_Quantity() >= 1)
		{

			stone->Add_Workers(1);
			stone->Update_Production_Rate();
			thalions->Sub_Quantity(stone->Get_Worker_Cost());
			stone->Set_Worker_Cost(stone->Get_Worker_Cost() * 1.2);

			item->Sub_Quantity(1);
		}
		else if (stone->Get_Worker_Tool_Equiped() == "Tool")
		{
			stone->Add_Workers(1);
			stone->Update_Production_Rate();
			thalions->Sub_Quantity(stone->Get_Worker_Cost());
			stone->Set_Worker_Cost(stone->Get_Worker_Cost() * 1.2);
		}
	}

	if (Is_Mouse_Over_Standard(player, 160, 300))
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Mining");
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > stone->Get_Workers_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= stone->Get_Workers())
			{
				sorted_Item[0]->Sub_Quantity(stone->Get_Workers());
				stone->Set_Workers_Tool_Power(sorted_Item[0]->Get_Power());
				stone->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}

	if (Is_Mouse_Over_Standard(player, 280, 160))
	{
		auto stone = resource_Manager->Get_Resource("Stone");

		stone->Add_Time(mining->Get_Power());
	}

	if (Is_Mouse_Over_Standard(player, 280, 230) &&
		stone->Get_Worker_Cost() <= thalions->Get_Quantity())
	{
		stone->Add_Collect_Workers(1);
		stone->Update_Collect_Rate();
		thalions->Sub_Quantity(stone->Get_Worker_Cost());
		stone->Set_Worker_Cost(stone->Get_Worker_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 280, 300) &&
		stone->Get_Collect_Cost() <= thalions->Get_Quantity())	
	{
		stone->Add_Collect_Workers_Tool_Power(1);
		stone->Update_Collect_Rate();
		thalions->Sub_Quantity(stone->Get_Collect_Cost());
		stone->Set_Collect_Cost(stone->Get_Collect_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 280, 370) &&
		stone->Get_Time_Upgrade_Cost() <= thalions->Get_Quantity()	)
	{
		stone->Add_Time_Escalaction(1);
		thalions->Sub_Quantity(stone->Get_Time_Upgrade_Cost());
		stone->Set_Time_Upgrade_Cost(stone->Get_Time_Upgrade_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 400, 160))
	{
		auto softwood = resource_Manager->Get_Resource("SoftWood");

		if (softwood->Get_Quantity() >= stone->Get_Depth_Cost())
		{
			softwood->Sub_Quantity(stone->Get_Depth_Cost());
			stone->Set_Depth_Cost(stone->Get_Depth_Cost() * 1.2);
			stone->Add_Depth(1);
			stone->Add_Collect_Time(10);
		}
	}

	//tin buttons
	if (Is_Mouse_Over_Standard(player, 600, 160))
	{
		if (mining->is_Crit())
		{
			tin->Add_Mined(mining->Get_Power() * mining->Get_Crit_Power() * tin->Get_Depth());
			mining->Add_Exp(mining->Get_Exp_Gain());
		}
		else
		{
			tin->Add_Mined(mining->Get_Power() * tin->Get_Depth());
			mining->Add_Exp(mining->Get_Exp_Gain());
		}
	}

	if (Is_Mouse_Over_Standard(player, 600, 230) &&
		tin->Get_Worker_Cost() <= thalions->Get_Quantity())
	{

		if (tin->Get_Worker_Tool_Equiped() != "Tool" &&
			item->Get_Quantity() >= 1)
		{

			tin->Add_Workers(1);
			stone->Update_Production_Rate();
			thalions->Sub_Quantity(tin->Get_Worker_Cost());
			stone->Set_Worker_Cost(tin->Get_Worker_Cost() * 1.2);

			item->Sub_Quantity(1);
		}
		else if (tin->Get_Worker_Tool_Equiped() == "Tool")
		{
			tin->Add_Workers(1);
			tin->Update_Production_Rate();
			thalions->Sub_Quantity(tin->Get_Worker_Cost());
			tin->Set_Worker_Cost(tin->Get_Worker_Cost() * 1.2);
		}
	}

	if (Is_Mouse_Over_Standard(player, 600, 300))
	{
		auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Mining");
		if (!sorted_Item.empty() &&
			sorted_Item[0]->Get_Power() > tin->Get_Workers_Tool_Power())
		{
			if (sorted_Item[0]->Get_Quantity() >= tin->Get_Workers())
			{
				sorted_Item[0]->Sub_Quantity(tin->Get_Workers());
				tin->Set_Workers_Tool_Power(sorted_Item[0]->Get_Power());
				tin->Set_Worker_Tool_Equiped(sorted_Item[0]->Get_Name());

			}
		}
	}

	if (Is_Mouse_Over_Standard(player, 720, 160))
	{
		tin->Add_Time(mining->Get_Power());
	}

	if (Is_Mouse_Over_Standard(player, 720, 230) &&
		tin->Get_Worker_Cost() <= thalions->Get_Quantity())
	{
		tin->Add_Collect_Workers(1);
		tin->Update_Collect_Rate();
		thalions->Sub_Quantity(tin->Get_Worker_Cost());
		tin->Set_Worker_Cost(tin->Get_Worker_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 720, 300) &&
		tin->Get_Collect_Cost() <= thalions->Get_Quantity())
	{
		tin->Add_Collect_Workers_Tool_Power(1);
		tin->Update_Collect_Rate();
		thalions->Sub_Quantity(tin->Get_Collect_Cost());
		tin->Set_Collect_Cost(tin->Get_Collect_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 720, 370) &&
		tin->Get_Time_Upgrade_Cost() <= thalions->Get_Quantity())
	{
		tin->Add_Time_Escalaction(1);
		thalions->Sub_Quantity(tin->Get_Time_Upgrade_Cost());
		tin->Set_Time_Upgrade_Cost(tin->Get_Time_Upgrade_Cost() * 1.2);
	}

	if (Is_Mouse_Over_Standard(player, 840, 160))
	{
		auto softwood = resource_Manager->Get_Resource("SoftWood");

		if (softwood->Get_Quantity() >= tin->Get_Depth_Cost())
		{
			softwood->Sub_Quantity(tin->Get_Depth_Cost());
			tin->Set_Depth_Cost(tin->Get_Depth_Cost() * 1.2);
			tin->Add_Depth(1);
			tin->Add_Collect_Time(10);
		}
	}
}

void Game_Manager::Craftingtable_Window(Player* player, Craftingtable_Manager* craftingtable, Window_Manager* window_Manager, Blueprint_Manager* blueprint_Manager, Resource_Manager* resource_Manager)
{

	auto sorted_Resources = resource_Manager->Get_Sorted_Resources_Numbers(Resources::Resource_Type::Crafting);

	auto craftingtables = craftingtable->get_Craftingtable(craftingtable->Get_Active_Table());
	int row = 0;
	for (size_t i = 0; i < sorted_Resources.size(); i++)
	{
		int start_Y = 160;
		if (Is_Mouse_Over_Standard(player, 160 + (120 * (i - row * 4)), start_Y + (row * 60)))
		{
			craftingtable->get_Craftingtable(craftingtable->Get_Active_Table())->Set_Resource(sorted_Resources[i]->Get_Name());
		}

		if ((i + 1) % 4 == 0)
		{
			row++;
		}
	}

	row = 0;
	auto sorted_Blueprints = blueprint_Manager->Get_Sorted_Blueprints_Numbers();
	for (size_t i = 0; i < sorted_Blueprints.size(); i++)
	{
		int start_Y = 160;
		if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 2 + 10 + (120 * (i - row * 4)), start_Y + (row * 60)))
		{
			craftingtable->get_Craftingtable(craftingtable->Get_Active_Table())->Set_Blueprint(sorted_Blueprints[i]->Get_Name());
		}

		if ((i + 1) % 4 == 0)
		{
			row++;
		}

	}

	
	
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, 160))
	{
		window_Manager->set_Active_Window("Forge");
	}
	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50) &&
		craftingtables->Get_Resource() != "none" &&
		craftingtables->Get_Blueprint() != "none" &&
		(blueprint_Manager->Get_Blueprints(craftingtables->Get_Blueprint())->Get_Cost() <= resource_Manager->Get_Resource(craftingtables->Get_Resource())->Get_Quantity() ||
			craftingtables->Get_In_Use()))
	{
		player->Get_Stats("Crafting")->Add_Exp(player->Get_Stats("Crafting")->Get_Exp_Gain());
		craftingtables->Add_Progress(player->Get_Stats("Crafting")->Get_Power());
		if (craftingtables->Get_In_Use() == false)
		{
			resource_Manager->Get_Resource(craftingtables->Get_Resource())->Sub_Quantity(blueprint_Manager->Get_Blueprints(craftingtables->Get_Blueprint())->Get_Cost());
		}
		craftingtables->Set_In_Use(true);
	}
}

void Game_Manager::Lumberjack_Tool_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager)
{

	if (Is_Mouse_Over_Standard(player, 160, 60))
	{
		window_Manager->set_Active_Window("Lumberjack Tool");
	}
	if (Is_Mouse_Over_Standard(player, 160, 120))
	{
		window_Manager->set_Active_Window("Crafting Tool");
	}
	if (Is_Mouse_Over_Standard(player, 160, 180))
	{
		window_Manager->set_Active_Window("Mining Tool");
	}

	if (window_Manager->get_Active_Window() == "Lumberjack Tool")
	{

		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Lumberjack");
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
	else if (window_Manager->get_Active_Window() == "Crafting Tool")
	{
		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Crafting");
		double start_X = SCRWIDTH / 2 + 10;
		double start_Y = 115;
		double button_Hight = 55;

		for (double i = 0; i < sorted_Items.size(); i++)
		{
			Item* item = sorted_Items[i];

			if (Is_Mouse_Over_Standard(player, start_X, start_Y + i * button_Hight))
			{
				auto stats = player->Get_Stats("Crafting");
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
	}else if (window_Manager->get_Active_Window() == "Mining Tool")
	{
		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Mining");
		double start_X = SCRWIDTH / 2 + 10;
		double start_Y = 115;
		double button_Hight = 55;

		for (double i = 0; i < sorted_Items.size(); i++)
		{
			Item* item = sorted_Items[i];

			if (Is_Mouse_Over_Standard(player, start_X, start_Y + i * button_Hight))
			{
				auto stats = player->Get_Stats("Mining");
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
	if (Is_Mouse_Over_Standard(player, 380 + 1 * (((SCRWIDTH - 60 - 170) - 20 * 2) / 3), SCRHEIGHT / 2 + 400) &&
		resource_Manager->Get_Resource("Paper")->Get_Quantity() >= draft_Manager->Get_Cost())
	{
		blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_2())->Set_Unlocked(true);
		draft_Manager->Draft_Blueprint_Cards(blueprint_Manager);
		resource_Manager->Get_Resource("Paper")->Sub_Quantity(draft_Manager->Get_Cost());
		draft_Manager->Calculate_Cost();
	}
	if (Is_Mouse_Over_Standard(player, 380 + 2 * (((SCRWIDTH - 60 - 170) - 20 * 2) / 3), SCRHEIGHT / 2 + 400) &&
		resource_Manager->Get_Resource("Paper")->Get_Quantity() >= draft_Manager->Get_Cost())
	{
		blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_3())->Set_Unlocked(true);
		draft_Manager->Draft_Blueprint_Cards(blueprint_Manager);
		resource_Manager->Get_Resource("Paper")->Sub_Quantity(draft_Manager->Get_Cost());
		draft_Manager->Calculate_Cost();
	}
}
void Game_Manager::Blueprint_Upgrade_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager)
{
	auto paper = resource_Manager->Get_Resource("Paper");
	auto sorted_Blueprints = blueprint_Manager->Get_Sorted_Blueprints_Numbers();
	for (size_t i = 0; i < sorted_Blueprints.size(); i++)
	{
		if (Is_Mouse_Over_Standard(player, 770, 170 + (i * 60)))
		{
			auto blueprints = blueprint_Manager->Get_Blueprints(sorted_Blueprints[i]->Get_Name());
			if (paper->Get_Quantity() >= pow(2, blueprints->Get_Level() - 1))
			{
				paper->Sub_Quantity(pow(2, blueprints->Get_Level() - 1));
				blueprints->Add_Level(1);
				blueprints->Add_Conversion_Rate(0.1);
			}
		}
	}

}

void Game_Manager::Ascension_Upgrade_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager, Craftingtable_Manager* craftingtable_Manager)
{
	ascension_Upgrade_Screen->Update_Drag(player);
	auto all_Upgrades = ascension_Manager->Get_All_Upgrades();

	for (size_t i = 0; i < all_Upgrades.size(); i++)
	{
		double world_X = all_Upgrades[i]->Get_World_X();
		double world_Y = all_Upgrades[i]->Get_World_Y();

		double screen_X = world_X - ascension_Upgrade_Screen->Get_Camera_X();
		double screen_Y = world_Y - ascension_Upgrade_Screen->Get_Camera_Y();

		if (ascension_Upgrade_Screen->Is_In_View(screen_X, screen_Y, 150, 50, SCRWIDTH / 3 * 2 - 150, 950))
		{
			if (Is_Mouse_Over_Standard(player, screen_X, screen_Y))
			{
				ascension_Manager->Buy_Upgrades(all_Upgrades[i]->Get_Name(),resource_Manager, player, craftingtable_Manager);
			}

		}
	}
}

void Game_Manager::Smelting_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager, Craftingtable_Manager* craftingtable_Manager, Smelter_Manager* smelter_Manager)
{
	auto sorted_Ore = resource_Manager->Get_Sorted_Resources_Numbers(Resources::Resource_Type::Ore);
	auto sorted_Fuel = resource_Manager->Get_Sorted_Resources_Numbers(Resources::Resource_Type::Fuel);
	auto active_Smelter = smelter_Manager->Get_Smelter(smelter_Manager->Get_Active_Smelter());
	auto smelting = player->Get_Stats("Smelting");
	int row = 0;
	int start_Y = 160;

	for (size_t i = 0; i < sorted_Fuel.size(); i++)
	{
		if (sorted_Fuel[i]->Check_Resource_Type(Resources::Resource_Type::Fuel))
		{
			if (Is_Mouse_Over_Standard(player, 160 + (120 * (i - row * 4)), start_Y + (row * 60)))
			{
				active_Smelter->Set_Fuel(sorted_Fuel[i]->Get_Name());
			}
			if ((i + 1) % 4 == 0)
			{
				row++;
			}
		}
	}
	row = 0;
	for (size_t i = 0; i < sorted_Ore.size(); i++)
	{
		if (sorted_Ore[i]->Check_Resource_Type(Resources::Resource_Type::Ore))
		{
			if (Is_Mouse_Over_Standard(player, SCRWIDTH / 3 * 2 + 10 + (120 * (i - row * 4)), start_Y + (row * 60)))
			{
				active_Smelter->Set_Ore(sorted_Ore[i]->Get_Name());
			}
			if ((i + 1) % 4 == 0)
			{
				row++;
			}
		}
	}

	if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, 160))
	{
		window_Manager->set_Active_Window("Forge");
	}

	if (active_Smelter->Get_Fuel() != "None" &&
		active_Smelter->Get_Ore() != "None")
	{
		if (Is_Mouse_Over_Standard(player, SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50))
		{
			if (resource_Manager->Get_Resource(active_Smelter->Get_Fuel())->Get_Quantity() >= 1)
			{
				active_Smelter->Add_Heat(resource_Manager->Get_Resource(active_Smelter->Get_Fuel())->Get_Heat_Minimal() / 100 * smelting->Get_Power());
				resource_Manager->Get_Resource(active_Smelter->Get_Fuel())->Sub_Quantity(smelting->Get_Power());
				player->Get_Stats("Smelting")->Add_Exp(player->Get_Stats("Smelting")->Get_Exp_Gain());
			}
		}
	}
}

void Game_Manager::Check_All_Updates(double deltatime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Unlock_Manager* unlock_Manger, Ascension_Manager* ascension_Manager, Smelter_Manager* smelter_Manager)
{
	Update_All_Per_Seccond_Events(deltatime, player, resource_Manager, craftingtable, blueprint_Manager, smelter_Manager);
	Check_Level_Up(player);
	Check_Player_Stats(player);
	Check_Craftingtable_Progress(resource_Manager, craftingtable, blueprint_Manager, item_Manager);
	Check_Smelter_Progress(smelter_Manager, resource_Manager);
	unlock_Manger->Check_Unlock(resource_Manager, player);
	ascension_Manager->Update_Gain_On_Reset(resource_Manager);

}

void Game_Manager::Update_All_Per_Seccond_Events(double deltaTime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable_Manager, Blueprint_Manager* blueprint_Manager, Smelter_Manager* smelter_Manager)
{
	auto all_Resources = resource_Manager->Get_All_Resources();
	auto all_Craftingtables = craftingtable_Manager->Get_All_Craftingtables();
	auto all_Smelters = smelter_Manager->Get_All_smelters();

	double delta_Seconds = deltaTime / 1000.0;
	double production_Multiplier = 1.0;

	if (player->Get_Timer() >= player->Get_Idle_Deep_Timer())
	{
		production_Multiplier = player->Get_Idle_Deep_Multiplier() * player->Get_Idle_Multiplier();
	}
	else if (player->Get_Timer() >= player->Get_Idle_Timer())
	{
		production_Multiplier = player->Get_Idle_Multiplier();
	}

	for (size_t i = 0; i < all_Resources.size(); i++)
	{
		auto resource = all_Resources[i];

		if (!resource)
		{
			continue;
		}

		resource->Update_Production_Rate();
		resource->Update_Collect_Rate();

		double amount = resource->Get_Production_Rate() * resource->Get_Depth() * production_Multiplier * delta_Seconds;

		if (resource->Get_Gathering_Destination() == "Mined")
		{
			resource->Add_Mined(amount);
		}
		else
		{
			resource->Add_Quantity(amount);
		}

		if (resource->Get_Collect_Time() <= resource->Get_Time() &&
			resource->Get_Mined() > (resource->Get_Collect_Rate() + player->Get_Stats("Mining")->Get_Power()) * production_Multiplier)
		{
			resource->Add_Quantity((resource->Get_Collect_Rate() + player->Get_Stats("Mining")->Get_Power()) * production_Multiplier);
			resource->Set_Mined(resource->Get_Mined() - ((resource->Get_Collect_Rate() + player->Get_Stats("Mining")->Get_Power()) * production_Multiplier));
			resource->Set_Time(0);
		}
		else if (resource->Get_Collect_Time() <= resource->Get_Time())
		{
			resource->Add_Quantity(resource->Get_Mined());
			resource->Set_Mined(0);
			resource->Set_Time(0);
		}
		else
		{
			resource->Add_Time(resource->Get_Time_Escalation() * delta_Seconds);
		}
	}

	for (size_t i = 0; i < all_Craftingtables.size(); i++)
	{
		auto table = all_Craftingtables[i];

		if (!table ||
			!table->Get_Unlocked() ||
			table->Get_Worker() < 1)
		{
			continue;
		}

		auto blueprint = blueprint_Manager->Get_Blueprints(table->Get_Blueprint());
		auto resource = resource_Manager->Get_Resource(table->Get_Resource());

		if (!blueprint || !resource)
		{
			continue;
		}

		bool can_Start = blueprint->Get_Cost() <= resource->Get_Quantity();

		if (!table->Get_In_Use() && !can_Start)
		{
			continue;
		}

		table->Update_Production_Rate();

		if (!table->Get_In_Use())
		{
			resource->Sub_Quantity(blueprint->Get_Cost());
			table->Set_In_Use(true);
		}

		table->Add_Progress(table->Get_Production_Rate() * production_Multiplier * delta_Seconds);
	}

	if (clicked)
	{
		player->Set_Timer(0);
	}
	else if (player->Get_Timer() < 60)
	{
		player->Add_Timer(delta_Seconds);
	}

	for (size_t i = 0; i < all_Smelters.size(); i++)
	{
		auto fuel = all_Smelters[i]->Get_Fuel();
		auto ore = all_Smelters[i]->Get_Ore();

		if (fuel == "None" || ore == "None")
		{
			continue;
		}

		if (all_Smelters[i]->Get_Heat() >= resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal())
		{
			if (resource_Manager->Get_Resource(ore)->Get_Quantity() >= 1)
			{
				all_Smelters[i]->Add_Progress(all_Smelters[i]->Get_Heat() / resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal() * delta_Seconds);
			}
			if (all_Smelters[i]->Get_Heat() > resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal() + 1)
			{
				all_Smelters[i]->Set_Heat_Loss(
					((all_Smelters[i]->Get_Heat() / resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal())
						+
						((all_Smelters[i]->Get_Heat() - resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal()) / 60)));
				all_Smelters[i]->Sub_Heat(all_Smelters[i]->Get_Heat_Loss() * delta_Seconds);
			}
		}

		if (all_Smelters[i]->Get_Workers() < 1)
		{
			continue;
		}

		if (all_Smelters[i]->Get_Production_Rate() <= resource_Manager->Get_Resource_Quantity(all_Smelters[i]->Get_Fuel()))
		{
			resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Sub_Quantity(all_Smelters[i]->Get_Production_Rate() * delta_Seconds);
			all_Smelters[i]->Add_Heat(resource_Manager->Get_Resource(all_Smelters[i]->Get_Fuel())->Get_Heat_Minimal() / 100 * all_Smelters[i]->Get_Production_Rate() * delta_Seconds);
		}

	}

}

void Game_Manager::Check_Level_Up(Player* player)
{

	auto lumberjack = player->Get_Stats("Lumberjack");
	auto crafting = player->Get_Stats("Crafting");
	auto mining = player->Get_Stats("Mining");
	auto all_Stats = player->Get_All_Stats();

	for (size_t i = 0; i < all_Stats.size(); i++)
	{
		if (all_Stats[i]->Get_Exp() >= all_Stats[i]->Get_Exp_Needed())
		{
			all_Stats[i]->Add_Level(all_Stats[i]->Get_Growth());
			all_Stats[i]->Add_Exp_Needed(50);
			all_Stats[i]->Set_Exp(0);
		}
	}
}

void Game_Manager::Check_Player_Stats(Player* player)
{
	auto all_Stats = player->Get_All_Stats();

	for (size_t i = 0; i < all_Stats.size(); i++)
	{
		all_Stats[i]->Set_Power((all_Stats[i]->Get_Level() + all_Stats[i]->Get_Ascension_Power()) * all_Stats[i]->Get_Tool_Power());
	}
}

void Game_Manager::Check_Craftingtable_Progress(Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager)
{
	auto all_Craftingtables = craftingtable->Get_All_Craftingtables();
	

	for (size_t i = 0; i < all_Craftingtables.size(); i++)
	{
		auto blueprint = blueprint_Manager->Get_Blueprints(all_Craftingtables[i]->Get_Blueprint());
		auto resource = resource_Manager->Get_Resource(all_Craftingtables[i]->Get_Resource());

		if (resource && blueprint && craftingtable->get_Craftingtable("Master Craftingtable")->Get_Mass_Production() && all_Craftingtables[i]->Get_Progress() >= resource->Get_Hardness())
		{
		
			while (all_Craftingtables[i]->Get_Progress() >= resource->Get_Hardness())
			{
				all_Craftingtables[i]->Set_Progress(all_Craftingtables[i]->Get_Progress() - resource->Get_Hardness());
				resource->Sub_Quantity(blueprint->Get_Cost());
				double level = blueprint->Get_Level();
				string combined_Name = all_Craftingtables[i]->Get_Resource() + " " + all_Craftingtables[i]->Get_Blueprint() + " Level: " + to_string(static_cast<int>(blueprint->Get_Level()));
				auto item = item_Manager->Get_Item(combined_Name);
				if (item)
				{
					item->Add_Quantity(1);
					all_Craftingtables[i]->Set_In_Use(false);
				}
				else
				{
					item_Manager->Add_Item(combined_Name, all_Craftingtables[i]->Get_Resource(), all_Craftingtables[i]->Get_Blueprint(), blueprint->Get_Equip_Slot(), blueprint->Get_Level(), resource->Get_Hardness() * blueprint->Get_Level() * (blueprint->Get_Cost() / resource->Get_Hardness()), resource->Get_Hardness() * blueprint->Get_Conversion_Rate());
					all_Craftingtables[i]->Set_In_Use(false);
				}
			}
			all_Craftingtables[i]->Set_Progress(0);
		}
		else if (resource && blueprint && all_Craftingtables[i]->Get_Progress() >= resource->Get_Hardness())
		{
			all_Craftingtables[i]->Set_Progress(0);
			double level = blueprint->Get_Level();
			string combined_Name = all_Craftingtables[i]->Get_Resource() + " " + all_Craftingtables[i]->Get_Blueprint() + " Level: " + to_string(static_cast<int>(blueprint->Get_Level()));
			auto item = item_Manager->Get_Item(combined_Name);
			if (item)
			{
				item->Add_Quantity(1);
				all_Craftingtables[i]->Set_In_Use(false);
			}
			else
			{
				item_Manager->Add_Item(combined_Name, all_Craftingtables[i]->Get_Resource(), all_Craftingtables[i]->Get_Blueprint(), blueprint->Get_Equip_Slot(), blueprint->Get_Level(), resource->Get_Hardness() * blueprint->Get_Level() * blueprint->Get_value(), resource->Get_Hardness() * blueprint->Get_Conversion_Rate());
				all_Craftingtables[i]->Set_In_Use(false);
			}
		}
	}
}

void Game_Manager::Check_Smelter_Progress(Smelter_Manager* smelter_Manager, Resource_Manager* resource_Manager)
{
	auto all_Smelters = smelter_Manager->Get_All_smelters();
	auto all_Resources = resource_Manager->Get_All_Resources();

	for (size_t i = 0; i < all_Smelters.size(); i++)
	{

		if (all_Smelters[i]->Get_Fuel() != "None" &&
			all_Smelters[i]->Get_Ore() != "None")
		
		{
		auto smelting_Output = resource_Manager->Get_Resource(all_Smelters[i]->Get_Ore())->Get_Smelting_Output();
		auto smelting_Input = resource_Manager->Get_Resource(all_Smelters[i]->Get_Ore())->Get_Name();
			if (all_Smelters[i]->Get_Progress() >= 60)
			{
				all_Smelters[i]->Set_Progress(0);
				resource_Manager->Get_Resource(smelting_Output)->Add_Quantity(1);
				resource_Manager->Get_Resource(smelting_Input)->Sub_Quantity(1);
			}
		}
	}
}
