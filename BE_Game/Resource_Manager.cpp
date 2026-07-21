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

	Add_Resource("Tin Ore", "Mined", 0, 100, 20, 0, false, Resources::Resource_Type::Ore, Resources::Resource_Type::None, "Tin");
	Add_Resource("Tin", "Quantity", 0, 100, 20, 2, false, Resources::Resource_Type::Crafting, Resources::Resource_Type::None, "Tin");
}
