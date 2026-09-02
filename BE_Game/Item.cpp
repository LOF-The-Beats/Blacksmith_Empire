#include "precomp.h"
#include "Item.h"

Item::Item(string name, string resource, string blueprint, string equip_Slot, double level, double value, double power, double weight, double strength, double agility, double vitality, double luck, double armor)
	:name(name), resource(resource), blueprint(blueprint), equip_Slot(equip_Slot), level(level), power(power), quantity(1.0), value(value), weight(weight), strength(strength), agility(agility), vitality(vitality), luck(luck), armor(armor)
{
}

string Item::Get_Name() const
{
	return name;
}

string Item::Get_Resource() const
{
	return resource;
}

string Item::Get_Blueprint() const
{
	return blueprint;
}

string Item::Get_Equip_Slot() const
{
	return equip_Slot;
}

double Item::Get_Level() const
{
	return level;
}

double Item::Get_Power() const
{
	return power;
}

double Item::Get_Quantity() const
{
	return quantity;
}

double Item::Get_Value() const
{
	return value;
}

double Item::Get_Weight() const
{
	return weight;
}

double Item::Get_Strength() const
{
	return strength;
}

double Item::Get_Agility() const
{
	return agility;
}

double Item::Get_Vitality() const
{
	return vitality;
}

double Item::Get_Luck() const
{
	return luck;
}

double Item::Get_Armor() const
{
	return armor;
}

void Item::Set_Name(string n)
{
	name = n;
	return;
}

void Item::Set_Resource(string n)
{
	resource = n;
	return;
}

void Item::Set_Blueprint(string n)
{
	blueprint = n;
	return;
}

void Item::Set_Equip_Slot(string n)
{
	equip_Slot = n;
	return;
}

void Item::Set_Level(double amount)
{
	level = amount;
	return;
}

void Item::Set_Power(double amount)
{
	power = amount;
	return;
}

void Item::Set_Quantity(double amount)
{
	quantity = amount;
	return;
}

void Item::Set_Value(double amount)
{
	value = amount;
	return;
}

void Item::Set_Weight(double amount)
{
	weight = amount;
}

void Item::Set_Strength(double amount)
{
	strength = amount;
}

void Item::Set_Agility(double amount)
{
	agility = amount;
}

void Item::Set_Vitality(double amount)
{
	vitality = amount;
}

void Item::Set_Luck(double amount)
{
	luck = amount;
}

void Item::Set_Armor(double amount)
{
	armor = amount;
}

void Item::Add_Level(double amount)
{
	level += amount;
	return;
}

void Item::Add_Power(double amount)
{
	power += amount;
	return;
}

void Item::Add_Quantity(double amount)
{
	quantity += amount;
	return;
}

void Item::Sub_Level(double amount)
{
	level -= amount;
	return;
}

void Item::Sub_Power(double amount)
{
	power -= amount;
	return;
}

void Item::Sub_Quantity(double amount)
{
	quantity -= amount;
	return;
}
