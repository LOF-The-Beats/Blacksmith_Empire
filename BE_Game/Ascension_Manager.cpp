#include "precomp.h"
#include "Ascension_Manager.h"
#include "Resource_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"
#include "Player.h"
#include "Craftingtable_Manager.h"
#include "Draft_Manager.h"
#include "Ascension_Upgrades.h"


Ascension_Manager::Ascension_Manager()
	:base_Cost(10000)
{
}

double Ascension_Manager::Get_Base_Cost() const
{
	return base_Cost;
}

Ascension_Upgrades* Ascension_Manager::Get_Upgrade(string name)
{
	auto upgrade = upgrades.find(name);
	if (upgrade != upgrades.end())
	{
		return upgrade->second;
	}
	return nullptr;
}

void Ascension_Manager::Set_Base_Cost(double amount)
{
	base_Cost = amount;
	return;
}

void Ascension_Manager::Add_Upgrade(string name, string description, double max_Level, double cost, double world_X, double world_Y)
{
	if (upgrades.find(name) == upgrades.end())
	{
		upgrades[name] = new Ascension_Upgrades(name ,description, max_Level, cost, world_X, world_Y);
	}
}

void Ascension_Manager::Update_Gain_On_Reset(Resource_Manager* resource_Manager)
{
	auto thalions = resource_Manager->Get_Resource("Thalions");
	auto hourglasses = resource_Manager->Get_Resource("Hourglass");

	double cost = base_Cost;
	double gain = 0;

	while (thalions->Get_Quantity() >= cost)
	{
		gain++;
		cost *= 2;
	}
	hourglasses->Set_Gain_On_Reset(gain);
}

void Ascension_Manager::Ascend_Run(Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager, Draft_Manager* draft_Manager)
{
	auto all_Resources = resource_Manager->Get_All_Resources();
	auto all_Blueprints = blueprint_Manager->Get_All_Blueprints();
	auto all_Stats = player->Get_All_Stats();
	auto all_Craftingtables = craftingtable_Manager->Get_All_Craftingtables();

	for (size_t i = 0; i < all_Resources.size(); i++)
	{
		if (all_Resources[i]->Get_Name() == "Hourglass")
		{
			all_Resources[i]->Add_Quantity(all_Resources[i]->Get_Gain_On_Reset());
			all_Resources[i]->Set_Gain_On_Reset(0);
		}
		else
		{
			all_Resources[i]->Set_Quantity(all_Resources[i]->Get_Gain_On_Reset());
			all_Resources[i]->Set_Workers(0);
			all_Resources[i]->Set_Workers_Tool_Power(1);
			all_Resources[i]->Set_Worker_Cost(20);
			all_Resources[i]->Set_Worker_Tool_Equiped("None");
		}
	}

	for (size_t i = 0; i < all_Blueprints.size(); i++)
	{
		all_Blueprints[i]->Set_Level(1);
		all_Blueprints[i]->Set_Conversion_Rate(all_Blueprints[i]->Get_Base_Conversion_Rate());
		all_Blueprints[i]->Set_Unlocked(false);
	}
	blueprint_Manager->Get_Blueprints("Axe")->Set_Unlocked(true);

	for (size_t i = 0; i < all_Stats.size(); i++)
	{
		all_Stats[i]->Set_Exp(0);
		all_Stats[i]->Set_Exp_Needed(50);
		all_Stats[i]->Set_Level(1);
		all_Stats[i]->Set_Tool_Name("Hands");
		all_Stats[i]->Set_Tool_Power(1);
	}

	for (size_t i = 0; i < all_Craftingtables.size(); i++)
	{
		all_Craftingtables[i]->Set_Blueprint("None");
		all_Craftingtables[i]->Set_Resource("None");
		all_Craftingtables[i]->Set_In_Use(false);
		all_Craftingtables[i]->Set_Progress(0);
	}

	draft_Manager->Set_Blueprint_Card_1("None");
	draft_Manager->Set_Blueprint_Card_2("None");
	draft_Manager->Set_Blueprint_Card_3("None");
	draft_Manager->Set_Cost(10);

	item_Manager->Delete_All_Items();

}

vector<Ascension_Upgrades*> Ascension_Manager::Get_All_Upgrades()
{
	vector<Ascension_Upgrades*> all_Upgrades;
	for (auto& upgrade : upgrades)
	{
		all_Upgrades.push_back(upgrade.second);
	}

	return all_Upgrades;
}


