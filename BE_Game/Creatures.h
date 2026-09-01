#pragma once
class Creatures
{
public:
	Creatures(string name, double strength, double agility, double vitality, double luck);

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
	double Get_Damage() const;
	double Get_Armor() const;
	double Get_Hit_Chance() const;
	double Get_Speed() const;
	double Get_Crit_Chance() const;
	double Get_Dodge_Chance() const;


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
	void Set_Damage(double new_Damage);
	void Set_Armor(double new_Armor);
	void Set_Hit_Chance(double new_Hit_Chance);
	void Set_Speed(double new_Speed);
	void Set_Crit_Chance(double new_Crit_Chance);
	void Set_Dodge_Chance(double new_Dodge_Chance);


	// Adders
	void Add_Level(double amount);
	void Add_Exp(double amount);

	void Add_Strength(double amount);
	void Add_Agility(double amount);
	void Add_Vitality(double amount);
	void Add_Luck(double amount);

	void Add_Health(double amount);
	void Add_Damage(double amount);
	void Add_Armor(double amount);
	void Add_Hit_Chance(double amount);
	void Add_Speed(double amount);
	void Add_Crit_Chance(double amount);
	void Add_Dodge_Chance(double amount);


	// Subtracters
	void Sub_Health(double amount);

	//Calculator
	void calculate_Stats();

private:

	string name;
	double level, exp, exp_Needed;
	double strength, agility, vitality, luck;
	double health, damage, armor, hit_Chance, speed, crit_Chance, dodge_Chance;
};

