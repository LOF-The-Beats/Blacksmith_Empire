#include "precomp.h"
#include "Draft_Manager.h"
#include "Blueprint_Manager.h"

Draft_Manager::Draft_Manager()
	:blueprint_Card_1(""), blueprint_Card_2(""), blueprint_Card_3(""), cost(10)
{
}

string Draft_Manager::Get_Blueprint_Card_1() const
{
	return blueprint_Card_1;
}

string Draft_Manager::Get_Blueprint_Card_2() const
{
	return blueprint_Card_2;
}

string Draft_Manager::Get_Blueprint_Card_3() const
{
	return blueprint_Card_3;
}

double Draft_Manager::Get_Cost() const
{
	return cost;
}

void Draft_Manager::Set_Blueprint_Card_1(string n)
{
	blueprint_Card_1 = n;
	return;
}
void Draft_Manager::Set_Blueprint_Card_2(string n)
{
	blueprint_Card_2 = n;
	return;
}
void Draft_Manager::Set_Blueprint_Card_3(string n)
{
	blueprint_Card_3 = n;
	return;
}

void Draft_Manager::Calculate_Cost()
{
	cost *= 5;
	return;
}

void Draft_Manager::Open_Draft_Screen(Blueprint_Manager* blueprint_Manager)
{
	if (blueprint_Card_1 == "" ||
		blueprint_Card_2 == "" ||
		blueprint_Card_3 == "")
	{
		Draft_Blueprint_Cards(blueprint_Manager);
	}
}

void Draft_Manager::Draft_Blueprint_Cards(Blueprint_Manager* blueprint_Manager)
{
	if (!blueprint_Manager->Get_Blueprints("Tools")->Get_Unlocked())
	{
		blueprint_Card_1 = "Tools";
		blueprint_Card_2 = "Tools";
		blueprint_Card_3 = "Tools";
	}
	else if (!blueprint_Manager->Get_Blueprints("Pickaxe")->Get_Unlocked())
	{
		blueprint_Card_1 = "Pickaxe";
		blueprint_Card_2 = "Pickaxe";
		blueprint_Card_3 = "Pickaxe";
	}
	else if (true)
	{
		blueprint_Card_1 = "Axe";
		blueprint_Card_2 = "Axe";
		blueprint_Card_3 = "Axe";
	}
}

