#include "precomp.h"
#include "UI.h"
#include "Resource_Manager.h"
#include "Player.h"
#include "Window_Manager.h"
#include "Craftingtable_Manager.h"

UI::UI()
{
}

void UI::Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable)
{
	UI_Layout(screen);
	if (window_Manager->get_Active_Window() == "Forest")
	{
		Forest_UI(screen, resource_Manager, player);
	}
	else if (window_Manager->get_Active_Window() == "Forge" ||
		window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		Forge_UI(screen, resource_Manager, player, window_Manager, craftingtable);
	}

}

void UI::UI_Layout(Surface* screen)
{
	screen->Line(0, 50, SCRWIDTH, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 1, 0, SCRWIDTH / 3 * 1, 50, 0xFF00FF);
	screen->Line(SCRWIDTH / 3 * 2, 0, SCRWIDTH / 3 * 2, 50, 0xFF00FF);
	// top tekst


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
}

void UI::Forest_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player)
{

	// draws the level progress bar
	{
		double level_Indicator = 150 + (player->Get_Lumberjack_Exp() / player->Get_Lumberjack_Exp_Needed_Level_Up() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = std::round(player->Get_Lumberjack_Exp());
		double player_Exp_Needed = std::round(player->Get_Lumberjack_Exp_Needed_Level_Up());
		std::string level_Idicator_Tekst = "Exp: " + std::to_string(static_cast<int>(std::round(player_Exp))) + " / Exp Needed: " + std::to_string(static_cast<int>(std::round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000 , 2.0F);
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);


	button_Standard("Gather", "", 160, 160, screen); //gather resource knop
	
	double cost =  std::round(resource_Manager->Get_Resource("SoftWood")->Get_Worker_Cost());
	std::string label = "Cost: " + std::to_string(static_cast<int>(std::round(cost))) + " SoftWood";
	button_Standard("Buy Worker", label.c_str(), 160, 230, screen); // buy worker


	screen->Print((string(resource_Manager->Get_Resource("SoftWood")->Get_Name()) + ": " + to_string(static_cast<int>(std::round(resource_Manager->Get_Resource("SoftWood")->Get_Quantity())))).c_str(), 180, SCRHEIGHT / 30 * 1 + 35, 0xFF00FF, 1.5);

}

void UI::Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable)
{
	// draws the level progress bar
	{
		double level_Indicator = 150 + (player->Get_Crafting_Exp() / player->Get_Crafting_Exp_Needed_Level_Up() * (SCRWIDTH - 150));
		screen->Bar(150, 100, level_Indicator, 150, 0x00FF00);
		double player_Exp = std::round(player->Get_Crafting_Exp());
		double player_Exp_Needed = std::round(player->Get_Crafting_Exp_Needed_Level_Up());
		std::string level_Idicator_Tekst = "Exp: " + std::to_string(static_cast<int>(std::round(player_Exp))) + " / Exp Needed: " + std::to_string(static_cast<int>(std::round(player_Exp_Needed)));
		screen->Print(level_Idicator_Tekst.c_str(), (SCRWIDTH - 150) / 2, 125, 0xFF0000, 2.0F);
	}
	screen->Line(150, 100, SCRWIDTH, 100, 0xFF00FF);
	screen->Line(150, 150, SCRWIDTH, 150, 0xFF00FF);

	if (window_Manager->get_Active_Window() == "Forge")
	{
		button_Standard("Crafting table", "", 160, 160, screen);
	}
	if (window_Manager->get_Active_Window() == "Craftingtable 1")
	{
		// layout of craftingtable
		screen->Line(SCRWIDTH / 3 * 1, 150, SCRWIDTH / 3 * 1, SCRHEIGHT, 0xFF00FF);
		screen->Line(SCRWIDTH / 3 * 2, 150, SCRWIDTH / 3 * 2, SCRHEIGHT, 0xFF00FF);
		screen->Line(100, SCRHEIGHT / 10 * 8 + 50, SCRWIDTH, SCRHEIGHT / 10 * 8 + 50, 0xFF00FF);

		// Buttons
		button_Standard("Close", "Craftingtable", SCRWIDTH / 2 - 50, 160, screen);
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "SoftWood")
		{
			button_Standard("SoftWood", "", SCRWIDTH / 3 * 1 - 120, 160, screen);
		}
		else
		{
			button_Standard_Selected("SoftWood", SCRWIDTH / 3 * 1 - 120, 160, screen);
		}
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "Axe")
		{
			button_Standard("Axe", "", SCRWIDTH / 3 * 2 + 10, 160, screen);
		}
		else
		{
			button_Standard_Selected("Axe", SCRWIDTH / 3 * 2 + 10, 160, screen);
		}
		
		if (craftingtable->get_Craftingtable("Craftingtable 1")->Get_Resource() != "" &&
			craftingtable->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "")
		{
			button_Standard("Craft", "", SCRWIDTH / 2 - 50, SCRHEIGHT / 10 * 8 - 50, screen);
		}

	}
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



