#include "precomp.h"
#include "UI.h"
#include "Resource_Manager.h"
#include "Player.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"
#include "Draft_Manager.h"
#include "Unlock_Manager.h"
#include "Tutorial.h"

UI::UI()
{
}

void UI::Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlock_Manager, Tutorial* tutorial)
{
	UI_Layout(screen, resource_Manager, unlock_Manager);
	tutorial->Draw_Tutorial_UI(screen, this);
	if (unlock_Manager->Get_Unlocked("Forest")->Get_Unlocked() &&
		window_Manager->get_Active_Window() == "Forest")
	{
		Forest_UI(screen, resource_Manager, player, item_Manager);
	}
	else if (
		(window_Manager->get_Active_Window() == "Forge" ||
		window_Manager->get_Active_Window() == "Craftingtable 1"))
	{
		Forge_UI(screen, resource_Manager, player, window_Manager, craftingtable, blueprint_Manager, item_Manager);
	}
	else if (window_Manager->get_Active_Window() == "Player" ||
		window_Manager->get_Active_Window() == "Lumberjack Tool" ||
		window_Manager->get_Active_Window() == "Crafting Tool" ||
		window_Manager->get_Active_Window() == "Mining Tool")
	{
		Player_UI(screen, window_Manager, item_Manager, player);
	}
	else if (window_Manager->get_Active_Window() == "Libary" ||
		window_Manager->get_Active_Window() == "Blueprint Upgrade" ||
		window_Manager->get_Active_Window() == "Blueprint Crafting")
	{
		Libary_UI(screen, resource_Manager, blueprint_Manager, player, window_Manager, draft_Manager);
	}
	else if (window_Manager->get_Active_Window() == "Witch Hut")
	{
		Witch_Hut_UI(screen, resource_Manager, blueprint_Manager, player, window_Manager, draft_Manager);
	}

}

