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

void Resource_Manager::Add_Resource(const string name, double quantity)
{
	if (resources.find(name) == resources.end())
	{
		resources[name] = new Resources(name, quantity);
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
