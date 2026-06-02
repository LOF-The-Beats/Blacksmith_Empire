#pragma once
#include "unordered_map"
#include "Item.h"

class Item_Manager
{
public:
	Item_Manager();

	//getter

	Item* Get_Item(const string name) const;


	//adder

	void Add_Item(const string name, string resource, string blueprint, string equip_Slot, double level, double value, double power);
	
	// sell actions
	double Sell_All_Items();

	// sorter
	vector<Item*> get_Item_Sorted_By_Power_And_Name();

private:
	unordered_map<string, Item*> item;
};

