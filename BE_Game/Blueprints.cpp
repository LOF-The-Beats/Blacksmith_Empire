#include "precomp.h"
#include "Blueprints.h"

Blueprints::Blueprints(string name, string equip_Slot, double base_Conversion_Rate, double cost, double value,  int order, double weight_Value, double strength_Value, double agility_Value, double vitality_Value, double luck_Value, double armor)
	:name(name), equip_Slot(equip_Slot), conversion_Rate(base_Conversion_Rate), base_Conversion_Rate(base_Conversion_Rate), order(order), level(1.0), cost(cost), value(value), unlocked(false), researched(true), weight_Value(weight_Value), strength_Value(strength_Value), agility_Value(agility_Value), vitality_Value(vitality_Value), luck_Value(luck_Value), armor(armor)
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

double Blueprints::Get_value() const
{
	return value;
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

double Blueprints::Get_Weight_Value() const
{
	return weight_Value;
}

double Blueprints::Get_Strength_Value() const
{
	return strength_Value;
}

double Blueprints::Get_Agility_Value() const
{
	return agility_Value;
}

double Blueprints::Get_Vitality_Value() const
{
	return vitality_Value;
}

double Blueprints::Get_Luck_Value() const
{
	return luck_Value;
}

double Blueprints::Get_Armor() const
{
	return armor;
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

void Blueprints::Set_value(double amount)
{
	value = amount;
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
