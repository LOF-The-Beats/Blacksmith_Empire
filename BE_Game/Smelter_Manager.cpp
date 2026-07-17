#include "precomp.h"
#include "Smelter_Manager.h"

Smelter_Manager::Smelter_Manager()
	: active_Smelter("None")
{
}

Smelter* Smelter_Manager::Get_Smelter(string name)
{
	auto smelters = smelter.find(name);
	if (smelters != smelter.end())
	{
		return smelters->second;
	}
	return nullptr;
}

vector<Smelter*> Smelter_Manager::Get_All_smelters()
{
	vector<Smelter*> all_Smelters;
	for (auto& Smelters : smelter)
	{
		all_Smelters.push_back(Smelters.second);
	}

	return all_Smelters;
}

string Smelter_Manager::Get_Active_Smelter() const
{
	return active_Smelter;
}

void Smelter_Manager::Set_Active_Smelter(string n)
{
	active_Smelter = n;
	return;
}

void Smelter_Manager::Add_Smelter(string name)
{
	if (smelter.find(name) == smelter.end())
	{
		smelter[name] = new Smelter(name);
	}
}
