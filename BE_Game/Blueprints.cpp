#include "precomp.h"
#include "Blueprints.h"

Blueprints::Blueprints(string name, string equip_Slot, double conversion_Rate, int order)
	:name(name), equip_Slot(equip_Slot), conversion_Rate(conversion_Rate), order(order), level(1.0), cost(10.0), unlocked(false), researched(true)
{
}


string Blueprints::Get_Name() const
{
	return name;
}

string Blueprints::Get_Equip_Slot() const
{
	return equip_Slot;
}

int Blueprints::Get_Order() const
{
	return order;
}

double Blueprints::Get_Level() const
{
	return level;
}

double Blueprints::Get_Cost() const
{
	return cost;
}

double Blueprints::Get_Conversion_Rate() const
{
	return conversion_Rate;
}

double Blueprints::Get_Base_Conversion_Rate() const
{
	return base_Conversion_Rate;
}

bool Blueprints::Get_Unlocked() const
{
	return unlocked;
}

bool Blueprints::Get_Researched() const
{
	return researched;
}

void Blueprints::Set_Name(string n)
{
	name = n;
	return;
}

void Blueprints::Set_Level(double amount)
{
	level = amount;
	return;
}

void Blueprints::Set_Cost(double amount)
{
	cost = amount;
	return;
}

void Blueprints::Set_Conversion_Rate(double amount)
{
	conversion_Rate = amount;
	return;
}

void Blueprints::Set_Base_Conversion_Rate(double amount)
{
	base_Conversion_Rate = amount;
	return;
}

void Blueprints::Set_Unlocked(bool b)
{
	unlocked = b;
	return;
}

void Blueprints::Set_Researched(bool b)
{
	researched = b;
	return;
}

void Blueprints::Add_Level(double amount)
{
	level += amount;
	return;
}

void Blueprints::Add_Cost(double amount)
{
	cost += amount;
	return;
}
void Blueprints::Add_Conversion_Rate(double amount)
{
	conversion_Rate += amount;
		return;
}
void Blueprints::Sub_Level(double amount)
{
	level -= amount;
	return;
}

void Blueprints::Sub_Cost(double amount)
{
	cost -= amount;
	return;
}

void Blueprints::Sub_Conversion_Rate(double amount)
{
	conversion_Rate -= amount;
	return;
}
