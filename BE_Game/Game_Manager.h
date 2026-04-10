#pragma once

class Player;
class Resource_Manager;
class Window_Manager;
class Craftingtable_Manager;
class Blueprint_Manager;
class Item_Manager;

class Game_Manager
{
public:
	Game_Manager();

	void Update_Mouse_Pos(Player* player);
	void If_Clicked(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
	bool Is_Mouse_Over_Standard(Player* player, double x, double y);
	bool Is_Mouse_Over_Location(Player* player, double x, double y, double z);
	void Location_Buttons_Pressed(Player* player, Window_Manager* window_Manager);


	// Location buttons
	void Forest_Buttons(Player* player, Resource_Manager* resource_Manager, Item_Manager* item_Manager);
	void Forge_Buttons(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Item_Manager* item_Manager);
	void Player_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager);
	void Libary_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager);



	//craftingtable window
	void Craftingtable_1_Window(Player* player, Craftingtable_Manager* craftingtable, Window_Manager* window_Manager, Blueprint_Manager* blueprint_Manager, Resource_Manager* resource_Manager);
	void Lumberjack_Tool_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager);



	void Check_All_Updates(double deltatime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
	void Update_All_Per_Seccond_Events(double deltatime, Player* player, Resource_Manager* resource_Manager);
	void Check_Level_Up(Player* player);
	void Check_Player_Stats(Player* player);
	void Check_Craftingtable_Progress(Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
private:
	bool clicked = false;

};

