#include "precomp.h"
#include "Blueprint_Manager.h"

Blueprint_Manager::Blueprint_Manager()
{
}

Blueprints* Blueprint_Manager::Get_Blueprints(const string name) const
{
	auto it = blueprints.find(name);
	if (it != blueprints.end())
	{
		return it->second;
	}
	return nullptr;
}

vector<Blueprints*> Blueprint_Manager::Get_Sorted_Blueprints_Numbers()
{
	vector<Blueprints*> sorted_Blueprints;

	for (auto& blueprint : blueprints)
	{
		if (blueprint.second->Get_Unlocked())
		{
			sorted_Blueprints.push_back(blueprint.second);
		}
	}

	sort(sorted_Blueprints.begin(), sorted_Blueprints.end(), [](Blueprints* a, Blueprints* b)
		{
			return a->Get_Order() < b->Get_Order();
		}
	);
	return sorted_Blueprints;
}

vector<Blueprints*> Blueprint_Manager::Get_All_Blueprints()
{
	vector<Blueprints*> all_Blueprints;

	for (auto& blueprint : blueprints)
	{
		all_Blueprints.push_back(blueprint.second);
	}

	return all_Blueprints;
}

vector<Blueprints*> Blueprint_Manager::Get_All_Unlocked_Blueprints()
{
	vector<Blueprints*> all_Blueprints;

	for (auto& blueprint : blueprints)
	{
		if (!blueprint.second->Get_Unlocked())
		{
			all_Blueprints.push_back(blueprint.second);
		}
	}

	return all_Blueprints;
}

void Blueprint_Manager::Add_Blueprints(const string name, string equip_Slot, const double conversion_Rate, double cost, double value, int order, double weight_Value, double strength_Value, double agility_Value, double vitality_Value, double luck_Value, double armor)
{
	if (blueprints.find(name) == blueprints.end())
	{
		blueprints[name] = new Blueprints(name, equip_Slot,conversion_Rate, cost, value, order, weight_Value, strength_Value, agility_Value, vitality_Value, luck_Value, armor);
	}
}

void Blueprint_Manager::Create_All_Blueprints()
{
	Add_Blueprints("Axe", "Lumberjack", 0.2, 10, 1, 0, 0.1, 0.7, 0.3, 0, 0, 0);
	Add_Blueprints("Tools", "Crafting", 0.2, 10, 1, 1, 0.3, 0.8, 0.2, 0, 0, 0);
	Add_Blueprints("Pickaxe", "Mining", 0.2, 10, 1, 2, 0.2, 0.7, 0.3, 0, 0, 0);
	Add_Blueprints("Short Sword", "Mining", 0.3, 15, 1.2, 3, 0.3, 0.4, 0.4, 0, 0.2, 0);
	Add_Blueprints("Shield", "Mining", 0.3, 15, 1.2, 4, 0.4, 0, 0, 0.4, 0, 0.6);
	Add_Blueprints("Long Sword", "Mining", 0.3, 15, 1.2, 5, 0.6, 0.6, 0.3, 0, 0.1, 0);
	Add_Blueprints("Rapier", "Mining", 0.4, 20, 1.4, 6, 0.2, 0.2, 0.5, 0, 0.3, 0);

	Get_Blueprints("Axe")->Set_Unlocked(true);
}