void UI::UI_Layout(Surface* screen, Resource_Manager* resource_Manager, Unlock_Manager* unlock_Manager)
{
	screen->Line(0, 50, SCRWIDTH, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 1, 0, SCRWIDTH / 3 * 1, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 2, 0, SCRWIDTH / 3 * 2, 50, 0xFF00FF);
	// top tekst
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto hourglass = resource_Manager->Get_Resource("Hourglass");

	string tekst = "Thalions : " + to_string(static_cast<int>(round(thalions->Get_Quantity())));
	screen->Print(tekst.c_str(), (SCRWIDTH * 0 / 3) + 10, 20, 0xFF00FF, 2.5F);
	if (unlock_Manager->Get_Unlocked("Witch Hut")->Get_Unlocked())
	{
		tekst = "Hourglasses: " + to_string(static_cast<int>(round(hourglass->Get_Quantity()))) + "(" + to_string(static_cast<int>(round(hourglass->Get_Gain_On_Reset()))) + ")";
		screen->Print(tekst.c_str(), (SCRWIDTH * 1 / 3) + 10, 20, 0xFF00FF, 2.5F);
	}

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
	if (unlock_Manager->Get_Unlocked("Forge")->Get_Unlocked())
	{
		screen->Print("Forge", 50, SCRHEIGHT / 10 * 2, 0xFF00FF);
	}
	if (unlock_Manager->Get_Unlocked("Player")->Get_Unlocked())
	{
		screen->Print("Player", 50, SCRHEIGHT / 10 * 3, 0xFF00FF);
	}
	if (unlock_Manager->Get_Unlocked("Libary")->Get_Unlocked())
	{
		screen->Print("Libary", 50, SCRHEIGHT / 10 * 4, 0xFF00FF);
	}
	if (unlock_Manager->Get_Unlocked("Witch Hut")->Get_Unlocked())
	{
		screen->Print("Witch Hut", 50, SCRHEIGHT / 10 * 5, 0xFF00FF);
	}
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

	auto sorted_Item = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Lumberjack");
	if (!sorted_Item.empty() &&
		sorted_Item[0]->Get_Power() > resource_Manager->Get_Resource("SoftWood")->Get_Workers_Tool_Power())
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

	// info tekst
	string test = "Click Gather amount: " + to_string(static_cast<int>(player->Get_Stats("Lumberjack")->Get_Power()));
	string test2 = "Total workers " + to_string(static_cast<int>(resource_Manager->Get_Resource("SoftWood")->Get_Workers()));
	string test3 = "";
	string test4 = "Workers gather total: " + to_string(static_cast<int>(resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate()));

	if (resource_Manager->Get_Resource("SoftWood")->Get_Workers() >= 1)
	{
		test3 = "One Workers gathers: " + to_string(static_cast<int>(resource_Manager->Get_Resource("SoftWood")->Get_Production_Rate() / resource_Manager->Get_Resource("SoftWood")->Get_Workers()));
	}
	else
	{
		test3 = "One Workers gathers: 0";
	}

	screen->Print(test.c_str(), 360, 160, 0xFF00FF, 1.0F);
	screen->Print(test2.c_str(), 360, 170, 0xFF00FF, 1.0F);
	screen->Print(test3.c_str(), 360, 180, 0xFF00FF, 1.0F);
	screen->Print(test4.c_str(), 360, 190, 0xFF00FF, 1.0F);


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

		//Testing
		auto Sorted_Blueprints = blueprint_Manager->Get_Sorted_Blueprints_Numbers();
		auto sorted_Resources = resource_Manager->Get_Sorted_Resources_Numbers();

		for (size_t i = 0; i < Sorted_Blueprints.size(); i++)
		{
			int start_Y = 160;
			if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() == Sorted_Blueprints[i]->Get_Name())
			{
				button_Standard_Selected(Sorted_Blueprints[i]->Get_Name(), SCRWIDTH / 3 * 2 + 10, start_Y + (i * 60), screen);
				double number;
				string tekst = "Name: " + blueprint_Manager->Get_Blueprints(Sorted_Blueprints[i]->Get_Name())->Get_Name();
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 925, 0xFF00FF, 1.5F);

				number = std::round(blueprint_Manager->Get_Blueprints(Sorted_Blueprints[i]->Get_Name())->Get_Level());
				tekst = "Level: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 950, 0xFF00FF, 1.5F);

				number = std::round(blueprint_Manager->Get_Blueprints(Sorted_Blueprints[i]->Get_Name())->Get_Cost());
				tekst = "Cost: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), SCRWIDTH / 3 * 2 + 10, 975, 0xFF00FF, 1.5F);
			}
		else
			{
				button_Standard(Sorted_Blueprints[i]->Get_Name(), "", SCRWIDTH / 3 * 2 + 10, start_Y + (i * 60), screen);
			}
		}

		for (size_t i = 0; i < sorted_Resources.size(); i++)
		{
			int start_Y = 160;
			if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() == sorted_Resources[i]->Get_Name())
			{
				button_Standard_Selected(sorted_Resources[i]->Get_Name(), SCRWIDTH / 3 * 1 - 120, start_Y + (i * 60), screen);
				double number;
				string tekst = "Name: " + resource_Manager->Get_Resource(sorted_Resources[i]->Get_Name())->Get_Name();
				screen->Print(tekst.c_str(), 160, 925, 0xFF00FF, 1.5F);

				number = std::round(resource_Manager->Get_Resource(sorted_Resources[i]->Get_Name())->Get_Hardness());
				tekst = "Hardness: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), 160, 950, 0xFF00FF, 1.5F);
			}
			else
			{
				button_Standard(sorted_Resources[i]->Get_Name(), "", SCRWIDTH / 3 * 1 - 120, start_Y + (i * 60), screen);
			}
		}

		

		//resource selected show 
		auto table = craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource();
		if (table != "none")
		{
			screen->Print((string(resource_Manager->Get_Resource(table)->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource(table)->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);
		}

		// Buttons
		button_Standard("Close", "Craftingtable", SCRWIDTH / 2 - 50, 160, screen);
		

		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "none" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "none")
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
		button_Standard("Equip: ", "Crafting tool", 160, 120, screen);
		button_Standard("Equip: ", "Mining tool", 160, 180, screen);
	}
	else if (window == "Lumberjack Tool")
	{
		button_Standard_Selected("Lumberjack tool", 160, 60, screen);
		button_Standard("Equip: ", "Crafting tool", 160, 120, screen);
		button_Standard("Equip: ", "Mining tool", 160, 180, screen);

		screen->Box(SCRWIDTH / 2, 50, SCRWIDTH - 1, SCRHEIGHT - 1, 0x00FF00);

		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Lumberjack");
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
	else if (window == "Crafting Tool")
	{
		button_Standard("Equip: ", "Lumberjack tool", 160, 60, screen);
		button_Standard_Selected("Crafting tool", 160, 120, screen);
		button_Standard("Equip: ", "Mining tool", 160, 180, screen);

		screen->Box(SCRWIDTH / 2, 50, SCRWIDTH - 1, SCRHEIGHT - 1, 0x00FF00);

		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Crafting");
		double start_X = SCRWIDTH / 2 + 10;
		double start_Y = 115;
		double button_Hight = 55;

		string tekst = "Tool Equiped: " + player->Get_Stats("Crafting")->Get_Tool_Name() + "  Tool power: " + to_string(static_cast<int>(player->Get_Stats("Crafting")->Get_Tool_Power()));
		screen->Print(tekst.c_str(), start_X, start_Y - button_Hight, 0xFF00FF, 2.0F);

		for (double i = 0; i < sorted_Items.size(); i++)
		{
			Item* item = sorted_Items[i];
			string tekst = "power: " + to_string(static_cast<int>(item->Get_Power()));

			button_Standard(item->Get_Name().c_str(), tekst.c_str(),start_X, start_Y + i * button_Hight, screen);
		}
	}else if (window == "Mining Tool")
	{
		button_Standard("Equip: ", "Lumberjack tool", 160, 60, screen);
		button_Standard("Equip: ", "Crafting tool", 160, 120, screen);
		button_Standard_Selected("Mining Tool", 160, 180, screen);

		screen->Box(SCRWIDTH / 2, 50, SCRWIDTH - 1, SCRHEIGHT - 1, 0x00FF00);

		auto sorted_Items = item_Manager->get_Item_Sorted_By_Power_And_Equip_Slot("Mining");
		double start_X = SCRWIDTH / 2 + 10;
		double start_Y = 115;
		double button_Hight = 55;

		string tekst = "Tool Equiped: " + player->Get_Stats("Mining")->Get_Tool_Name() + "  Tool power: " + to_string(static_cast<int>(player->Get_Stats("Mining")->Get_Tool_Power()));
		screen->Print(tekst.c_str(), start_X, start_Y - button_Hight, 0xFF00FF, 2.0F);

		for (double i = 0; i < sorted_Items.size(); i++)
		{
			Item* item = sorted_Items[i];
			string tekst = "power: " + to_string(static_cast<int>(item->Get_Power()));

			button_Standard(item->Get_Name().c_str(), tekst.c_str(),start_X, start_Y + i * button_Hight, screen);
		}
	}
	
}

