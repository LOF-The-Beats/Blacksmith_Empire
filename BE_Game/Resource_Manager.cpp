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

vector<Resources*> Resource_Manager::Get_Sorted_Resources_Numbers()
{
	vector<Resources*> sorted_Resources;

	for (auto& resource : resources)
	{
		if (resource.second->Get_Crafting_Resource())
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

void Resource_Manager::Add_Resource(const string name, string gathering_Destination, double quantity, double hardness, double worker_Cost, int order, bool crafting_Resource)
{
	if (resources.find(name) == resources.end())
	{
		resources[name] = new Resources(name, gathering_Destination, quantity, hardness, worker_Cost,  order, crafting_Resource);
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
