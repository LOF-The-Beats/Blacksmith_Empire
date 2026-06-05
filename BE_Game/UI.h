#pragma once
class Resource_Manager;
class Player;
class Window_Manager;
class Craftingtable_Manager;
class Blueprint_Manager;
class Item_Manager;
class Draft_Manager;
class Unlock_Manager;
class Tutorial;
class Ascension_Upgrade_Screen;
class Ascension_Manager;

class UI
{
public:

	UI();
	//Layouts
	void Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlock_Manager, Tutorial* tutorial, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager);
	void UI_Layout(Surface* screen, Resource_Manager* resource_Manager, Unlock_Manager* unlock_Manager);
	void Forest_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Item_Manager* item_Manager);
	void Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
	void Player_UI(Surface* screen, Window_Manager* window_Manager, Item_Manager* item_Manager, Player* player);
	void Libary_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager);
	void Witch_Hut_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager);


	//Buttons
	void button_Standard(string name, string cost, int x1, int y1, Surface* screen);
	void button_Standard_Selected(string name, int x1, int y1, Surface* screen);

	// arrows
	void Arrow_Up(Surface* screen, int x1, int y1);
	void Arrow_Down(Surface* screen, int x1, int y1);
	void Arrow_Left(Surface* screen, int x1, int y1);
	void Arrow_Right(Surface* screen, int x1, int y1);
	
	// other
	void draw_Ascension_Upgrades(Surface* screen, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen);

private:
};

