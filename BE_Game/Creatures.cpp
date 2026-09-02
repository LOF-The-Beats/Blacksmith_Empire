#include "precomp.h"
#include "Creatures.h"
#include "Item_Manager.h"

Creatures::Creatures(Item_Manager* item_Manager, string name, string race
)
	: name(name),
	level(1),
	exp(0),
	exp_Needed(100),
	head_Slot("None"),
	chest_Slot("None"),
	legs_Slot("None"),
	hands_Slot("None"),
	feet_Slot("None"),
	main_Hand("None"),
	off_Hand("None")
{

	Set_Race(race);
	calculate_Stats(item_Manager);
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

string Creatures::Get_Head_Slot() const
{
	return head_Slot;
}

string Creatures::Get_Chest_Slot() const
{
	return chest_Slot;
}

string Creatures::Get_Legs_Slot() const
{
	return legs_Slot;
}

string Creatures::Get_Hands_Slot() const
{
	return hands_Slot;
}

string Creatures::Get_Feet_Slot() const
{
	return feet_Slot;
}

string Creatures::Get_Main_Hand() const
{
	return main_Hand;
}

string Creatures::Get_Off_Hand() const
{
	return off_Hand;
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

void Creatures::Set_Head_Slot(string new_Head_Slot)
{
	head_Slot = new_Head_Slot;
}

void Creatures::Set_Chest_Slot(string new_Chest_Slot)
{
	chest_Slot = new_Chest_Slot;
}

void Creatures::Set_Legs_Slot(string new_Legs_Slot)
{
	legs_Slot = new_Legs_Slot;
}

void Creatures::Set_Hands_Slot(string new_Hands_Slot)
{
	hands_Slot = new_Hands_Slot;
}

void Creatures::Set_Feet_Slot(string new_Feet_Slot)
{
	feet_Slot = new_Feet_Slot;
}

void Creatures::Set_Main_Hand(string new_Main_Hand)
{
	main_Hand = new_Main_Hand;
}

void Creatures::Set_Off_Hand(string new_Off_Hand)
{
	off_Hand = new_Off_Hand;
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
	else
	{
		strength = 1;
		vitality = 1;
		agility = 1;
		luck = 1;
	}
}

void Creatures::calculate_Stats(Item_Manager* item_Manager)
{
	auto all_Items = item_Manager->Get_All_Items();
	double item_Total_Strength = 0;
	double item_Total_Agility = 0;
	double item_Total_Vitality = 0;
	double item_Total_Luck = 0;
	double item_Total_Armor = 0;

	for (size_t i = 0; i < all_Items.size(); i++)
	{
		auto items = all_Items[i];

		if (items->Get_Name() == head_Slot ||
			items->Get_Name() == chest_Slot ||
			items->Get_Name() == legs_Slot ||
			items->Get_Name() == hands_Slot ||
			items->Get_Name() == feet_Slot ||
			items->Get_Name() == main_Hand ||
			items->Get_Name() == off_Hand)
		{
			item_Total_Strength = item_Total_Strength + items->Get_Strength();
			item_Total_Agility = item_Total_Agility + items->Get_Agility();
			item_Total_Vitality = item_Total_Vitality + items->Get_Vitality();
			item_Total_Luck = item_Total_Luck + items->Get_Luck();
			item_Total_Armor = item_Total_Armor + items->Get_Armor();
		}
	}

	max_Health = (strength + item_Total_Strength) + ((vitality + item_Total_Vitality) * 5);
	health = max_Health;
	damage = (strength + item_Total_Strength);
	armor = item_Total_Armor;
	armor_Pen = (40.0 * ((agility + item_Total_Agility) / ((agility + item_Total_Agility) + 10000.0))) + (10.0 * ((luck + item_Total_Luck) / ((luck + item_Total_Luck) + 10000.0)));
	speed = (agility + item_Total_Agility);
	crit_Chance = 5.0 + (70.0 * ((luck + item_Total_Luck) / ((luck + item_Total_Luck) + 1000.0)));
}
