#pragma once
class Smelter
{
public:
	Smelter(string name);

	// Getters
	string Get_Name() const;
	string Get_Fuel() const;
	string Get_Ore() const;
	string Get_Worker_Tool_Equiped() const;
	double Get_Workers() const;
	double Get_Worker_Tool_Power() const;
	double Get_Worker_Ascension_Power() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;
	double Get_Heat() const;
	double Get_Heat_Loss() const;
	double Get_Progress() const;
	bool Get_Unlocked() const;

	// Setters
	void Set_Name(string n);
	void Set_Fuel(string n);
	void Set_Ore(string n);
	void Set_Worker_Tool_Equiped(string n);
	void Set_Workers(double amount);
	void Set_Worker_Tool_Power(double amount);
	void Set_Worker_Ascension_Power(double amount);
	void Set_Worker_Cost(double amount);
	void Set_Production_Rate(double amount);
	void Set_Heat(double amount);
	void Set_Heat_Loss(double amount);
	void Set_Progress(double amount);
	void Set_Unlocked(double b);

	// Adders
	void Add_Heat(double amount);
	void Add_Progress(double amount);
	void Add_Worker(double amount);
	void Add_Worker_Tool_Power(double amount);
	void Add_Worker_Ascension_Power(double amount);

	// Subtrackters
	void Sub_Heat(double amount);

	// updaters
	void Update_Production_Rate();

private:
	string name, fuel, ore, worker_Tool_Equiped;
	double heat, heat_Loss, progress, workers, worker_Tool_Power, worker_Ascension_Power, worker_Cost, production_Rate;
	bool unlocked;

	
};

