#include "precomp.h"
#include "Resources.h"

Resources::Resources(string name, string gathering_Destination, double quantity, double hardness, double worker_Cost, int order, bool crafting_Resource, Resource_Type resource_Type_1, Resource_Type resource_Type_2)
	:name(name), gathering_Destination(gathering_Destination), quantity(quantity), mined(0.0), depth (1.0), depth_Cost(1000), gain_On_Reset(0.0), workers(0.0), worker_Cost(worker_Cost), production_Rate(0.0), hardness(hardness), worker_Tool_Power(1.0), worker_Ascension_Power(1), worker_Tool_Equiped("None"), order(order), crafting_Resource(crafting_Resource), time(0.0), collect_Time(60), collect_Workers(0.0), collect_Worker_Tool_Power(1.0), collect_Worker_Ascension_Power(1.0), collect_Rate(0.0), collect_Cost(100.0), time_Upgrade_Cost(250), time_Escalation(1.0), resource_Type_1(resource_Type_1), resource_Type_2(resource_Type_2), heat_Minimal(100)
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

string Resources::Get_Gathering_Destination() const
{
	return gathering_Destination;
}

int Resources::Get_Order() const
{
	return order;
}

double Resources::Get_Quantity() const
{
	return quantity;
}

double Resources::Get_Mined() const
{
	return mined;
}

double Resources::Get_Depth() const
{
	return depth;
}

double Resources::Get_Depth_Cost() const
{
	return depth_Cost;
}

double Resources::Get_Gain_On_Reset() const
{
	return gain_On_Reset;
}

double Resources::Get_Workers() const
{
	return workers;
}

double Resources::Get_Workers_Tool_Power() const
{
	return worker_Tool_Power;
}

double Resources::Get_Workers_Ascension_Power() const
{
	return worker_Ascension_Power;
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

double Resources::Get_Time() const
{
	return time;
}

double Resources::Get_Time_Escalation() const
{
	return time_Escalation;
}

double Resources::Get_Time_Upgrade_Cost() const
{
	return time_Upgrade_Cost;
}

double Resources::Get_Collect_Time() const
{
	return collect_Time;
}

double Resources::Get_Collect_Workers() const
{
	return collect_Workers;
}

double Resources::Get_Collect_Workers_Tool_Power() const
{
	return collect_Worker_Tool_Power;
}

double Resources::Get_Collect_Workers_Ascension_Power() const
{
	return collect_Worker_Ascension_Power;
}

double Resources::Get_Collect_Rate() const
{
	return collect_Rate;
}

double Resources::Get_Collect_Cost() const
{
	return collect_Cost;
}

double Resources::Get_Heat_Minimal() const
{
	return heat_Minimal;
}

double Resources::Get_Smelting_Time() const
{
	return smelting_Time;
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

void Resources::Set_Gathering_Destination(string n)
{
	gathering_Destination = n;
	return;
}

void Resources::Set_Quantity(double d)
{
	quantity = d;
	return;
}

void Resources::Set_Mined(double d)
{
	mined = d;
	return;
}

void Resources::Set_Depth(double d)
{
	depth = d;
	return;
}

void Resources::Set_Depth_Cost(double d)
{
	depth_Cost = d;
	return;
}

void Resources::Set_Gain_On_Reset(double d)
{
	gain_On_Reset = d;
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

void Resources::Set_Workers_Ascension_Power(double d)
{
	worker_Ascension_Power = d;
	return;
}

void Resources::Set_Worker_Cost(double d)
{
	worker_Cost = d;
	return;
}

void Resources::Set_Production_Rate(double d)
{
	production_Rate = d;
	return;
}

void Resources::Set_Hardness(double d)
{
	hardness = d;
	return;
}

void Resources::Set_Time(double d)
{
	time = d;
	return;
}

void Resources::Set_Time_Escalation(double d)
{
	time_Escalation = d;
	return;
}

void Resources::Set_Time_Upgrade_Cost(double d)
{
	time_Upgrade_Cost = d;
	return;
}

void Resources::Set_Collect_Time(double d)
{
	collect_Time = d;
	return;
}

void Resources::Set_Collect_Workers(double d)
{
	collect_Workers = d;
	return;
}

void Resources::Set_Collect_Workers_Tool_Power(double d)
{
	collect_Worker_Tool_Power = d;
	return;
}

void Resources::Set_Collect_Workers_Ascension_Power(double d)
{
	collect_Worker_Ascension_Power = d;
	return;
}

void Resources::Set_Collect_Rate(double d)
{
	collect_Rate = d;
	return;
}

void Resources::Set_Collect_Cost(double d)
{
	collect_Cost = d;
	return;
}

void Resources::Set_Heat_Minimal(double d)
{
	heat_Minimal = d;
	return;
}

void Resources::Set_Smelting_Time(double d)
{
	smelting_Time = d;
	return;
}

void Resources::Add_Quantity(double d)
{
	quantity += d;
	return;
}

void Resources::Add_Mined(double d)
{
	mined += d;
	return;
}

void Resources::Add_Depth(double d)
{
	depth += d;
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

void Resources::Add_Workers_Ascension_Power(double d)
{
	worker_Ascension_Power += d;
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

void Resources::Add_Time(double d)
{
	time += d;
	return;
}

void Resources::Add_Time_Escalaction(double d)
{
	time_Escalation += d;
	return;
}

void Resources::Add_Collect_Time(double d)
{
	collect_Time += d;
	return;
}

void Resources::Add_Collect_Workers(double d)
{
	collect_Workers += d;
	return;
}

void Resources::Add_Collect_Workers_Tool_Power(double d)
{
	collect_Worker_Tool_Power += d;
	return;
}

void Resources::Add_Collect_Workers_Ascension_Power(double d)
{
	collect_Worker_Ascension_Power += d;
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

void Resources::Sub_Collect_Time(double d)
{
	collect_Time -= d;
	return;
}

void Resources::Update_Production_Rate()
{
	if (workers > 0)
	{
		production_Rate = workers * worker_Ascension_Power * worker_Tool_Power;
	}
}

void Resources::Update_Collect_Rate()
{
	if (collect_Workers > 0)
	{
		collect_Rate = collect_Workers * collect_Worker_Ascension_Power * collect_Worker_Tool_Power;
	}
}

bool Resources::Check_Resource_Type(Resource_Type resource_Type) const
{
	if (resource_Type == resource_Type_1 ||
		resource_Type == resource_Type_2)
	{
		return true;
	}
	return false;
}
