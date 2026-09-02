#pragma once
class Item_Manager;
class Creatures
{
public:
	Creatures(Item_Manager* item_Manager, string name, string race);

	// Getters
	string Get_Name() const;
	double Get_Level() const;
	double Get_Exp() const;
	double Get_Exp_Needed() const;

	double Get_Strength() const;
	double Get_Agility() const;
	double Get_Vitality() const;
	double Get_Luck() const;

	double Get_Health() const;
	double Get_Max_Health() const;
	double Get_Damage() const;
	double Get_Armor() const;
	double Get_Armor_Pen() const;
	double Get_Speed() const;
	double Get_Crit_Chance() const;

	string Get_Head_Slot() const;
	string Get_Chest_Slot() const;
	string Get_Legs_Slot() const;
	string Get_Hands_Slot() const;
	string Get_Feet_Slot() const;
	string Get_Main_Hand() const;
	string Get_Off_Hand() const;


	// Setters
	void Set_Name(string new_Name);
	void Set_Level(double new_Level);
	void Set_Exp(double new_Exp);
	void Set_Exp_Needed(double new_Exp_Needed);

	void Set_Strength(double new_Strength);
	void Set_Agility(double new_Agility);
	void Set_Vitality(double new_Vitality);
	void Set_Luck(double new_Luck);

	void Set_Health(double new_Health);
	void Set_Max_Health(double new_Max_Health);
	void Set_Damage(double new_Damage);
	void Set_Armor(double new_Armor);
	void Set_Armor_Pen(double new_Armor_Pen);
	void Set_Speed(double new_Speed);
	void Set_Crit_Chance(double new_Crit_Chance);

	void Set_Head_Slot(string new_Head_Slot);
	void Set_Chest_Slot(string new_Chest_Slot);
	void Set_Legs_Slot(string new_Legs_Slot);
	void Set_Hands_Slot(string new_Hands_Slot);
	void Set_Feet_Slot(string new_Feet_Slot);
	void Set_Main_Hand(string new_Main_Hand);
	void Set_Off_Hand(string new_Off_Hand);


	// Adders
	void Add_Level(double amount);
	void Add_Exp(double amount);

	void Add_Strength(double amount);
	void Add_Agility(double amount);
	void Add_Vitality(double amount);
	void Add_Luck(double amount);

	void Add_Health(double amount);
	void Add_Max_Health(double amount);
	void Add_Damage(double amount);
	void Add_Armor(double amount);
	void Add_Armor_Pen(double amount);
	void Add_Speed(double amount);
	void Add_Crit_Chance(double amount);


	// Subtracters
	void Sub_Health(double amount);



	//Calculator
	void Set_Race(string race);
	void calculate_Stats(Item_Manager* item_Manager);

private:

	string name;
	double level, exp, exp_Needed;
	double strength, agility, vitality, luck;

	string head_Slot, chest_Slot, legs_Slot, hands_Slot, feet_Slot, main_Hand, off_Hand;
	double health, max_Health, damage, armor, armor_Pen, speed, crit_Chance;
};

