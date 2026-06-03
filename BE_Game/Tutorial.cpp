#include "precomp.h"
#include "Tutorial.h"
#include "UI.h"
#include "Game_Manager.h"
#include "Player.h"
#include "Resource_Manager.h"
#include "Craftingtable_Manager.h"
#include "Unlock_Manager.h"

Tutorial::Tutorial()
	:enabled(true), tutorial_Step(0), page(0)
{
}

bool Tutorial::Get_Enabled() const
{
	return enabled;
}

int Tutorial::Get_Tutorial_Step() const
{
	return tutorial_Step;
}

int Tutorial::Get_Page() const
{
	return page;
}

void Tutorial::Set_Enabled(bool b)
{
	enabled = b;
	return;
}

void Tutorial::Set_Tutorial_Step(int amount)
{
	tutorial_Step = amount;
	return;
}

void Tutorial::SetPage(int amount)
{
	page = amount;
	return;
}

void Tutorial::Draw_Tutorial_UI(Surface* screen, UI* ui)
{
	if (enabled)
	{
		if (tutorial_Step == 0)
		{
			if (page == 0)
			{
				screen->Box(700,700, 1000, 1000, 0xF0F0F0);
				screen->Print("Hello Welcome to BE.", 710,710, 0xF0F0F0, 2.0F);
				screen->Print("In this Game you gather resources to grow your empire", 710,730, 0xF0F0F0, 2.0F);
				screen->Print("Lets start with the basics.", 710,750, 0xF0F0F0, 2.0F);

				ui->button_Standard("Continue", "", 750, 780, screen);


			}
			else if (page == 1)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("The First resource you can gather is SoftWood.", 710, 710, 0xF0F0F0, 2.0F);
				screen->Print("You can gather SoftWood by pressing the button.", 710, 730, 0xF0F0F0, 2.0F);
				screen->Print("You can see how much SoftWood you have above it.", 710, 750, 0xF0F0F0, 2.0F);
				screen->Print("Gather some SoftWood!", 710, 770, 0xF0F0F0, 2.0F);


				ui->Arrow_Left(screen, 320, 185);
				ui->Arrow_Up(screen, 210, 100);
				
			}
			else if (page == 2)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("Great, when you personaly do something you gain EXP.", 710, 710, 0xF0F0F0, 2.0F);
				screen->Print("Gain enough and you level up and get stronger.", 710, 730, 0xF0F0F0, 2.0F);
				screen->Print("Lets start with gathering 20 SoftWood", 710, 750, 0xF0F0F0, 2.0F);

				ui->Arrow_Right(screen, 800, 125);
			}

		}
		else if (tutorial_Step == 1)
		{
			if (page == 0)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("You have unlocked the Forge", 710, 710, 0xF0F0F0, 2.0F);
				screen->Print("Here you can craft items and sell them.", 710, 730, 0xF0F0F0, 2.0F);
				screen->Print("Press the Forge Button to enter the forge!", 710, 750, 0xF0F0F0, 2.0F);

				ui->Arrow_Up(screen, 65, 250);
			}
			if (page == 1)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("Press the Crafting Button", 710, 710, 0xF0F0F0, 2.0F);

				ui->Arrow_Left(screen, 280, 185);
			}
			if (page == 2)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("This is the Craftingtable.", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("On the left you can choose a resource you want to use.", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("On the right you can choose a blueprint you want to use.", 710, 450, 0xF0F0F0, 2.0F);
				screen->Print("Together they create a item.", 710, 470, 0xF0F0F0, 2.0F);
				screen->Print("When selecting a resource or blueprint the info will be show underneath.", 710, 490, 0xF0F0F0, 2.0F);


				ui->Arrow_Right(screen, 500, 185);
				ui->Arrow_Left(screen, 1420, 185);
				ui->Arrow_Down(screen, 200, 900);
				ui->Arrow_Down(screen, 1350, 900);
			}
			if (page == 3)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("In the middle is the combined stats if you know them.", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("How fast you can craft is based on the hardness of the resource you use.", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("Lets craft 2 axes!", 710, 450, 0xF0F0F0, 2.0F);

				ui->Arrow_Down(screen, 700, 900);
				ui->Arrow_Right(screen, 875, 830);
			}
			if (page == 4)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("Lets Sell the Items we just crafted.", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("Go back to the Forge by closing the craftingtable", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("or press Forge again.", 710, 450, 0xF0F0F0, 2.0F);

				ui->Arrow_Up(screen, 65, 250);
				ui->Arrow_Up(screen, 960, 220);
			}
			if (page == 5)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("Great Press the Sell All Items button.", 710, 710, 0xF0F0F0, 2.0F);

				ui->Arrow_Down(screen, 210, 290);
			}
			if (page == 6)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("As you can se in the top left you gained 20 thallions.", 710, 710, 0xF0F0F0, 2.0F);
				screen->Print("Lets use that to buy workers for SoftWood", 710, 730, 0xF0F0F0, 2.0F);
				screen->Print("Go back to the Forest", 710, 750, 0xF0F0F0, 2.0F);

				ui->Arrow_Up(screen, 65, 125);
				ui->Arrow_Left(screen, 250, 25);
			}if (page == 7)
			{
				screen->Box(700, 700, 1000, 1000, 0xF0F0F0);
				screen->Print("Press the Buy worker button.", 710, 710, 0xF0F0F0, 2.0F);

				ui->Arrow_Left(screen, 280, 255);
			}
		}
		else if (tutorial_Step == 2)
		{
			if (page == 0)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("Now that you have made some axes.", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("lets equip Them", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("Go to The player screen.", 710, 450, 0xF0F0F0, 2.0F);
			}
			if (page == 1)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("On the left are the buttons of each equipmentslot", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("You can only have 1 item per slot.", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("Click the Lumberjack slot!", 710, 450, 0xF0F0F0, 2.0F);
				screen->Print("Then on the right you will see the Items you have made", 710, 470, 0xF0F0F0, 2.0F);
				screen->Print("Press the button on the right to equip the item.", 710, 490, 0xF0F0F0, 2.0F);
				screen->Print("In the top right corner you now see which item is equiped.", 710, 510, 0xF0F0F0, 2.0F);
				screen->Print("And how strong it is.", 710, 530, 0xF0F0F0, 2.0F);

			}
			}
		else if (tutorial_Step == 3)
		{
			if (page == 0)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("You have unlocked the Libary lets fo ther.", 710, 410, 0xF0F0F0, 2.0F);
			}
			if (page == 1)
			{
				screen->Box(700, 400, 1000, 700, 0xF0F0F0);
				screen->Print("On the left you can craft paper.", 710, 410, 0xF0F0F0, 2.0F);
				screen->Print("Paper is used to upgrade or unlock new blueprints.", 710, 430, 0xF0F0F0, 2.0F);
				screen->Print("On the right are 2 buttons left one used to upgrade blueprints.", 710, 450, 0xF0F0F0, 2.0F);
				screen->Print("And right one to unlock new blueprints.", 710, 470, 0xF0F0F0, 2.0F);
			}
		}
	}
}

