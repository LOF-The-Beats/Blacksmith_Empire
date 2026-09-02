#pragma once
#include "unordered_map"
#include "Item.h"

class Item_Manager
{
public:
	Item_Manager();

	//getter

	Item* Get_Item(const string name) const;
	vector<Item*> Get_All_Items();



	//adder

	void Add_Item(const string name, string resource, string blueprint, string equip_Slot, double level, double value, double power, double weight, double strength, double agility, double vitality, double luck, double armor);

	//Deleter

	void Delete_All_Items();
	
	// sell actions
	double Sell_All_Items();

	// sorter
	vector<Item*> get_Item_Sorted_By_Power_And_Equip_Slot(string equip_Slot);

private:
	unordered_map<string, Item*> item;
};

