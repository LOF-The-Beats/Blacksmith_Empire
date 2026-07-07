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
#include "Ascension_Upgrade_Screen.h"
#include "Ascension_Manager.h"
#include "Ascension_Upgrades.h"

extern GLFWwindow* window;

UI::UI()
{
}

void UI::Draw_UI(Surface* screen,Surface* resource_Icon_Sheet, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlock_Manager, Tutorial* tutorial, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager)
{
	UI_Layout(screen, resource_Icon_Sheet, resource_Manager, unlock_Manager, window_Manager);
	tutorial->Draw_Tutorial_UI(screen, this, player, window_Manager);
	if (unlock_Manager->Get_Unlocked("Forest")->Get_Unlocked() &&
		window_Manager->get_Active_Window() == "Forest")
	{
		Forest_UI(screen, resource_Icon_Sheet, resource_Manager, player, item_Manager, window_Manager);
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
	else if (window_Manager->get_Active_Window() == "Witch Hut" ||
		window_Manager->get_Active_Window() == "Ascension Upgrade")
	{
		Witch_Hut_UI(screen, resource_Manager, blueprint_Manager, player, window_Manager, draft_Manager, ascension_Upgrade_Screen, ascension_Manager);
	}

}

void UI::UI_Layout(Surface* screen,Surface* resource_Icon_Sheet, Resource_Manager* resource_Manager, Unlock_Manager* unlock_Manager, Window_Manager* window_Manager)
{
	screen->Bar(0, 0, SCRWIDTH, 50, 0x120018);
	screen->Line(0, 50, SCRWIDTH, 50, 0x6A0DAD);
	screen->Line(SCRWIDTH / 3 * 1, 0, SCRWIDTH / 3 * 1, 50, 0x6A0DAD);
	screen->Line(SCRWIDTH / 3 * 2, 0, SCRWIDTH / 3 * 2, 50, 0x6A0DAD);
	// top tekst
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto hourglass = resource_Manager->Get_Resource("Hourglass");

	string tekst = "Thalions : " + to_string(static_cast<int>(round(thalions->Get_Quantity())));
	draw_Resource_Icons(screen, "Thalions", 30, 17, 2, resource_Icon_Sheet);
	screen->Print(tekst.c_str(), (SCRWIDTH * 0 / 3) + 30, 20, 0xFF00FF, 2.5F);
	if (unlock_Manager->Get_Unlocked("Witch Hut")->Get_Unlocked())
	{
		tekst = "Hourglasses: " + to_string(static_cast<int>(round(hourglass->Get_Quantity()))) + "(" + to_string(static_cast<int>(round(hourglass->Get_Gain_On_Reset()))) + ")";
		screen->Print(tekst.c_str(), (SCRWIDTH * 1 / 3) + 10, 20, 0xFF00FF, 2.5F);
	}

	// left bar background
	screen->Bar(0, 50, 150, SCRHEIGHT -1, 0x0A0710);
	screen->Line(150, 50, 150, SCRHEIGHT - 1, 0x6A0DAD);

	int tab_X = 0;
	int tab_Y = 60;
	int tab_H = SCRHEIGHT / 10;

	if (window_Manager->get_Active_Window() == "Forest")
		button_Tab_Selected("Forest", tab_X, tab_Y + (0 * tab_H), screen);
	else
		button_Tab("Forest", tab_X, tab_Y + (0 * tab_H), screen);

	if (unlock_Manager->Get_Unlocked("Forge")->Get_Unlocked())
	{
		if (window_Manager->get_Active_Window() == "Forge")
			button_Tab_Selected("Forge", tab_X, tab_Y + (1 * tab_H), screen);
		else
			button_Tab("Forge", tab_X, tab_Y + (1 * tab_H), screen);
	}

	if (unlock_Manager->Get_Unlocked("Player")->Get_Unlocked())
	{
		if (window_Manager->get_Active_Window() == "Player")
			button_Tab_Selected("Player", tab_X, tab_Y + (2 * tab_H), screen);
		else
			button_Tab("Player", tab_X, tab_Y + (2 * tab_H), screen);
	}

	if (unlock_Manager->Get_Unlocked("Libary")->Get_Unlocked())
	{
		if (window_Manager->get_Active_Window() == "Libary")
			button_Tab_Selected("Libary", tab_X, tab_Y + (3 * tab_H), screen);
		else
			button_Tab("Libary", tab_X, tab_Y + (3 * tab_H), screen);
	}

	if (unlock_Manager->Get_Unlocked("Witch Hut")->Get_Unlocked())
	{
		if (window_Manager->get_Active_Window() == "Witch Hut")
			button_Tab_Selected("Witch Hut", tab_X, tab_Y + (4 * tab_H), screen);
		else
			button_Tab("Witch Hut", tab_X, tab_Y + (4 * tab_H), screen);
	}
}

void UI::Forest_UI(Surface* screen, Surface* resource_Icon_Sheet, Resource_Manager* resource_Manager, Player* player, Item_Manager* item_Manager, Window_Manager* window_Manager)
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


	string test = "Click Gather amount: " + to_string(static_cast<int>(player->Get_Stats("Lumberjack")->Get_Power()));
	button_Standard("Gather", "", test.c_str(), 160, 160, screen, window_Manager, player); //gather resource knop
	
	double cost =  round(resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost());
	string label = "Cost: " + std::to_string(static_cast<int>(std::round(cost))) + " " + resource_Manager->Get_Resource("Thalions")->Get_Name() + " 1 " + resource_Manager->Get_Resource("SoftWood")->Get_Worker_Tool_Equiped();
	button_Standard("Buy Worker", label.c_str(), "", 160, 230, screen, window_Manager, player); // buy worker

	button_Standard("Upgrade tools", "", "", 160, 300, screen, window_Manager, player); // upgrade tools

	draw_Resource_Icons(screen, "SoftWood", 180, SCRHEIGHT / 30 * 1 + 35, 1, resource_Icon_Sheet);
	screen->Print((string(resource_Manager->Get_Resource("SoftWood")->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource("SoftWood")->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);

	// info tekst
	
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
		button_Standard("Crafting table", "", "", 160, 160, screen, window_Manager, player);
		button_Standard("Buy Worker", "", "", 160, 230, screen, window_Manager, player);
		button_Standard("Upgrade Tools", "", "", 160, 300, screen, window_Manager, player);
		button_Standard("Sell all items", "", "", 160, 600, screen, window_Manager, player);
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
				button_Standard_Selected(Sorted_Blueprints[i]->Get_Name(), SCRWIDTH / 3 * 2 + 10, start_Y + (i * 60), window_Manager, screen);
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
				button_Standard(Sorted_Blueprints[i]->Get_Name(), "", "", SCRWIDTH / 3 * 2 + 10, start_Y + (i * 60), screen, window_Manager, player);
			}
		}

		for (size_t i = 0; i < sorted_Resources.size(); i++)
		{
			int start_Y = 160;
			if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() == sorted_Resources[i]->Get_Name())
			{
				button_Standard_Selected(sorted_Resources[i]->Get_Name(), SCRWIDTH / 3 * 1 - 120, start_Y + (i * 60), window_Manager, screen);
				double number;
				string tekst = "Name: " + resource_Manager->Get_Resource(sorted_Resources[i]->Get_Name())->Get_Name();
				screen->Print(tekst.c_str(), 160, 925, 0xFF00FF, 1.5F);

				number = std::round(resource_Manager->Get_Resource(sorted_Resources[i]->Get_Name())->Get_Hardness());
				tekst = "Hardness: " + to_string(static_cast<int>(number));
				screen->Print(tekst.c_str(), 160, 950, 0xFF00FF, 1.5F);
			}
			else
			{
				button_Standard(sorted_Resources[i]->Get_Name(), "", "", SCRWIDTH / 3 * 1 - 120, start_Y + (i * 60), screen, window_Manager, player);
			}
		}

		

		//resource selected show 
		auto table = craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource();
		if (table != "None")
		{
			screen->Print((string(resource_Manager->Get_Resource(table)->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource(table)->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);
		}

		// Buttons
		button_Standard("Close", "", "", SCRWIDTH / 2 - 50, 160, screen, window_Manager, player);
		

		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "None" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "None")
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
		
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "None" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "None")
		{
			screen->Bar(SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50, SCRWIDTH / 2 - 50 + (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Progress() / resource_Manager->Get_Resource(craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource())->Get_Hardness() * 110), SCRHEIGHT / 10 * 8, 0x00FF00);
			button_Standard("Craft", "", "", SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50, screen, window_Manager, player);
			
		}

	}
}

