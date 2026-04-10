#pragma once
class Resource_Manager;
class Player;
class Window_Manager;
class Craftingtable_Manager;
class Blueprint_Manager;
class Item_Manager;

class UI
{
public:

	UI();
	//Layouts
	void Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
	void UI_Layout(Surface* screen, Resource_Manager* resource_Manager);
	void Forest_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Item_Manager* item_Manager);
	void Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
	void Player_UI(Surface* screen, Window_Manager* window_Manager, Item_Manager* item_Manager, Player* player);
	void Libary_UI(Surface* screen, Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Player* player);


	//Buttons
	void button_Standard(string name, string cost, int x1, int y1, Surface* screen);
	void button_Standard_Selected(string name, int x1, int y1, Surface* screen);

private:
};

