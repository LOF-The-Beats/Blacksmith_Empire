#pragma once
#include "unordered_map"
class Resource_Manager;
class Blueprint_Manager;
class Item_Manager;
class Player;
class Craftingtable_Manager;
class Draft_Manager;
class Ascension_Upgrades;

class Ascension_Manager
{
public:
	Ascension_Manager();

	//getter
	double Get_Base_Cost() const;
	Ascension_Upgrades* Get_Upgrade(string name);

	//setters

	void Set_Base_Cost(double amount);


	// adders
	void Add_Upgrade(string name, string description, double max_Level, double cost, double world_X, double world_Y);

	//other functions
	void Update_Gain_On_Reset(Resource_Manager* resource_Manager);
	void Ascend_Run(Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager, Draft_Manager* draft_Manager);
	vector<Ascension_Upgrades*> Get_All_Upgrades();
	void Create_Upgrades();

private:

	double base_Cost;
	unordered_map<string, Ascension_Upgrades*> upgrades;
};