void UI::Player_UI(Surface* screen, Window_Manager* window_Manager, Item_Manager* item_Manager, Player* player)
{
	auto window = window_Manager->get_Active_Window();
	if (window == "Player")
	{
		button_Standard("Lumberjack tool", "", "", 160, 60, screen, window_Manager, player);
		button_Standard("Crafting Tool", "", "", 160, 120, screen, window_Manager, player);
		button_Standard("Mining Tool", "", "", 160, 180, screen, window_Manager, player);
	}
	else if (window == "Lumberjack Tool")
	{
		button_Standard_Selected("Lumberjack tool", 160, 60, window_Manager, screen);
		button_Standard("Crafting Tool", "", "", 160, 120, screen, window_Manager, player);
		button_Standard("Mining Tool", "", "", 160, 180, screen, window_Manager, player);

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

			button_Standard(item->Get_Name().c_str(), "", "", start_X, start_Y + i * button_Hight, screen, window_Manager, player);
		}
	}
	else if (window == "Crafting Tool")
	{
		button_Standard("Lumberjack tool", "", "", 160, 60, screen, window_Manager, player);
		button_Standard_Selected("Crafting tool", 160, 120, window_Manager, screen);
		button_Standard("Mining Tool", "", "", 160, 180, screen, window_Manager, player);

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

			button_Standard(item->Get_Name().c_str(),"", "", start_X, start_Y + i * button_Hight, screen, window_Manager, player);
		}
	}else if (window == "Mining Tool")
	{
		button_Standard("Lumberjack tool","", "", 160, 60, screen, window_Manager, player);
		button_Standard("Crafting Tool", "", "",  160, 120, screen, window_Manager, player);
		button_Standard_Selected("Mining Tool", 160, 180, window_Manager, screen);

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

			button_Standard(item->Get_Name().c_str(), "", "", start_X, start_Y + i * button_Hight, screen, window_Manager, player);
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
		button_Standard("Craft Paper", "", "", 160, 160, screen, window_Manager, player); //craft paper knop

		button_Standard("Upgrade Blueprint", "", "", SCRWIDTH / 2 - 50, 160, screen, window_Manager, player);

		button_Standard("Invent Blueprint", "", "", SCRWIDTH / 2 + 80, 160, screen, window_Manager, player);
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

		button_Standard("Unlock", "", "", 380 + 0 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen, window_Manager, player);
		button_Standard("Unlock", "", "", 380 + 1 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen, window_Manager, player);
		button_Standard("Unlock", "", "", 380 + 2 * ((((SCRWIDTH - 60 - 170) - 20 * 2) / 3)), SCRHEIGHT / 2 + 400, screen, window_Manager, player);


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
			button_Standard("Upgrade", "", "", 770, 170 + (i * 60), screen, window_Manager, player);
		}
	}
}

