#include "precomp.h"
#include "Blueprints.h"

Blueprints::Blueprints(string name)
	:name(name), level(1.0), cost(10.0), unlocked(false), researched(true)
{
}

string Blueprints::Get_Name() const
{
	return name;
}

double Blueprints::Get_Level() const
{
	return level;
}

double Blueprints::Get_Cost() const
{
	return cost;
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