#include "precomp.h"
#include "Resource_Manager.h"

Resource_Manager::Resource_Manager()
{
}

Resources* Resource_Manager::Get_Resource(const string name) const
{
	auto it = resources.find(name);
	if (it != resources.end())
	{
		return it->second;
	}
	return nullptr;
}

double Resource_Manager::Get_Resource_Quantity(const string name) const
{
	Resources* resource = Get_Resource(name);
	if (resource)
	{
		return resource->Get_Quantity();
	}
	return 0.0;
}

vector<Resources*> Resource_Manager::Get_Sorted_Resources_Numbers(Resources::Resource_Type resource_Type)
{
	vector<Resources*> sorted_Resources;

	for (auto& resource : resources)
	{
		if (resource.second->Check_Resource_Type(resource_Type) &&
			resource.second->Get_Unlocked() == true)
		{
			sorted_Resources.push_back(resource.second);
		}
	}

	sort(sorted_Resources.begin(), sorted_Resources.end(), [](Resources* a, Resources* b)
		{
			return a->Get_Order() < b->Get_Order();
		}
	);
	return sorted_Resources;
}

vector<Resources*> Resource_Manager::Get_All_Resources()
{
	vector<Resources*> all_Resources;

	for (auto& resource : resources)
	{
		all_Resources.push_back(resource.second);
	}

	std::sort(all_Resources.begin(),all_Resources.end(),[](Resources* a, Resources* b)
		{
			return a->Get_Order() < b->Get_Order();
		}
	);

	return all_Resources;
}

void Resource_Manager::Add_Resource(const string name, string gathering_Destination, double quantity, double hardness, double worker_Cost, int order, bool unlocked, Resources::Resource_Type resource_Type_1, Resources::Resource_Type resource_Type_2, string smelting_Output)
{
	if (resources.find(name) == resources.end())
	{
		resources[name] = new Resources(name, gathering_Destination, quantity, hardness, worker_Cost,  order, unlocked, resource_Type_1, resource_Type_2, smelting_Output);
	}
}

void Resource_Manager::Add_Resource_Quantity(const string name, double amount)
{
	Resources* resource = Get_Resource(name);
	if (resource)
	{
		return resource->Add_Quantity(amount);
	}
	return;
}

void Resource_Manager::Sub_Resource_Quantity(const string name, double amount)
{
	Resources* resource = Get_Resource(name);
	if (resource)
	{
		return resource->Sub_Quantity(amount);
	}
	return;
}

void Resource_Manager::Remove_Resource(const string name)
{
	auto it = resources.find(name);
	if (it != resources.end())
	{
		delete it->second;
		resources.erase(it);
	}
}

void Resource_Manager::Create_All_Resources()
{
	Add_Resource("Thalions", "Quantity", 0, 0, 20, 0, true, Resources::Resource_Type::Currency, Resources::Resource_Type::None, "Thalions");
	Add_Resource("Hourglass", "Quantity", 0, 0, 20, 0, true, Resources::Resource_Type::Currency, Resources::Resource_Type::None, "Hourglass");
	Add_Resource("Paper", "Quantity", 0, 1000, 20, 0, true, Resources::Resource_Type::None, Resources::Resource_Type::None, "Paper");

	Add_Resource("SoftWood", "Quantity", 0, 10, 20, 0, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::Fuel, "SoftWood");
	Add_Resource("Stone", "Mined", 0, 25, 20, 1, false, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Stone");

	Add_Resource("Tin Ore", "Mined", 0, 100, 20, 2, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Tin");
	Add_Resource("Tin", "Quantity", 0, 100, 20, 2, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Tin");

	Add_Resource("Copper Ore", "Mined", 0, 500, 20, 3, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Copper");
	Add_Resource("Copper", "Quantity", 0, 500, 20, 3, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Copper");

	Add_Resource("Bronze", "Quantity", 0, 2500, 20, 4, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Bronze");

	Add_Resource("Lead Ore", "Mined", 0, 10000, 20, 5, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Lead");
	Add_Resource("Lead", "Quantity", 0, 10000, 20, 5, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Lead");

	Add_Resource("HardWood", "Quantity", 0, 20000, 20, 6, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::Fuel, "HardWood");

	Add_Resource("Silver Ore", "Mined", 0, 100000, 20, 7, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Silver");
	Add_Resource("Silver", "Quantity", 0, 100000, 20, 7, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Silver");

	Add_Resource("Iron Ore", "Mined", 0, 500000, 20, 8, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Iron");
	Add_Resource("Iron", "Quantity", 0, 500000, 20, 8, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Iron");

	Add_Resource("Gold Ore", "Mined", 0, 2500000, 20, 9, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Gold");
	Add_Resource("Gold", "Quantity", 0, 2500000, 20, 9, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Gold");

	Add_Resource("IronWood", "Quantity", 0, 10000000, 20, 10, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::Fuel, "IronWood");

	Add_Resource("Electrum", "Quantity", 0, 25000000, 20, 11, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Electrum");

	Add_Resource("Steel", "Quantity", 0, 150000000, 20, 12, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Steel");

	Add_Resource("Platinum Ore", "Mined", 0, 500000000, 20, 13, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Platinum");
	Add_Resource("Platinum", "Quantity", 0, 500000000, 20, 13, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Platinum");

	Add_Resource("Obsidian", "Mined", 0, 150000000, 20, 14, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Obsidian");

	Add_Resource("Adementine Ore", "Mined", 0, 1000000000, 20, 15, true, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Adementine");
	Add_Resource("Adementine", "Quantity", 0, 1000000000, 20, 15, true, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Adementine");
}