void UI::Witch_Hut_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager)
{

	if (window_Manager->get_Active_Window() == "Witch Hut")
	{
		button_Standard("Ascend", "", "", 160, 160, screen, window_Manager, player);
		button_Standard("Upgrades", "", "", 160, 220, screen, window_Manager, player);
	}
	
	if (window_Manager->get_Active_Window() == "Ascension Upgrade")
	{
		screen->Box(150, 50, SCRWIDTH / 3 * 2, 1000, 0xFF00FF);
		screen->Line(SCRWIDTH / 3 * 2 , 1000, SCRWIDTH, 1000, 0xFF00FF);

		ascension_Upgrade_Screen->Update_Drag(player);
		draw_Ascension_Upgrades(screen, ascension_Manager, ascension_Upgrade_Screen, player, window_Manager);
	}
}

void UI::button_Standard(string name, string cost, string description, int x1, int y1, Surface* screen, Window_Manager* window_Manager, Player* player)
{
	int w = 110;
	int h = 50;

	bool hover =
		player->Get_Player_X() >= x1 &&
		player->Get_Player_X() <= x1 + w &&
		player->Get_Player_Y() >= y1 &&
		player->Get_Player_Y() <= y1 + h;

	bool pressed =
		hover &&
		glfwGetMouseButton(window, 0) == GLFW_PRESS;

	uint outer_Border = 0x2A1035;      // Very dark purple
	uint accent_Color = 0x9B30FF;      // Bright purple border
	uint inner_Panel = 0x9257C2;       // Medium purple
	uint text_Color = 0xF0D0FF;        // Light purple text
	uint shadow_Color = 0x14081A;      // Nearly black purple
	uint highlight_Color = 0xD9A6FF;   // Soft lavender


	uint hover_Accent = accent_Color;
	uint hover_Inner = inner_Panel;
	uint pressed_Inner = inner_Panel;

	if (window_Manager->get_Active_Window() == "Forest")
	{
		outer_Border = 0x0E2415;
		accent_Color = 0x3CB371;
		inner_Panel = 0x2E8B57;
		text_Color = 0xD8FFD8;
		highlight_Color = 0x90EE90;

		hover_Accent = 0x66D995;
		hover_Inner = 0x3FAF6F;
		pressed_Inner = 0x1F6B42;
	}
	else if (window_Manager->get_Active_Window() == "Forge" ||
		window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		outer_Border = 0x3A1200;
		accent_Color = 0xFF6600;
		inner_Panel = 0xC1440E;
		text_Color = 0xFFE0CC;
		highlight_Color = 0xFFAA66;

		hover_Accent = 0xFF8844;
		hover_Inner = 0xD85A1A;
		pressed_Inner = 0x8F2F08;
	}
	else if (window_Manager->get_Active_Window() == "Player" ||
		window_Manager->get_Active_Window() == "Lumberjack Tool" ||
		window_Manager->get_Active_Window() == "Crafting Tool" ||
		window_Manager->get_Active_Window() == "Mining Tool")
	{
		outer_Border = 0x2A1035;
		accent_Color = 0x9B30FF;
		inner_Panel = 0x7A4CA5;
		text_Color = 0xF0D0FF;
		highlight_Color = 0xD9A6FF;

		hover_Accent = 0xB84DFF;
		hover_Inner = 0x8B5DB8;
		pressed_Inner = 0x633A87;
	}
	else if (window_Manager->get_Active_Window() == "Libary" ||
		window_Manager->get_Active_Window() == "Blueprint Upgrade" ||
		window_Manager->get_Active_Window() == "Blueprint Crafting")
	{
		outer_Border = 0x606060;
		accent_Color = 0xFFFFFF;
		inner_Panel = 0xD8D8D8;
		text_Color = 0x202020;
		highlight_Color = 0xFFFFFF;

		hover_Accent = 0xFFFFFF;
		hover_Inner = 0xEEEEEE;
		pressed_Inner = 0xBEBEBE;
	}
	else if (window_Manager->get_Active_Window() == "Witch Hut" ||
		window_Manager->get_Active_Window() == "Ascension Upgrade")
	{
		outer_Border = 0x050505;
		accent_Color = 0x6A0DAD;
		inner_Panel = 0x1A1A1A;
		text_Color = 0xE6CCFF;
		highlight_Color = 0xB266FF;

		hover_Accent = 0x8A2BE2;
		hover_Inner = 0x2A123A;
		pressed_Inner = 0x100814;
	}

	int button_Offset = 0;

	if (hover)
	{
		inner_Panel = hover_Inner;
		accent_Color = hover_Accent;
	}

	if (pressed)
	{
		button_Offset = 2;
		inner_Panel = pressed_Inner;
	}

	x1 += button_Offset;
	y1 += button_Offset;

	screen->Bar(x1 + 3, y1 + 3, x1 + w + 3, y1 + h + 3, shadow_Color);

	screen->Bar(x1, y1, x1 + w, y1 + h, outer_Border);
	screen->Box(x1, y1, x1 + w, y1 + h, accent_Color);

	screen->Bar(x1 + 4, y1 + 4, x1 + w - 4, y1 + h - 4, inner_Panel);

	if (!pressed)
	{
		screen->Line(x1 + 2, y1 + 2, x1 + w - 2, y1 + 2, highlight_Color);
		screen->Line(x1 + 2, y1 + 2, x1 + 2, y1 + h - 2, highlight_Color);
		screen->Line(x1 + 2, y1 + h - 2, x1 + w - 2, y1 + h - 2, shadow_Color);
		screen->Line(x1 + w - 2, y1 + 2, x1 + w - 2, y1 + h - 2, shadow_Color);
	}
	else
	{
		screen->Line(x1 + 2, y1 + 2, x1 + w - 2, y1 + 2, shadow_Color);
		screen->Line(x1 + 2, y1 + 2, x1 + 2, y1 + h - 2, shadow_Color);
		screen->Line(x1 + 2, y1 + h - 2, x1 + w - 2, y1 + h - 2, highlight_Color);
		screen->Line(x1 + w - 2, y1 + 2, x1 + w - 2, y1 + h - 2, highlight_Color);
	}

	float name_Scale = Get_Text_Scale(name, w - 20, 1.5f);

	int name_Width =
		static_cast<int>(name.size() * 6 * name_Scale);

	int name_X =
		x1 + ((w - name_Width) / 2);

	screen->Print(name.c_str(),name_X, y1 + 12, text_Color, name_Scale);

	if (hover)
	{
		draw_Hover_Info(name, cost, description, screen, player, window_Manager);
	}
	
}

