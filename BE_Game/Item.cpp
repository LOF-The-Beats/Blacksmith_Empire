#include "precomp.h"
#include "Item.h"

Item::Item(string name, string resource, string blueprint, double level, double value, double power)
	:name(name), resource(resource), blueprint(blueprint), level(level), power(power), quantity(1.0), value(value)
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
