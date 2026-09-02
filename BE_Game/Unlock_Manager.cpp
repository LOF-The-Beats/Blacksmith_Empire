#include "precomp.h"
#include "Unlock_Manager.h"
#include "Resource_Manager.h"
#include "Player.h"

Unlock_Manager::Unlock_Manager()
{
}

Unlocker* Unlock_Manager::Get_Unlocked(const string name) const
{
	auto it = unlocked.find(name);
	if (it != unlocked.end())
	{
		return it->second;
	}
	return nullptr;
}

void Unlock_Manager::Add_Unlocked(string name)
{
	if (unlocked.find(name) == unlocked.end())
	{
		unlocked[name] = new Unlocker(name);
	}
}

void Unlock_Manager::Create_All_Unlocks()
{
	Add_Unlocked("Forest");
	Add_Unlocked("Forge");
	Add_Unlocked("Player");
	Add_Unlocked("Libary");
	Add_Unlocked("Witch Hut");
	Add_Unlocked("Mine");
	Add_Unlocked("Dungeon");
	Add_Unlocked("Settings");


	Get_Unlocked("Forest")->Set_Unlocked(true);

}

void Unlock_Manager::Check_Unlock(Resource_Manager* resource_Manager, Player* player)
{
	if (resource_Manager->Get_Resource("SoftWood")->Get_Quantity() >= 20 &&
		!Get_Unlocked("Forge")->Get_Unlocked())
	{
		Get_Unlocked("Forge")->Set_Unlocked(true);
	}
	if (player->Get_Stats("Crafting")->Get_Level() >= 2 &&
		!Get_Unlocked("Player")->Get_Unlocked())
	{
		Get_Unlocked("Player")->Set_Unlocked(true);
	}
	if (resource_Manager->Get_Resource("SoftWood")->Get_Quantity() >= 1000 &&
		!Get_Unlocked("Libary")->Get_Unlocked())
	{
		Get_Unlocked("Libary")->Set_Unlocked(true);
	}
	if (resource_Manager->Get_Resource("Hourglass")->Get_Gain_On_Reset() >= 1 &&
		!Get_Unlocked("Witch Hut")->Get_Unlocked())
	{
		Get_Unlocked("Witch Hut")->Set_Unlocked(true);
	}
	if (resource_Manager->Get_Resource("Stone")->Get_Unlocked() &&
		!Get_Unlocked("Mine")->Get_Unlocked())
	{
		Get_Unlocked("Mine")->Set_Unlocked(true);
	}
	if (resource_Manager->Get_Resource("Softwood") &&
		!Get_Unlocked("Settings")->Get_Unlocked())
	{
		Get_Unlocked("Settings")->Set_Unlocked(true);
	}


	if (resource_Manager->Get_Resource("Stone")->Get_Depth() >= 25)
	{
		resource_Manager->Get_Resource("Tin")->Set_Unlocked(true);
		resource_Manager->Get_Resource("Tin Ore")->Set_Unlocked(true);
	}

}