void UI::Libary_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* draft_Manager)
{
	{
		double level_Indicator = 150 + (player->Get_Stats("Scribe")->Get_Exp() / player->Get_Stats("Scribe")->Get_Exp_Needed() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = round(player->Get_Stats("Scribe")->Get_Exp());
		double player_Exp_Needed = round(player->Get_Stats("Scribe")->Get_Exp_Needed());
		string level_Idicator_Tekst = "Exp: " + to_string(static_cast<int>(round(player_Exp))) + " / Exp Needed: " + to_string(static_cast<int>(std::round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000, 2.0F);

		auto paper = resource_Manager->Get_Resource("Paper");
		auto softwood = resource_Manager->Get_Resource("SoftWood");
		double test1 = paper->Get_Quantity();
		string test2 = paper->Get_Name() + ": " + to_string(static_cast<int>(test1));
		screen->Print(test2.c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);
		test1 = softwood->Get_Quantity();
		test2 = softwood->Get_Name() + ": " + to_string(static_cast<int>(test1));
		screen->Print(test2.c_str(), 330, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);
		
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);

	if (window_Manager->get_Active_Window() == "Libary")
	{
		button_Standard("Craft Paper", "Cost 1000 SoftWood", 160, 160, screen); //craft paper knop

		button_Standard("Upgrade Blueprint", " ", SCRWIDTH / 2 - 50, 160, screen);

		button_Standard("Invent Blueprint", " ", SCRWIDTH / 2 + 80, 160, screen);
	}
	if (window_Manager->get_Active_Window() == "Blueprint Crafting")
	{
		
		screen->Box(160, 160, SCRWIDTH - 50, SCRHEIGHT - 50, 0x00FF00);
		screen->Box(170 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2, 170 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20) + (((SCRWIDTH - 60 - 170) - 20 * 2) / 3), SCRHEIGHT - 60, 0x0000FF);
		screen->Box(170 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20),SCRHEIGHT / 2,170 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20) + (((SCRWIDTH - 60 - 170) - 20 * 2) / 3),SCRHEIGHT - 60,0x0000FF);
		screen->Box(170 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20),SCRHEIGHT / 2,170 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20) + (((SCRWIDTH - 60 - 170) - 20 * 2) / 3),SCRHEIGHT - 60,0x0000FF);

		string card1_Name ="name: " + draft_Manager->Get_Blueprint_Card_1();
		string card1_Raity = "";
		string card1_Conversion = "Multiplier: " + to_string(static_cast<float>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_1())->Get_Conversion_Rate()));
		string card1_Cost = "Crafting Cost: " + to_string(static_cast<int>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_1())->Get_Cost()));

		string card2_Name = "name: " + draft_Manager->Get_Blueprint_Card_2();
		string card2_Raity = "";
		string card2_Conversion = "Multiplier: " + to_string(static_cast<float>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_2())->Get_Conversion_Rate()));
		string card2_Cost = "Crafting Cost: " + to_string(static_cast<int>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_2())->Get_Cost()));

		string card3_Name = "name: " + draft_Manager->Get_Blueprint_Card_3();
		string card3_Raity = "";
		string card3_Conversion = "Multiplier: " + to_string(static_cast<float>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_3())->Get_Conversion_Rate()));
		string card3_Cost = "Crafting Cost: " + to_string(static_cast<int>(blueprint_Manager->Get_Blueprints(draft_Manager->Get_Blueprint_Card_3())->Get_Cost()));

		// Card 1
		screen->Print(card1_Name.c_str(), 180 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 50, 0xFF00FF, 2.0F);
		screen->Print(card1_Conversion.c_str(), 180 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 100, 0xFF00FF, 2.0F);
		screen->Print(card1_Cost.c_str(), 180 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 150, 0xFF00FF, 2.0F);
			

		// Card 2
		screen->Print(card2_Name.c_str(), 180 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 50, 0xFF00FF, 2.0F);
		screen->Print(card2_Conversion.c_str(), 180 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 100, 0xFF00FF, 2.0F);
		screen->Print(card2_Cost.c_str(), 180 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 150, 0xFF00FF, 2.0F);

		// Card 3
		screen->Print(card3_Name.c_str(), 180 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 50, 0xFF00FF, 2.0F);
		screen->Print(card3_Conversion.c_str(), 180 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 100, 0xFF00FF, 2.0F);
		screen->Print(card3_Cost.c_str(), 180 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3) + 20), SCRHEIGHT / 2 + 150, 0xFF00FF, 2.0F);

		button_Standard("Unlock", "Cost: x", 380 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen);
		button_Standard("Unlock", "Cost: x", 380 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen);
		button_Standard("Unlock", "Cost: x", 380 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen);


	}

	if (window_Manager->get_Active_Window() == "Blueprint Upgrade")
	{
		screen->Box(160, 160, SCRWIDTH - 50, SCRHEIGHT - 50, 0x00FF00);
		
		

		auto sorted_Blueprints = blueprint_Manager->Get_Sorted_Blueprints_Numbers();
		for (size_t i = 0; i < sorted_Blueprints.size(); i++)
		{
			auto blueprints = blueprint_Manager->Get_Blueprints(sorted_Blueprints[i]->Get_Name());
			string test = "Name: " + blueprints->Get_Name();
			string test2 = "Level: " + to_string(static_cast<int>( blueprints->Get_Level()));
			string test3 = "Conversion rate: " + to_string( blueprints->Get_Conversion_Rate());
			
			string test4 = "Name: " + blueprints->Get_Name();
			string test5 = "Level: " + to_string(static_cast<int>( blueprints->Get_Level() + 1));
			string test6 = "Conversion rate: " + to_string( blueprints->Get_Conversion_Rate() + 0.1);

			string cost = "Cost: " + to_string(static_cast<int>(pow(2, blueprints->Get_Level() - 1)));

			int start_Y = 170;

			screen->Print(test.c_str(), 170, start_Y + (i * 60), 0xFF00FF, 1.0F);
			screen->Print(test2.c_str(), 170, start_Y + 10 + (i * 60), 0xFF00FF, 1.0F);
			screen->Print(test3.c_str(), 170, start_Y + 20 + (i * 60), 0xFF00FF, 1.0F);
			screen->Line(370, 195 + (i * 60), 470, 195 + (i * 60), 0xFF00FF);
			screen->Line(470, 195 + (i * 60), 445, 170 + (i * 60), 0xFF00FF);
			screen->Line(470, 195 + (i * 60), 445, 220 + (i * 60), 0xFF00FF);
			screen->Print(test4.c_str(), 570, start_Y + (i * 60), 0xFF00FF, 1.0F);
			screen->Print(test5.c_str(), 570, start_Y + 10 + (i * 60), 0xFF00FF, 1.0F);
			screen->Print(test6.c_str(), 570, start_Y + 20 + (i * 60), 0xFF00FF, 1.0F);
			button_Standard("Upgrade", cost.c_str(), 770, 170 + (i * 60), screen);
		}
	}
}

