#include "precomp.h"
#include "Creature_Manager.h"
#include "Item_Manager.h"

Creature_Manager::Creature_Manager()
{
}

Creatures* Creature_Manager::Get_Creatures(const string name) const
{
	auto it = creatures.find(name);
	if (it != creatures.end())
	{
		return it->second;
	}
	return nullptr;
}

void Creature_Manager::Add_Creature(Item_Manager* item_Manager, string name, string race)
{
	if (creatures.find(name) == creatures.end())
	{
		creatures[name] = new Creatures(item_Manager, name, race);
	}
}
