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

void Blueprint_Manager::Add_Blueprints(const string name, string equip_Slot, const double conversion_Rate, int order)
{
	if (blueprints.find(name) == blueprints.end())
	{
		blueprints[name] = new Blueprints(name, equip_Slot,conversion_Rate, order);
	}
}

void Blueprint_Manager::Create_All_Blueprints()
{
	Add_Blueprints("Axe", "Lumberjack", 0.2, 0);
	Add_Blueprints("Tools", "Crafting", 0.2, 1);
	Add_Blueprints("Pickaxe", "Mining", 0.2, 2);

	Get_Blueprints("Axe")->Set_Unlocked(true);
}
