#include "precomp.h"
#include "Item_Manager.h"

Item_Manager::Item_Manager()
{
}

Item* Item_Manager::Get_Item(const string name) const
{
	auto it = item.find(name);
	if (it != item.end())
	{
		return it->second;
	}
	return nullptr;
}

void Item_Manager::Add_Item(const string name, string resource, string blueprint, double level, double value, double power)
{
	if (item.find(name) == item.end())
	{
		item[name] = new Item(name, resource, blueprint, level, value, power);
	}
}

double Item_Manager::Sell_All_Items()
{
	double earned_gold = 0;

	for (auto& [key, item_Pointer] : item)
	{
		if (item_Pointer) // always good to be safe
		{
			earned_gold = item_Pointer->Get_Quantity() * item_Pointer->Get_Value();
			item_Pointer->Set_Quantity(0);
		}
	}
	return earned_gold;
}

vector<Item*> Item_Manager::get_Item_Sorted_By_Power_And_Name()
{
	vector<Item*> sorted_Items;

	for (auto& [key, itemPtr] : item)
	{
		if (itemPtr && itemPtr->Get_Quantity() > 0)
		{
			sorted_Items.push_back(itemPtr);
		}
	}

	sort(sorted_Items.begin(), sorted_Items.end(),
		[](Item* a, Item* b)
		{
			if (a->Get_Power() != b->Get_Power())
			{
				return a->Get_Power() > b->Get_Power(); // higher power first
			}

			return a->Get_Name() < b->Get_Name(); // alphabetical if same power
		});

	return sorted_Items;
}
