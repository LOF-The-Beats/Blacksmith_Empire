#pragma once
class Smelter
{
public:
	Smelter(string name);

	// Getters
	string Get_Name() const;
	string Get_Fuel() const;
	string Get_Ore() const;
	double Get_Heat() const;
	double Get_Progress() const;
	bool Get_Unlocked() const;

	// Setters
	void Set_Name(string n);
	void Set_Fuel(string n);
	void Set_Ore(string n);
	void Set_Heat(double amount);
	void Set_Progress(double amount);
	void Set_Unlocked(double b);

	// Adders
	void Add_Heat(double amount);
	void Add_Progress(double amount);

	// Subtrackters
	void Sub_Heat(double amount);

private:
	string name, fuel, ore;
	double heat, progress;
	bool unlocked;
};