void UI::Witch_Hut_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager)
{
	screen->Print("Test", 500, 500, 0xFF00FF, 1.0F);
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

void UI::Arrow_Up(Surface* screen, int x1, int y1)
{
	screen->Line(x1, y1, x1, y1 + 50, 0xF0F0F0);
	screen->Line(x1, y1, x1 + 25, y1 + 25, 0xF0F0F0);
	screen->Line(x1, y1, x1 - 25, y1 + 25, 0xF0F0F0);
}

void UI::Arrow_Down(Surface* screen, int x1, int y1)
{
	screen->Line(x1, y1, x1, y1 - 50, 0xF0F0F0);
	screen->Line(x1, y1, x1 + 25, y1 - 25, 0xF0F0F0);
	screen->Line(x1, y1, x1 - 25, y1 - 25, 0xF0F0F0);
}

void UI::Arrow_Left(Surface* screen, int x1, int y1)
{
	screen->Line(x1, y1, x1 + 100, y1, 0xF0F0F0);
	screen->Line(x1, y1, x1 + 50, y1 - 25, 0xF0F0F0);
	screen->Line(x1, y1, x1 +50, y1 + 25, 0xF0F0F0);
}

void UI::Arrow_Right(Surface* screen, int x1, int y1)
{
	screen->Line(x1, y1, x1 - 100, y1, 0xF0F0F0);
	screen->Line(x1, y1, x1 - 50, y1 - 25, 0xF0F0F0);
	screen->Line(x1, y1, x1 - 50, y1 + 25, 0xF0F0F0);
}



