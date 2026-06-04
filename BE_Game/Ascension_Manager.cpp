#include "precomp.h"
#include "Ascension_Manager.h"
#include "Resource_Manager.h"
#include "Blueprint_Manager.h"
#include "Item_Manager.h"
#include "Player.h"
#include "Craftingtable_Manager.h"

Ascension_Manager::Ascension_Manager()
	:base_Cost(10000)
{
}

double Ascension_Manager::Get_Base_Cost() const
{
	return base_Cost;
}

void Ascension_Manager::Set_Base_Cost(double amount)
{
	base_Cost = amount;
	return;
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

void Ascension_Manager::Ascend_Run(Resource_Manager* resource_Manager, Blueprint_Manager* blueprint_Manager, Item_Manager* item_Manager, Player* player, Craftingtable_Manager* craftingtable_Manager)
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

}
