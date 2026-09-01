#include "precomp.h"
#include "Ascension_Upgrades.h"

Ascension_Upgrades::Ascension_Upgrades(string name, string description, double max_Level, double cost, double world_X, double world_Y)
	:name(name), description(description), level(0.0), max_Level(max_Level), cost(cost), world_X(world_X), world_Y(world_Y), unlocked(false)
{
}

string Ascension_Upgrades::Get_Name() const
{
	return name;
}

string Ascension_Upgrades::Get_Description() const
{
	return description;
}

double Ascension_Upgrades::Get_Level() const
{
	return level;
}

double Ascension_Upgrades::Get_Max_Level() const
{
	return max_Level;
}

double Ascension_Upgrades::Get_Cost() const
{
	return cost;
}

double Ascension_Upgrades::Get_World_X() const
{
	return world_X;
}

double Ascension_Upgrades::Get_World_Y() const
{
	return world_Y;
}

bool Ascension_Upgrades::Get_Unlocked() const
{
	return unlocked;
}

void Ascension_Upgrades::Set_Name(string n)
{
	name = n;
	return;
}

int Ascension_Upgrades::Get_Upgrade_State() const
{
	if (level >= max_Level)
	{
		return 2;
	}

	if (level > 0)
	{
		return 1;
	}

	return 0;
}

void Ascension_Upgrades::Set_Description(string n)
{
	description = n;
	return;
}

void Ascension_Upgrades::Set_Level(double amount)
{
	level = amount;
	return;
}

void Ascension_Upgrades::Set_Max_Level(double amount)
{
	max_Level = amount;
	return;
}

void Ascension_Upgrades::Set_Cost(double amount)
{
	cost = amount; 
	return;
}

void Ascension_Upgrades::Set_World_X(double amount)
{
	world_X = amount;
	return;
}

void Ascension_Upgrades::Set_World_Y(double amount)
{
	world_Y = amount;
	return;
}

void Ascension_Upgrades::Set_Unlocked(bool b)
{
	unlocked = b;
	return;
}

void Ascension_Upgrades::Add_Unlock(string name)
{
	unlocks.push_back(name);
}

vector<string> Ascension_Upgrades::Get_Unlocks() const
{
	return unlocks;
}
