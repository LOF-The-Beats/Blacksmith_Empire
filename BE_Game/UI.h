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
class Smelter_Manager;
class Ascension_Upgrades;

class UI
{
public:

	UI();
	//Layouts
	void Draw_UI(float deltaTime, Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlock_Manager, Tutorial* tutorial, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager, Smelter_Manager* smelter_Manager);
	void UI_Layout(Surface* screen, Resource_Manager* resource_Manager, Unlock_Manager* unlock_Manager, Window_Manager* window_Manager, Player* player);
	void Forest_UI(float deltaTime, Surface* screen, Surface* resource_Icon_Sheet, Resource_Manager* resource_Manager, Player* player, Item_Manager* item_Manager, Window_Manager* window_Manager);
	void Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Smelter_Manager* smelting_Manager);
	void Player_UI(Surface* screen, Window_Manager* window_Manager, Item_Manager* item_Manager, Player* player);
	void Libary_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager);
	void Witch_Hut_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player, Window_Manager* window_Manager, Draft_Manager* Draft_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager);
	void Mine_UI(Surface* screen, Window_Manager* window_Manager, Player* player, Resource_Manager* resource_Manager, Item_Manager* item_Manager);





	//Buttons
	void button_Standard(string name, string cost, string description, int x1, int y1, Surface* screen, Window_Manager* window_Manager, Player* player);
	void Ascension_Upgrade(Ascension_Upgrades* upgrade, int x1, int y1, Surface* screen, Window_Manager* window_Manager, Player* player);
	void button_Standard_Selected(string name, int x1, int y1, Window_Manager* window_Manager, Surface* screen);
	void button_Tab(string name, int x1, int y1, Surface* screen);
	void button_Tab_Selected(string name, int x1, int y1, Surface* screen);

	// arrows
	void Arrow_Up(Surface* screen, int x1, int y1);
	void Arrow_Down(Surface* screen, int x1, int y1);
	void Arrow_Left(Surface* screen, int x1, int y1);
	void Arrow_Right(Surface* screen, int x1, int y1);

	
	// other
	void draw_Ascension_Upgrades(Surface* screen, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Player* player, Window_Manager* window_Manager);
	void draw_Resource_Icons(Surface* screen, string resource_Name, int text_X, int text_Y, int scale, Surface* Asset_Sheet);
	float Get_Text_Scale(string text, int max_Width, float start_Scale);
	void draw_Hover_Info(string name, string cost, string description, Surface* screen, Player* player, Window_Manager* window_Manager);

private:
	bool hover_Active = false;

	string hover_Name;
	string hover_Cost;
	string hover_Description;

	Surface* resource_Icon_Sheet = new Surface("Assets/Crafting Materials Icons.png");

};