void Tutorial::Tutorial_Buttons(Game_Manager* game_Manager, Player* player, Resource_Manager* resourcemanager, Craftingtable_Manager* craftingtable_Manager, Unlock_Manager* unlock_Manager)
{
	if (enabled)
	{
		if (tutorial_Step == 0)
		{
			if (page == 0)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 750, 780))
				{
					page = 1;
				}
			}
			else if (page == 1)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 160, 160))
				{
					page = 2;
				}
			}
			else if (page == 2)
			{
				if (resourcemanager->Get_Resource("SoftWood")->Get_Quantity() >= 19) // this is off set with 1 cuz the update to 20 is done later than this get checked
				{
					page = 0;
					tutorial_Step = 1;
				}
			}
		}
		else if (tutorial_Step == 1)
		{	
			if (page == 0)
			{
				if (game_Manager->Is_Mouse_Over_Location(player, 0, 0, 1))
				{
					page = 1;
				}
			}
			if (page == 1)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player,160 , 160))
				{
					page = 2;
				}
			}
			if (page == 2)
			{
				if (craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Blueprint() != "none" ||
					craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Get_Resource() != "none")
				{
					page = 3;
				}
			}
			if (page == 3)
			{
				if (player->Get_Stats("Crafting")->Get_Exp() >= 19) // again is reduced by 1.
				{
					page = 4;
				}
			}
			if (page == 4)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 910, 160) ||
					game_Manager->Is_Mouse_Over_Location(player, 0, 0, 1))
				{
					page = 5;
				}
			}
			if (page == 5)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 160, 300))
				{
					page = 6;
				}
			}
			if (page == 6)
			{
				if (game_Manager->Is_Mouse_Over_Location(player, 0, 0, 0))
				{
					page = 7;
				}
			}
			if (page ==7)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 160, 230))
				{
					page = 8;
				}
			}
			if (page == 8)
			{
				if (unlock_Manager->Get_Unlocked("Player")->Get_Unlocked())
				{
					page = 0;
					tutorial_Step = 2;
				}
			}
		}
		else if (tutorial_Step == 2)
		{
			if (page == 0)
			{
				if (game_Manager->Is_Mouse_Over_Location(player, 0,0,2))
				{
					page = 1;
				}
			}
			if (page == 1)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 970, 115))
				{
					page = 2;
				}
			}
			if (page == 2)
			{
				if (resourcemanager->Get_Resource("SoftWood")->Get_Quantity() >= 1000)
				{
					page = 0;
					tutorial_Step = 3;
				}
			}
		}
		else if (tutorial_Step == 3)
		{
			if (page == 0 )
			{
				if (game_Manager->Is_Mouse_Over_Location(player, 0,0,3))
				{
					page = 1;
				}
			}
			if (page == 1)
			{
				if (game_Manager->Is_Mouse_Over_Standard(player, 160, 160))
				{
					page = 2;
				}
			}
		}

	}
}
