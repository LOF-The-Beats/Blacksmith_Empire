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

void Blueprint_Manager::Add_Blueprints(const string name, string equip_Slot, const double conversion_Rate, double cost, int order)
{
	if (blueprints.find(name) == blueprints.end())
	{
		blueprints[name] = new Blueprints(name, equip_Slot,conversion_Rate, cost, order);
	}
}

void Blueprint_Manager::Create_All_Blueprints()
{
	Add_Blueprints("Axe", "Lumberjack", 0.2, 10, 0);
	Add_Blueprints("Tools", "Crafting", 0.2, 10, 1);
	Add_Blueprints("Pickaxe", "Mining", 0.2, 10, 2);
	Add_Blueprints("Short Sword", "Mining", 0.3, 15, 3);
	Add_Blueprints("Shield", "Mining", 0.3, 15, 4);
	Add_Blueprints("Long Sword", "Mining", 0.3, 15, 5);
	Add_Blueprints("Rapier", "Mining", 0.4, 20,6);

	Get_Blueprints("Axe")->Set_Unlocked(true);
}
