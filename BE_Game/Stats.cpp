#include "precomp.h"
#include "Stats.h"

Stats::Stats(string name, double power)
	:name(name), power(power), exp(0), exp_Needed(50), level(1)
{
}

string Stats::Get_Name() const
{
	return name;
}

double Stats::Get_Power() const
{
	return power;
}

double Stats::Get_Exp() const
{
	return exp;
}

double Stats::Get_Exp_Needed() const
{
	return exp_Needed;
}

double Stats::Get_Level() const
{
	return level;
}

void Stats::Set_Name(string n)
{
	name = n;
	return;
}

void Stats::Set_Power(double amount)
{
	power = amount;
	return;
}

void Stats::Set_Exp(double amount)
{
	exp = amount;
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
void Stats::Add_Power(double amount)
{
	power += amount;
	return;
}

void Stats::Add_Exp(double amount)
{
	exp += amount;
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
