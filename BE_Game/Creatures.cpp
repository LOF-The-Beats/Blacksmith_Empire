#include "precomp.h"
#include "Creatures.h"

Creatures::Creatures(string name, double strength, double agility, double vitality, double luck)
	:name(name), strength(strength), agility(agility), vitality(vitality), luck(luck)
{
	calculate_Stats();
}

// Getters
string Creatures::Get_Name() const
{
	return name;
}

double Creatures::Get_Level() const
{
	return level;
}

double Creatures::Get_Exp() const
{
	return exp;
}

double Creatures::Get_Exp_Needed() const
{
	return exp_Needed;
}

double Creatures::Get_Strength() const
{
	return strength;
}

double Creatures::Get_Agility() const
{
	return agility;
}

double Creatures::Get_Vitality() const
{
	return vitality;
}

double Creatures::Get_Luck() const
{
	return luck;
}

double Creatures::Get_Health() const
{
	return health;
}

double Creatures::Get_Max_Health() const
{
	return max_Health;
}

double Creatures::Get_Damage() const
{
	return damage;
}

double Creatures::Get_Armor() const
{
	return armor;
}

double Creatures::Get_Armor_Pen() const
{
	return armor_Pen;
}

double Creatures::Get_Speed() const
{
	return speed;
}

double Creatures::Get_Crit_Chance() const
{
	return crit_Chance;
}



// Setters
void Creatures::Set_Name(string new_Name)
{
	name = new_Name;
}

void Creatures::Set_Level(double new_Level)
{
	level = new_Level;
}

void Creatures::Set_Exp(double new_Exp)
{
	exp = new_Exp;
}

void Creatures::Set_Exp_Needed(double new_Exp_Needed)
{
	exp_Needed = new_Exp_Needed;
}

void Creatures::Set_Strength(double new_Strength)
{
	strength = new_Strength;
}

void Creatures::Set_Agility(double new_Agility)
{
	agility = new_Agility;
}

void Creatures::Set_Vitality(double new_Vitality)
{
	vitality = new_Vitality;
}

void Creatures::Set_Luck(double new_Luck)
{
	luck = new_Luck;
}

void Creatures::Set_Health(double new_Health)
{
	health = new_Health;
}

void Creatures::Set_Max_Health(double new_Max_Health)
{
	max_Health = new_Max_Health;
}

void Creatures::Set_Damage(double new_Damage)
{
	damage = new_Damage;
}

void Creatures::Set_Armor(double new_Armor)
{
	armor = new_Armor;
}

void Creatures::Set_Armor_Pen(double new_Armor_Pen)
{
	armor_Pen = new_Armor_Pen;
}

void Creatures::Set_Speed(double new_Speed)
{
	speed = new_Speed;
}

void Creatures::Set_Crit_Chance(double new_Crit_Chance)
{
	crit_Chance = new_Crit_Chance;
}



// Adders
void Creatures::Add_Level(double amount)
{
	level += amount;
}

void Creatures::Add_Exp(double amount)
{
	exp += amount;
}

void Creatures::Add_Strength(double amount)
{
	strength += amount;
}

void Creatures::Add_Agility(double amount)
{
	agility += amount;
}

void Creatures::Add_Vitality(double amount)
{
	vitality += amount;
}

void Creatures::Add_Luck(double amount)
{
	luck += amount;
}

void Creatures::Add_Health(double amount)
{
	health += amount;
}

void Creatures::Add_Max_Health(double amount)
{
	max_Health += amount;
}

void Creatures::Add_Damage(double amount)
{
	damage += amount;
}

void Creatures::Add_Armor(double amount)
{
	armor += amount;
}

void Creatures::Add_Armor_Pen(double amount)
{
	armor_Pen += amount;
}

void Creatures::Add_Speed(double amount)
{
	speed += amount;
}

void Creatures::Add_Crit_Chance(double amount)
{
	crit_Chance += amount;
}



// Subtracters
void Creatures::Sub_Health(double amount)
{
	health -= amount;

	if (health < 0)
	{
		health = 0;
	}
}

void Creatures::Set_Race(string race)
{
	if (race == "Human")
	{
		strength = 1;
		vitality = 1;
		agility = 1;
		luck = 2;
	}
	else if (race == "Dwarf")
	{
		strength = 2;
		vitality = 1;
		agility = 1;
		luck = 1;
	}
	else if (race == "Elf")
	{
		strength = 1;
		vitality = 1;
		agility = 2;
		luck = 1;
	}
	else if (race == "Orc")
	{
		strength = 1;
		vitality = 2;
		agility = 1;
		luck = 1;
	}
}

void Creatures::calculate_Stats()
{
	max_Health = (strength) + (vitality * 5);
	health = max_Health;
	damage = (strength);
	armor = 0;
	armor_Pen = (40.0 * (agility / (agility + 10000.0))) + (10.0 * (luck / (luck + 10000.0)));
	speed = (agility);
	crit_Chance = 5.0 + (70.0 * (luck / (luck + 1000.0)));
}
