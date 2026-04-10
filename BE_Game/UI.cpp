#include "precomp.h"
#include "UI.h"
#include "Resource_Manager.h"
#include "Player.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"

UI::UI()
{
}

void UI::Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager)
{
	UI_Layout(screen, resource_Manager);
	if (window_Manager->get_Active_Window() == "Forest")
	{
		Forest_UI(screen, resource_Manager, player, item_Manager);
	}
	else if (window_Manager->get_Active_Window() == "Forge" ||
		window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		Forge_UI(screen, resource_Manager, player, window_Manager, craftingtable, blueprint_Manager, item_Manager);
	}
	else if (window_Manager->get_Active_Window() == "Player" ||
		window_Manager->get_Active_Window() == "Lumberjack Tool")
	{
		Player_UI(screen, window_Manager, item_Manager, player);
	}
	else if (window_Manager->get_Active_Window() == "Libary")
	{
		Libary_UI(screen, resource_Manager, blueprint_Manager, player);
	}

}

void UI::UI_Layout(Surface* screen, Resource_Manager* resource_Manager)
{
	screen->Line(0, 50, SCRWIDTH, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 1, 0, SCRWIDTH / 3 * 1, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 2, 0, SCRWIDTH / 3 * 2, 50, 0xFF00FF);
	// top tekst
	auto resource = resource_Manager->Get_Resource("Thalions");
	string tekst = "Thalions : " + to_string(static_cast<int>(round(resource->Get_Quantity())));
	screen->Print(tekst.c_str(), 10, 20, 0xFF00FF, 2.5F);

	// left bar
	screen->Line(150, 50, 150, SCRHEIGHT, 0xFF00FF);
	// Locaton buttons
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 1 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 2 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 3 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 4 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 5 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 6 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 7 + 50, 0xFF00FF);
	screen->Box(0, 50, 150, SCRHEIGHT / 10 * 8 + 50, 0xFF00FF);

	screen->Print("Forest", 50, SCRHEIGHT / 10 * 1, 0xFF00FF);
	screen->Print("Forge", 50, SCRHEIGHT / 10 * 2, 0xFF00FF);
	screen->Print("Player", 50, SCRHEIGHT / 10 * 3, 0xFF00FF);
	screen->Print("Libary", 50, SCRHEIGHT / 10 * 4, 0xFF00FF);
}

