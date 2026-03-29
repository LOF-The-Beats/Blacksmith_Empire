#include "precomp.h"
#include "Resources.h"

Resources::Resources(string name, double quantity)
	:name(name), quantity(quantity), workers(0.0), worker_Cost(20), production_Rate(0.0)
{
}

string Resources::Get_Name() const
{
	return name;
}

double Resources::Get_Quantity() const
{
	return quantity;
}

double Resources::Get_Workers() const
{
	return workers;
}

double Resources::Get_Worker_Cost() const
{
	return worker_Cost;
}

double Resources::Get_Production_Rate() const
{
	return production_Rate;
}

void Resources::Set_Name(string n)
{
	name = n;
	return;
}

void Resources::Set_Quantity(double d)
{
	quantity = d;
	return;
}

void Resources::Set_Workers(double d)
{
	workers = d;
	return;
}

void Resources::Set_Worker_Cost(double d)
{
	worker_Cost = d;
	return;
}

void Resources::Add_Quantity(double d)
{
	quantity += d;
	return;
}

void Resources::Add_Workers(double d)
{
	workers += d;
	return;
}

void Resources::Add_Worker_Cost(double d)
{
	worker_Cost += d;
	return;
}

void Resources::Sub_Quantity(double d)
{
	quantity -= d;
	return;
}

void Resources::Update_Production_Rate()
{
	production_Rate = workers;
}
