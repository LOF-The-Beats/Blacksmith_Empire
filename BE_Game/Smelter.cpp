#include "precomp.h"
#include "Smelter.h"

Smelter::Smelter(string name)
	:name(name), worker_Tool_Equiped("None"), fuel("None"), ore("None"), heat(0.0), heat_Loss (0.0), progress(0.0), workers(0), worker_Cost(20), worker_Tool_Power(1), worker_Ascension_Power(0), production_Rate(0.0)
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

string Smelter::Get_Worker_Tool_Equiped() const
{
	return worker_Tool_Equiped;
}

double Smelter::Get_Workers() const
{
	return workers;
}

double Smelter::Get_Worker_Tool_Power() const
{
	return worker_Tool_Power;
}

double Smelter::Get_Worker_Ascension_Power() const
{
	return worker_Ascension_Power;
}

double Smelter::Get_Worker_Cost() const
{
	return worker_Cost;
}

double Smelter::Get_Production_Rate() const
{
	return production_Rate;
}

double Smelter::Get_Heat() const
{
	return heat;
}

double Smelter::Get_Heat_Loss() const
{
	return heat_Loss;
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

void Smelter::Set_Worker_Tool_Equiped(string n)
{
	worker_Tool_Equiped = n;
	return;
}

void Smelter::Set_Workers(double amount)
{
	workers = amount;
	return;
}

void Smelter::Set_Worker_Tool_Power(double amount)
{
	worker_Tool_Power = amount;
	return;
}

void Smelter::Set_Worker_Ascension_Power(double amount)
{
	worker_Ascension_Power = amount;
	return;
}

void Smelter::Set_Worker_Cost(double amount)
{
	worker_Cost = amount;
	return;
}

void Smelter::Set_Production_Rate(double amount)
{
	production_Rate = amount;
	return;
}

void Smelter::Set_Heat(double amount)
{
	heat = amount;
	return;
}

void Smelter::Set_Heat_Loss(double amount)
{
	heat_Loss = amount;
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

void Smelter::Add_Worker(double amount)
{
	workers += amount;
	return;
}

void Smelter::Add_Worker_Tool_Power(double amount)
{
	worker_Tool_Equiped += amount;
	return;
}

void Smelter::Add_Worker_Ascension_Power(double amount)
{
	worker_Ascension_Power += amount;
	return;
}

void Smelter::Sub_Heat(double amount)
{
	heat -= amount;
	return;
}

void Smelter::Update_Production_Rate()
{
	if (workers > 0)
	{
		production_Rate = (workers + worker_Ascension_Power) * worker_Tool_Power;
	}
}