void UI::Forest_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Item_Manager* item_Manager)
{

	// draws the level progress bar
	{
		double level_Indicator = 150 + (player->Get_Stats("Lumberjack")->Get_Exp() / player->Get_Stats("Lumberjack")->Get_Exp_Needed() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = round(player->Get_Stats("Lumberjack")->Get_Exp());
		double player_Exp_Needed = round(player->Get_Stats("Lumberjack")->Get_Exp_Needed());
		string level_Idicator_Tekst = "Exp: " + to_string(static_cast<int>(round(player_Exp))) + " / Exp Needed: " + to_string(static_cast<int>(std::round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000 , 2.0F);
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);


	button_Standard("Gather", "", 160, 160, screen); //gather resource knop
	
	double cost =  round(resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost());
	string label = "Cost: " + std::to_string(static_cast<int>(std::round(cost))) + " " + resource_Manager->Get_Resource("Thalions")->Get_Name() + " 1 " + resource_Manager->Get_Resource("SoftWood")->Get_Worker_Tool_Equiped();
	button_Standard("Buy Worker", label.c_str(), 160, 230, screen); // buy worker

	auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Name();
	if (!sorted_Item.empty())
	{
		cost = resource_Manager->Get_Resource("SoftWood")->Get_Workers();
		label = "Cost: " + std::to_string(static_cast<int>(std::round(cost))) + " " + sorted_Item[0]->Get_Name();
	}
	else
	{
		
		label = "No Upgrades Available ";
	}
	button_Standard("Upgrade tools", label.c_str(), 160, 300, screen); // upgrade tools


	screen->Print((string(resource_Manager->Get_Resource("SoftWood")->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource("SoftWood")->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);

}

void UI::Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager)
{
	// draws the level progress bar
	{
		double level_Indicator = 150 + (player->Get_Stats("Crafting")->Get_Exp() / player->Get_Stats("Crafting")->Get_Exp_Needed() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = round(player->Get_Stats("Crafting")->Get_Exp());
		double player_Exp_Needed = round(player->Get_Stats("Crafting")->Get_Exp_Needed());
		string level_Idicator_Tekst = "Exp: " + to_string(static_cast<int>(round(player_Exp))) + " / Exp Needed: " + to_string(static_cast<int>(round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000, 2.0F);
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);

	if (window_Manager->get_Active_Window() == "Forge")
	{
		button_Standard("Crafting table", "", 160, 160, screen);
		button_Standard("Sell", "All Items", 160, 300, screen);
	}
	if (window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		// layout of craftingtable
		screen->Line(SCRWIDTH / 3 * 1, 150, SCRWIDTH / 3 * 1, SCRHEIGHT, 0xFF00FF);
		screen->Line(SCRWIDTH / 3 * 2, 150, SCRWIDTH / 3 * 2, SCRHEIGHT, 0xFF00FF);
		screen->Line(100, SCRHEIGHT / 10 * 8 + 50, SCRWIDTH, SCRHEIGHT / 10 * 8 + 50, 0xFF00FF);

		//resource selected show 
		auto table = craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource();
		if (table != "none")
		{
			screen->Print((string(resource_Manager->Get_Resource(table)->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource(table)->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);
		}

		// Buttons
		button_Standard("Close", "Craftingtable", SCRWIDTH / 2 - 50, 160, screen);
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() == "SoftWood")
		{
			button_Standard_Selected("SoftWood", SCRWIDTH / 3 * 1 - 120, 160, screen);
			double number;
			string tekst = "Name: " + resource_Manager->Get_Resource("SoftWood")->Get_Name();
			screen->Print(tekst.c_str(), 160, 925, 0xFF00FF, 1.5F);

			number = std::round(resource_Manager->Get_Resource("SoftWood")->Get_Hardness());
			tekst = "Hardness: " + to_string(static_cast<int>(number));
			screen->Print(tekst.c_str(), 160, 950, 0xFF00FF, 1.5F);
		}
		else
		{
			button_Standard("SoftWood", "", SCRWIDTH / 3 * 1 - 120, 160, screen);
		}
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() == "Axe")
		{
			button_Standard_Selected("Axe", SCRWIDTH / 3 * 2 + 10, 160, screen);
			double number;
			string tekst = "Name: " + blueprint_Manager->Get_Blueprints("Axe")->Get_Name();
			screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 925, 0xFF00FF, 1.5F);

			number = std::round(blueprint_Manager->Get_Blueprints("Axe")->Get_Level());
			tekst = "Level: " + to_string(static_cast<int>(number));
			screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 950, 0xFF00FF, 1.5F);

			number = std::round(blueprint_Manager->Get_Blueprints("Axe")->Get_Cost());
			tekst = "Cost: " + to_string(static_cast<int>(number));
			screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 975, 0xFF00FF, 1.5F);
		}
		else
		{
			button_Standard("Axe", "", SCRWIDTH / 3 * 2 + 10, 160, screen);
		}

		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() == "SoftWood" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() == "Axe")
		{
			auto table = craftingtable->get_Craftingtable("Craftingtable 1");
			auto blueprint = blueprint_Manager->Get_Blueprints(table->Get_Blueprint());
			auto resource = resource_Manager->Get_Resource(table->Get_Resource());
			string combined_Name = table->Get_Resource() + " " + table->Get_Blueprint() + " " + to_string(static_cast<int>(blueprint->Get_Level()));
			auto item = item_Manager->Get_Item(combined_Name);

			double number;
			string tekst = "Name: " + combined_Name;
			screen->Print(tekst.c_str(), SCRWIDTH / 3 * 1 + 10, 925, 0xFF00FF, 1.5F);

			if (item)
			{
				number = std::round(item->Get_Power());
				tekst = "Power: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 1 + 10, 950, 0xFF00FF, 1.5F);

				number = std::round(item->Get_Quantity());
				tekst = "Quantity: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 1 + 10, 975, 0xFF00FF, 1.5F);
			}
			else
			{
				tekst = "Power: Unknown";
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 1 + 10, 950, 0xFF00FF, 1.5F);
				
				tekst = "Quantity: 0";
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 1 + 10, 975, 0xFF00FF, 1.5F);
			}

			
		}
		
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "none" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "none")
		{
			screen->Bar(SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50, SCRWIDTH / 2 - 50 + (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Progress() / resource_Manager->Get_Resource(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource())->Get_Hardness() * 110), SCRHEIGHT / 10 * 8, 0x00FF00);
			button_Standard("Craft", "", SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50, screen);
			
		}

	}
}

