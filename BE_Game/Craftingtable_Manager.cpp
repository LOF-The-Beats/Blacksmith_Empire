#include "precomp.h"
#include "Craftingtable_Manager.h"

Craftingtable_Manager::Craftingtable_Manager()
{
}

Craftingtable* Craftingtable_Manager::get_Craftingtable(const string name) const
{
	auto it = craftingtable.find(name);
	if (it != craftingtable.end())
	{
		return it->second;
	}
	return nullptr;
}

vector<Craftingtable*> Craftingtable_Manager::Get_All_Craftingtables() const
{
	vector<Craftingtable*> all_Craftingtables;

	for (auto& craftingtables : craftingtable)
	{
		all_Craftingtables.push_back(craftingtables.second);
	}

	return all_Craftingtables;
}

void Craftingtable_Manager::Add_Craftingtable(const string name)
{
	if (craftingtable.find(name) == craftingtable.end())
	{
		craftingtable[name] = new Craftingtable(name);
	}
}
