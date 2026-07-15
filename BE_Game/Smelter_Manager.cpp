#include "precomp.h"
#include "Smelter_Manager.h"

Smelter_Manager::Smelter_Manager()
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

void Smelter_Manager::Add_Smelter(string name)
{
	if (smelter.find(name) == smelter.end())
	{
		smelter[name] = new Smelter(name);
	}
}
