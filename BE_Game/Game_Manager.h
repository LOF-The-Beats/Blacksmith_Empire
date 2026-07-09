#pragma once

class Player;
class Resource_Manager;
class Window_Manager;
class Craftingtable_Manager;
class Blueprint_Manager;
class Item_Manager;
class Draft_Manager;
class Unlock_Manager;
class Tutorial;
class Ascension_Manager;
class Ascension_Upgrade_Screen;

class Game_Manager
{
public:
	Game_Manager();

	void Update_Mouse_Pos(Player* player);
	void If_Clicked(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Draft_Manager* draft_Manager, Unlock_Manager* unlcok_Manager, Tutorial* tutorial, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen);
	bool Is_Mouse_Over_Standard(Player* player, double x, double y);
	bool Is_Mouse_Over_Location(Player* player, double x, double y, double z);
	void Location_Buttons_Pressed(Player* player, Window_Manager* window_Manager, Unlock_Manager* unlock_Manger);


	// Location buttons
	void Forest_Buttons(Player* player, Resource_Manager* resource_Manager, Item_Manager* item_Manager);
	void Forge_Buttons(Player* player, Resource_Manager* resource_Manager, Window_Manager* window_Manager, Item_Manager* item_Manager, Craftingtable_Manager* craftingtable_Manager);
	void Player_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager);
	void Libary_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager, Draft_Manager* draft_Manager, Blueprint_Manager* blueprint_Manager);
	void Witch_Hut_Buttons(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable_Manager, Draft_Manager* draft_Manager, Blueprint_Manager* blueprint_Manager, Ascension_Manager* ascension_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen);





	//craftingtable window
	void Craftingtable_Window(Player* player, Craftingtable_Manager* craftingtable, Window_Manager* window_Manager, Blueprint_Manager* blueprint_Manager, Resource_Manager* resource_Manager);
	void Lumberjack_Tool_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager);
	void Blueprint_Crafting_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager);
	void Blueprint_Upgrade_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager);
	void Ascension_Upgrade_Window(Player* player, Window_Manager* window_Manager, Item_Manager* item_Manager, Blueprint_Manager* blueprint_Manager, Draft_Manager* draft_Manager, Resource_Manager* resource_Manager, Ascension_Upgrade_Screen* ascension_Upgrade_Screen, Ascension_Manager* ascension_Manager, Craftingtable_Manager* craftingtable_Manager);



	void Check_All_Updates(double deltatime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Unlock_Manager* unlock_Manager, Ascension_Manager* ascension_Manager);
	void Update_All_Per_Seccond_Events(double deltaTime, Player* player, Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable_Manager, Blueprint_Manager* blueprint_Manager);
	void Check_Level_Up(Player* player);
	void Check_Player_Stats(Player* player);
	void Check_Craftingtable_Progress(Resource_Manager* resource_Manager, Craftingtable_Manager* craftingtable, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager);
private:
	bool clicked = false;

};