void UI::Player_UI(Surface* screen, Window_Manager* window_Manager, Item_Manager* item_Manager, Player* player)
{
	auto window = window_Manager->get_Active_Window();
	if (window == "Player")
	{
		button_Standard("Equip: ", "Lumberjack tool", 160, 60, screen);
	}
	else if (window == "Lumberjack Tool")
	{
		button_Standard_Selected("Lumberjack tool", 160, 60, screen);

		screen->Box(SCRWIDTH / 2, 50, SCRWIDTH - 1, SCRHEIGHT - 1, 0x00FF00);

		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Name();
		double start_X = SCRWIDTH / 2 + 10;
		double start_Y = 115;
		double button_Hight = 55;

		string tekst = "Tool Equiped: " + player->Get_Stats("Lumberjack")->Get_Tool_Name() + "  Tool power: " + to_string(static_cast<int>(player->Get_Stats("Lumberjack")->Get_Tool_Power()));
		screen->Print(tekst.c_str(), start_X, start_Y - button_Hight, 0xFF00FF, 2.0F);

		for (double i = 0; i < sorted_Items.size(); i++)
		{
			Item* item = sorted_Items[i];
			string tekst = "power: " + to_string(static_cast<int>(item->Get_Power()));

			button_Standard(item->Get_Name().c_str(), tekst.c_str(),start_X, start_Y + i * button_Hight, screen);
		}
	}
	
}

void UI::Libary_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player)
{
	{
		double level_Indicator = 150 + (player->Get_Stats("Scribe")->Get_Exp() / player->Get_Stats("Scribe")->Get_Exp_Needed() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = round(player->Get_Stats("Scribe")->Get_Exp());
		double player_Exp_Needed = round(player->Get_Stats("Scribe")->Get_Exp_Needed());
		string level_Idicator_Tekst = "Exp: " + to_string(static_cast<int>(round(player_Exp))) + " / Exp Needed: " + to_string(static_cast<int>(std::round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000, 2.0F);
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);

	button_Standard("Craft Paper", "Cost 1000 SoftWood", 160, 160, screen); //craft paper knop

	button_Standard("Upgrade Blueprint", " ", SCRWIDTH / 2 - 50, 160, screen);
}

void UI::button_Standard(string name, string cost, int x1, int y1, Surface* screen)
{
	screen->Box(x1, y1, x1 + 110, y1 + 50, 0xFF00FF);
	screen->Print(name.c_str(), x1 + 20, y1 + 22, 0xFF00FF);
	screen->Print(cost.c_str(), x1 + 5, y1 + 30, 0xFF00FF);
}

void UI::button_Standard_Selected(string name, int x1, int y1, Surface* screen)
{
	screen->Bar(x1, y1, x1 + 110, y1 + 50, 0xFF00FF);
	screen->Print(name.c_str(), x1 + 20, y1 + 22, 0xFFFFFF);
}