void Ascension_Manager::Buy_Upgrades(string name, Resource_Manager* resource_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager)
{
	auto upgrade = Get_Upgrade(name);
	auto hourglass = resource_Manager->Get_Resource("Hourglass");

	if (!upgrade)
	{
		return;
	}

	if (upgrade->Get_Level() >= upgrade->Get_Max_Level())
	{
		return;
	}

	if (hourglass->Get_Quantity() < upgrade->Get_Cost())
	{
		return;
	}

	hourglass->Sub_Quantity(upgrade->Get_Cost());
	upgrade->Set_Level(upgrade->Get_Level() + 1);
	upgrade->Set_Cost(upgrade->Get_Cost() * 2);

	Apply_Upgrade(name, resource_Manager, player, craftingtable_Manager);
}

void Ascension_Manager::Create_Upgrades()
{
	Add_Upgrade("Stone", "Unlock the Stone resource", 1, 1, 500, 500);
	Add_Upgrade("Lumberjack", "Increase Lumberjack power by 1", 10, 1, 500, 400);
	Add_Upgrade("Crafting", "Increase Crafting power by 1", 10, 1, 680, 400);
	Add_Upgrade("Mining", "Increase Mining power by 1", 10, 1, 320, 400);
	Add_Upgrade("Workers Lumberjack", "Increase Worker Lumberjack power by 1", 10, 1, 500, 600);
	Add_Upgrade("Workers Craftingtable", "Increase Worker craftingtable power by 1", 10, 1, 680, 600);
	Add_Upgrade("Lumberjack Crit Chance", "Increase Lumberjack crit chance by 1%", 5, 10, 500, 300);
	Add_Upgrade("Lumberjack Knowledge", "Increase Lumberjack XP gain by 1", 1, 100, 680, 300);
	Add_Upgrade("Lumberjack Crit Power", "Increase Lumberjack crit power by 10%", 5, 100, 500, 200);
	Add_Upgrade("Lumberjack Growth", "Increase lumberjack strength gain after level up by 1", 1, 1000, 680, 200);
	Add_Upgrade("Crafting Knowledge", "Increase Crafting XP gain by 1", 1, 100, 860, 300);
	Add_Upgrade("Crafting Growth", "Increase Crafting strength gain after level up by 1", 1, 1000, 860, 200);
	Add_Upgrade("Crafting Unlock table", "Unlock extra Craftingtable", 1, 1000, 1040, 200);
	Add_Upgrade("Crafting Mass Production", "Can craft more items at a time", 1, 1000, 1040, 300);

}

void Ascension_Manager::Apply_Upgrade(string name, Resource_Manager* resource_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager)
{
	auto lumberjack = player->Get_Stats("Lumberjack");
	auto crafting = player->Get_Stats("Crafting");

	if (name == "Stone")
	{
		resource_Manager->Add_Resource("Stone", 0, 25, 0, true);
	}

	else if (name == "Lumberjack")
	{
		lumberjack->Add_Ascension_Power(1);
	}

	else if (name == "Crafting")
	{
		crafting->Add_Ascension_Power(1);
	}

	else if (name == "Mining")
	{
		player->Get_Stats("Mining")->Add_Ascension_Power(1);
	}

	else if (name == "Workers Lumberjack")
	{
		resource_Manager->Get_Resource("SoftWood")->Add_Workers_Ascension_Power(1);
	}

	else if (name == "Workers Craftingtable")
	{
		craftingtable_Manager->get_Craftingtable("Craftingtable 1")->Add_Worker_Ascension_Power(1);
	}

	else if (name == "Lumberjack Crit Chance")
	{
		lumberjack->Add_Crit_Chance(1);
	}
	
	else if (name == "Lumberjack Knowledge")
	{
		lumberjack->Add_Exp_Gain(1);
	}
	
	else if (name == "Lumberjack Crit Power")
	{
		lumberjack->Add_Crit_Power(0.1);
	}
	
	else if (name == "Lumberjack Growth")
	{
		lumberjack->Add_Growth(1);
		lumberjack->Set_Level(lumberjack->Get_Level() * lumberjack->Get_Growth() - 1);
	}

	else if (name == "Crafting Knowledge")
	{
		crafting->Add_Exp_Gain(1);
	}

	else if (name == "Crafting Growth")
	{
		crafting->Add_Growth(1);
		crafting->Set_Level(crafting->Get_Level() * crafting->Get_Growth() - 1);
	}

	else if (name == "Crafting Mass Production")
	{
		craftingtable_Manager->get_Craftingtable("Master Craftingtable")->Set_Mass_Production(true);
	}

	else if (name == "Crafting Unlock table")
	{
		craftingtable_Manager->get_Craftingtable("Craftingtable 2")->Set_Unlocked(true);
	}
}