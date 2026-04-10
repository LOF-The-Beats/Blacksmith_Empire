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

void Blueprint_Manager::Add_Blueprints(const string name)
{
	if (blueprints.find(name) == blueprints.end())
	{
		blueprints[name] = new Blueprints(name);
	}
}

void Blueprint_Manager::Create_All_Blueprints()
{
	Add_Blueprints("Axe");
}
