#pragma once
class Ascension_Upgrades
{
public:
	Ascension_Upgrades(string name, string description, double max_Level, double cost, double world_X, double world_Y);

	// Getters
	string Get_Name() const;
	string Get_Description() const;
	double Get_Level() const;
	double Get_Max_Level() const;
	double Get_Cost() const;
	double Get_World_X() const;
	double Get_World_Y() const;
	bool Get_Unlocked() const;
	int Get_Upgrade_State() const;

	// Setters
	void Set_Name(string n);
	void Set_Description(string n);
	void Set_Level(double amount);
	void Set_Max_Level(double amount);
	void Set_Cost(double amount);
	void Set_World_X(double amount);
	void Set_World_Y(double amount);
	void Set_Unlocked(bool b);

private:
	string name, description;
	double level, max_Level, cost, world_X, world_Y;
	bool unlocked;


};

