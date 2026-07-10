#include "precomp.h"
#include "Stats.h"

Stats::Stats(string name, double power)
	:name(name), power(power), ascension_Power(0), exp(0), exp_Gain(1.0), exp_Needed(50), level(1), growth(1.0), tool_Name("Hands"), tool_Power(1.0), crit_Chance(0.0), crit_Power(2.0)
{
}

string Stats::Get_Name() const
{
	return name;
}

string Stats::Get_Tool_Name() const
{
	return tool_Name;
}

double Stats::Get_Power() const
{
	return power;
}

double Stats::Get_Ascension_Power() const
{
	return ascension_Power;
}


double Stats::Get_Tool_Power() const
{
	return tool_Power;
}

double Stats::Get_Exp() const
{
	return exp;
}

double Stats::Get_Exp_Gain() const
{
	return exp_Gain;
}

double Stats::Get_Exp_Needed() const
{
	return exp_Needed;
}

double Stats::Get_Level() const
{
	return level;
}

double Stats::Get_Growth() const
{
	return growth;
}

double Stats::Get_Crit_Chance() const
{
	return crit_Chance;
}

double Stats::Get_Crit_Power() const
{
	return crit_Power;
}

void Stats::Set_Name(string n)
{
	name = n;
	return;
}

void Stats::Set_Tool_Name(string n)
{
	tool_Name = n;
	return;
}

void Stats::Set_Power(double amount)
{
	power = amount;
	return;
}

void Stats::Set_Ascension_Power(double amount)
{
	ascension_Power = amount;
	return;
}

void Stats::Set_Tool_Power(double amount)
{
	tool_Power = amount;
	return;
}

void Stats::Set_Exp(double amount)
{
	exp = amount;
	return;
}

void Stats::Set_Exp_Gain(double amount)
{
	exp_Gain = amount;
	return;
}

void Stats::Set_Exp_Needed(double amount)
{
	exp_Needed = amount;
	return;
}

void Stats::Set_Level(double amount)
{
	level = amount;
	return;
}
void Stats::Set_Growth(double amount)
{
	growth = amount;
	return;
}
void Stats::Set_Crit_Chance(double amount)
{
	crit_Chance = amount;
	return;
}
void Stats::Set_Crit_Power(double amount)
{
	crit_Power = amount;
	return;
}
void Stats::Add_Power(double amount)
{
	power += amount;
	return;
}

void Stats::Add_Ascension_Power(double amount)
{
	ascension_Power += amount;
	return;
}

void Stats::Add_Exp(double amount)
{
	exp += amount;
	return;
}

void Stats::Add_Exp_Gain(double amount)
{
	exp_Gain += amount;
	return;
}

void Stats::Add_Exp_Needed(double amount)
{
	exp_Needed += amount;
	return;
}

void Stats::Add_Level(double amount)
{
	level += amount;
	return;
}

void Stats::Add_Growth(double amount)
{
	growth += amount;
	return;
}

void Stats::Add_Crit_Chance(double amount)
{
	crit_Chance += amount;
	return;
}

void Stats::Add_Crit_Power(double amount)
{
	crit_Power += amount;
	return;
}

void Stats::Sub_Power(double amount)
{
	power -= amount;
	return;
}

void Stats::Sub_Exp(double amount)
{
	exp -= amount;
	return;
}

void Stats::Sub_Exp_Needed(double amount)
{
	exp_Needed -= amount;
	return;
}

void Stats::Sub_Level(double amount)
{
	level -= amount;
	return;
}

bool Stats::is_Crit()
{
	double roll = (rand() % 100) + 1; // 1 - 100

	return roll <= crit_Chance;
}
