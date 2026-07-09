#include "precomp.h"
#include "Craftingtable.h"

Craftingtable::Craftingtable(string name)
	:name(name), resource("None"), blueprint("None"), worker_Tool_Equiped("None"), in_Use(false), Mass_Production(false), unlocked(false), progress(0.0), workers(0), worker_Cost(20), worker_Tool_Power(1), worker_Ascension_Power(0), production_Rate(0.0)
{
}

string Craftingtable::Get_Resource() const
{
	return resource;
}

string Craftingtable::Get_Blueprint() const
{
	return blueprint;
}

string Craftingtable::Get_Worker_Tool_Equiped() const
{
	return worker_Tool_Equiped;
}

bool Craftingtable::Get_In_Use() const
{
	return in_Use;
}

bool Craftingtable::Get_Mass_Production() const
{
	return Mass_Production;
}

bool Craftingtable::Get_Unlocked() const
{
	return unlocked;
}

double Craftingtable::Get_Progress() const
{
	return progress;
}

double Craftingtable::Get_Worker() const
{
	return workers;
}

double Craftingtable::Get_Worker_Tool_Power() const
{
	return worker_Tool_Power;
}

double Craftingtable::Get_Worker_Ascension_Power() const
{
	return worker_Ascension_Power;
}

double Craftingtable::Get_Worker_Cost() const
{
	return worker_Cost;
}

double Craftingtable::Get_Production_Rate() const
{
	return production_Rate;
}

void Craftingtable::Set_Resource(string name)
{
	resource = name;
	return;
}

void Craftingtable::Set_Blueprint(string name)
{
	blueprint = name;
	return;
}

void Craftingtable::Set_Worker_Tool_Equiped(string name)
{
	worker_Tool_Equiped = name;
	return;
}

void Craftingtable::Set_In_Use(bool b)
{
	in_Use = b;
	return;
}

void Craftingtable::Set_Mass_Production(bool b)
{
	Mass_Production = b;
	return;
}

void Craftingtable::Set_Unlocked(bool b)
{
	unlocked = b;
	return;
}

void Craftingtable::Set_Progress(double amount)
{
	progress = amount;
	return;
}

void Craftingtable::Set_Worker(double amount)
{
	workers = amount;
	return;
}

void Craftingtable::Set_Worker_Tool_Power(double amount)
{
	worker_Tool_Power = amount;
	return;
}

void Craftingtable::Set_Worker_Ascension_Power(double amount)
{
	worker_Ascension_Power = amount;
	return;
}

void Craftingtable::Set_Worker_Cost(double amount)
{
	worker_Cost = amount;
	return;
}

void Craftingtable::Set_Production_Rate(double amount)
{
	production_Rate = amount;
}

void Craftingtable::Add_Progress(double amount)
{
	progress += amount;
	return;
}

void Craftingtable::Add_Worker(double amount)
{
	workers += amount;
	return;
}

void Craftingtable::Add_Worker_Tool_Power(double amount)
{
	worker_Tool_Power += amount;
	return;
}

void Craftingtable::Add_Worker_Ascension_Power(double amount)
{
	worker_Ascension_Power += amount;
	return;
}

void Craftingtable::Update_Production_Rate()
{
	if (workers > 0)
	{
		production_Rate = (workers + worker_Ascension_Power) * worker_Tool_Power;
	}
}
