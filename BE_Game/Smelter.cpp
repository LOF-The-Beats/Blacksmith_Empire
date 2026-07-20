#include "precomp.h"
#include "Smelter.h"

Smelter::Smelter(string name)
	:name(name), fuel("None"), ore("None"), heat(0.0), progress(0.0)
{
}

string Smelter::Get_Name() const
{
	return name;
}

string Smelter::Get_Fuel() const
{
	return fuel;
}

string Smelter::Get_Ore() const
{
	return ore;
}

double Smelter::Get_Heat() const
{
	return heat;
}

double Smelter::Get_Progress() const
{
	return progress;
}

bool Smelter::Get_Unlocked() const
{
	return unlocked;
}

void Smelter::Set_Name(string n)
{
	name = n;
	return;
}

void Smelter::Set_Fuel(string n)
{
	fuel = n;
	return;
}

void Smelter::Set_Ore(string n)
{
	ore = n;
	return;
}

void Smelter::Set_Heat(double amount)
{
	heat = amount;
	return;
}

void Smelter::Set_Progress(double amount)
{
	progress = amount;
	return;
}

void Smelter::Set_Unlocked(double b)
{
	unlocked = b;
	return;
}

void Smelter::Add_Heat(double amount)
{
	heat += amount;
	return;
}

void Smelter::Add_Progress(double amount)
{
	progress += amount;
	return;
}

void Smelter::Sub_Heat(double amount)
{
	heat -= amount;
	return;
}

