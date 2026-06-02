#include "precomp.h"
#include "Resources.h"

Resources::Resources(string name, double quantity, double hardness, int order, bool crafting_Resource)
	:name(name), quantity(quantity), workers(0.0), worker_Cost(20), production_Rate(0.0), hardness(hardness), worker_Tool_Power(1.0), worker_Tool_Equiped("None"), order(order), crafting_Resource(crafting_Resource)
{
}

string Resources::Get_Name() const
{
	return name;
}

string Resources::Get_Worker_Tool_Equiped() const
{
	return worker_Tool_Equiped;
}

int Resources::Get_Order() const
{
	return order;
}

double Resources::Get_Quantity() const
{
	return quantity;
}

double Resources::Get_Workers() const
{
	return workers;
}

double Resources::Get_Workers_Tool_Power() const
{
	return worker_Tool_Power;
}

double Resources::Get_Worker_Cost() const
{
	return worker_Cost;
}

double Resources::Get_Production_Rate() const
{
	return production_Rate;
}

double Resources::Get_Hardness() const
{
	return hardness;
}

bool Resources::Get_Crafting_Resource() const
{
	return crafting_Resource;
}

void Resources::Set_Name(string n)
{
	name = n;
	return;
}

void Resources::Set_Worker_Tool_Equiped(string n)
{
	worker_Tool_Equiped = n;
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

void Resources::Set_Workers_Tool_Power(double d)
{
	worker_Tool_Power = d;
	return;
}

void Resources::Set_Worker_Cost(double d)
{
	worker_Cost = d;
	return;
}

void Resources::Set_Hardness(double d)
{
	hardness = d;
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

void Resources::Add_Workers_Tool_Power(double d)
{
	worker_Tool_Power += d;
	return;
}

void Resources::Add_Worker_Cost(double d)
{
	worker_Cost += d;
	return;
}

void Resources::Add_Hardness(double d)
{
	hardness += d;
	return;
}

void Resources::Sub_Quantity(double d)
{
	quantity -= d;
	return;
}

void Resources::Sub_Hardness(double d)
{
	hardness -= d;
	return;
}

void Resources::Update_Production_Rate()
{
	production_Rate = workers * worker_Tool_Power;
}