void UI::button_Standard_Selected(string name, int x1, int y1, Window_Manager* window_Manager, Surface* screen)
{
	int w = 110;
	int h = 50;

	uint outer_Border = 0x2A1035;
	uint accent_Color = 0xE0A6FF;
	uint inner_Panel = 0x633A87;
	uint text_Color = 0xFFFFFF;
	uint shadow_Color = 0x14081A;
	uint highlight_Color = 0xD9A6FF;

	if (window_Manager->get_Active_Window() == "Forest")
	{
		outer_Border = 0x0E2415;
		accent_Color = 0x3CB371;
		inner_Panel = 0x2E8B57;
		text_Color = 0xD8FFD8;
		highlight_Color = 0x90EE90;
	}
	else if (
		(window_Manager->get_Active_Window() == "Forge" ||
			window_Manager->get_Active_Window() == "Craftingtable 1"))
	{
		outer_Border = 0x3A1200;
		accent_Color = 0xFF6600;
		inner_Panel = 0xC1440E;
		text_Color = 0xFFE0CC;
		highlight_Color = 0xFFAA66;
	}
	else if (window_Manager->get_Active_Window() == "Player" ||
		window_Manager->get_Active_Window() == "Lumberjack Tool" ||
		window_Manager->get_Active_Window() == "Crafting Tool" ||
		window_Manager->get_Active_Window() == "Mining Tool")
	{
		outer_Border = 0x2A1035;
		accent_Color = 0x9B30FF;
		inner_Panel = 0x7A4CA5;
		text_Color = 0xF0D0FF;
		highlight_Color = 0xD9A6FF;
	}
	else if (window_Manager->get_Active_Window() == "Libary" ||
		window_Manager->get_Active_Window() == "Blueprint Upgrade" ||
		window_Manager->get_Active_Window() == "Blueprint Crafting")
	{
		outer_Border = 0x606060;
		accent_Color = 0xFFFFFF;
		inner_Panel = 0xD8D8D8;
		text_Color = 0x202020;
		highlight_Color = 0xFFFFFF;
	}
	else if (window_Manager->get_Active_Window() == "Witch Hut" ||
		window_Manager->get_Active_Window() == "Ascension Upgrade")
	{
		outer_Border = 0x050505;
		accent_Color = 0x6A0DAD;
		inner_Panel = 0x1A1A1A;
		text_Color = 0xE6CCFF;
		highlight_Color = 0xB266FF;
	}

	// Keep selected button visually pressed in
	x1 += 2;
	y1 += 2;

	screen->Bar(x1 + 3, y1 + 3, x1 + w + 3, y1 + h + 3, shadow_Color);

	screen->Bar(x1, y1, x1 + w, y1 + h, outer_Border);
	screen->Box(x1, y1, x1 + w, y1 + h, accent_Color);

	screen->Bar(x1 + 4, y1 + 4, x1 + w - 4, y1 + h - 4, inner_Panel);

	// Inverted 3D lines = pressed/selected look
	screen->Line(x1 + 2, y1 + 2, x1 + w - 2, y1 + 2, shadow_Color);
	screen->Line(x1 + 2, y1 + 2, x1 + 2, y1 + h - 2, shadow_Color);
	screen->Line(x1 + 2, y1 + h - 2, x1 + w - 2, y1 + h - 2, highlight_Color);
	screen->Line(x1 + w - 2, y1 + 2, x1 + w - 2, y1 + h - 2, highlight_Color);

	float name_Scale = Get_Text_Scale(name, w - 20, 1.5f);

	int name_Width =
		static_cast<int>(name.size() * 6 * name_Scale);

	int name_X =
		x1 + ((w - name_Width) / 2);

	screen->Print(
		name.c_str(),
		name_X,
		y1 + 12,
		text_Color,
		name_Scale
	);
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

void UI::draw_Ascension_Upgrades(Surface* screen, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Player* player, Window_Manager* window_Manager)
{
	auto all_Upgrades = ascension_Manager->Get_All_Upgrades();

	for (size_t i = 0; i < all_Upgrades.size(); i++)
	{
		double world_X = all_Upgrades[i]->Get_World_X();
		double world_Y = all_Upgrades[i]->Get_World_Y();

		double screen_X = world_X - ascension_Upgrade_Screen->Get_Camera_X();
		double screen_Y = world_Y - ascension_Upgrade_Screen->Get_Camera_Y();

		if (ascension_Upgrade_Screen->Is_In_View(screen_X, screen_Y, 150, 50, SCRWIDTH / 3 * 2 - 150, 950))
		{
			string name = all_Upgrades[i]->Get_Name();
			button_Standard(name.c_str(), "", "", screen_X, screen_Y, screen, window_Manager, player);
		}

	}
}

void UI::draw_Resource_Icons(Surface* screen, string resource_Name, int text_X, int text_Y, int scale, Surface* resource_Icon_Sheet)
{
	int icon_X = 0;
	int icon_Y = 0;
	int icon_W = 16;
	int icon_H = 16;

	if (resource_Name == "SoftWood")
	{
		icon_X = 16 * 27;
		icon_Y = 0;
	}
	else if (resource_Name == "Thalions")
	{
		icon_X = 16 * 35;
		icon_Y = 0;
	}
	else
	{
		return;
	}

	int icon_Draw_X = text_X - ((icon_W * scale) + 4);
	int icon_Draw_Y = text_Y - 8;

	resource_Icon_Sheet->Copy_Region_To( screen, icon_X, icon_Y, icon_W, icon_H, icon_Draw_X, icon_Draw_Y, scale);
}

void UI::button_Tab(string name, int x1, int y1, Surface* screen)
{
	int w = 150;
	int h = SCRHEIGHT / 10;

	uint outer_Border = 0x1A0A1F;
	uint accent_Color = 0x6A0DAD;
	uint inner_Panel = 0x2A1035;
	uint text_Color = 0xE6CCFF;

	screen->Bar(x1, y1, x1 + w, y1 + h, outer_Border);
	screen->Box(x1, y1, x1 + w, y1 + h, accent_Color);
	screen->Bar(x1 + 4, y1 + 4, x1 + w - 4, y1 + h - 4, inner_Panel);

	screen->Print(name.c_str(), x1 + 35, y1 + 28, text_Color, 1.5F);
}

void UI::button_Tab_Selected(string name, int x1, int y1, Surface* screen)
{
	int w = 150;
	int h = SCRHEIGHT / 10;

	uint outer_Border = 0x050505;
	uint accent_Color = 0xB266FF;
	uint inner_Panel = 0x4A235A;
	uint text_Color = 0xFFFFFF;



	screen->Bar(x1, y1, x1 + w, y1 + h, outer_Border);
	screen->Box(x1, y1, x1 + w, y1 + h, accent_Color);
	screen->Bar(x1 + 4, y1 + 4, x1 + w - 4, y1 + h - 4, inner_Panel);

	// no right border feel: selected tab connects to main window
	screen->Line(x1 + w, y1 + 4, x1 + w, y1 + h - 4, inner_Panel);

	screen->Print(name.c_str(), x1 + 35, y1 + 28, text_Color, 1.5F);
}

float UI::Get_Text_Scale(string text, int max_Width, float start_Scale)
{
	float scale = start_Scale;

	while ((text.size() * 6 * scale) > max_Width)
	{
		scale -= 0.1f;

		if (scale <= 1)
		{
			return 1;
		}
	}

	return scale;
}

void UI::draw_Hover_Info(
	string name,
	string cost,
	string description,
	Surface* screen,
	Player* player,
	Window_Manager* window_Manager
)
{
	int padding = 10;
	int line_H = 18;
	int box_W = 300;
	int max_Chars = 38;

	float name_Scale = 1.5f;
	float text_Scale = 1.0f;

	vector<string> description_Lines;
	string current_Line = "";

	for (size_t i = 0; i < description.size(); i++)
	{
		current_Line += description[i];

		if (current_Line.size() >= max_Chars && description[i] == ' ')
		{
			description_Lines.push_back(current_Line);
			current_Line = "";
		}
	}

	if (current_Line != "")
	{
		description_Lines.push_back(current_Line);
	}

	int box_H = padding * 2;
	box_H += line_H;

	if (cost != "")
	{
		box_H += line_H;
	}

	box_H += static_cast<int>(description_Lines.size()) * line_H;

	int x = static_cast<int>(player->Get_Player_X()) + 20;
	int y = static_cast<int>(player->Get_Player_Y()) + 20;

	if (x + box_W > SCRWIDTH)
	{
		x = static_cast<int>(player->Get_Player_X()) - box_W - 20;
	}

	if (y + box_H > SCRHEIGHT)
	{
		y = static_cast<int>(player->Get_Player_Y()) - box_H - 20;
	}

	if (x < 5)
	{
		x = 5;
	}

	if (y < 5)
	{
		y = 5;
	}

	uint outer_Border = 0x2A1035;
	uint accent_Color = 0x9B30FF;
	uint inner_Panel = 0x1A0A1F;
	uint text_Color = 0xF0D0FF;
	uint title_Color = 0xFFFFFF;

	if (window_Manager->get_Active_Window() == "Forest")
	{
		outer_Border = 0x0E2415;
		accent_Color = 0x3CB371;
		inner_Panel = 0x102818;
		text_Color = 0xD8FFD8;
		title_Color = 0xFFFFFF;
	}
	else if (window_Manager->get_Active_Window() == "Forge" ||
		window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		outer_Border = 0x3A1200;
		accent_Color = 0xFF6600;
		inner_Panel = 0x2A1000;
		text_Color = 0xFFE0CC;
		title_Color = 0xFFFFFF;
	}
	else if (window_Manager->get_Active_Window() == "Player" ||
		window_Manager->get_Active_Window() == "Lumberjack Tool" ||
		window_Manager->get_Active_Window() == "Crafting Tool" ||
		window_Manager->get_Active_Window() == "Mining Tool")
	{
		outer_Border = 0x2A1035;
		accent_Color = 0x9B30FF;
		inner_Panel = 0x1A0A1F;
		text_Color = 0xF0D0FF;
		title_Color = 0xFFFFFF;
	}
	else if (window_Manager->get_Active_Window() == "Libary" ||
		window_Manager->get_Active_Window() == "Blueprint Upgrade" ||
		window_Manager->get_Active_Window() == "Blueprint Crafting")
	{
		outer_Border = 0x606060;
		accent_Color = 0xFFFFFF;
		inner_Panel = 0xE0E0E0;
		text_Color = 0x202020;
		title_Color = 0x000000;
	}
	else if (window_Manager->get_Active_Window() == "Witch Hut" ||
		window_Manager->get_Active_Window() == "Ascension Upgrade")
	{
		outer_Border = 0x050505;
		accent_Color = 0x6A0DAD;
		inner_Panel = 0x101010;
		text_Color = 0xE6CCFF;
		title_Color = 0xFFFFFF;
	}

	screen->Bar(x + 3, y + 3, x + box_W + 3, y + box_H + 3, 0x000000);
	screen->Bar(x, y, x + box_W, y + box_H, outer_Border);
	screen->Box(x, y, x + box_W, y + box_H, accent_Color);
	screen->Bar(x + 4, y + 4, x + box_W - 4, y + box_H - 4, inner_Panel);

	int text_Y = y + padding;

	screen->Print(name.c_str(), x + padding, text_Y, title_Color, name_Scale);
	text_Y += line_H;

	if (cost != "")
	{
		screen->Print(cost.c_str(), x + padding, text_Y, text_Color, text_Scale);
		text_Y += line_H;
	}

	for (size_t i = 0; i < description_Lines.size(); i++)
	{
		screen->Print(description_Lines[i].c_str(), x + padding, text_Y, text_Color, text_Scale);
		text_Y += line_H;
	}
}


