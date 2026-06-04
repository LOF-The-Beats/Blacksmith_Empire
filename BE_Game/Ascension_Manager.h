#pragma once
class Resource_Manager;
class Blueprint_Manager;
class Item_Manager;
class Player;
class Craftingtable_Manager;

class Ascension_Manager
{
public:
	Ascension_Manager();

	//getter
	double Get_Base_Cost() const;

	//setters

	void Set_Base_Cost(double amount);

	//other functions
	void Update_Gain_On_Reset(Resource_Manager* resource_Manager);
	void Ascend_Run(Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager);

private:

	double base_Cost;
};

