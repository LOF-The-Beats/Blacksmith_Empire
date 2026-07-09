#pragma once
class Craftingtable
{
public:
	Craftingtable(string name);

	// getters
	string Get_Resource() const;
	string Get_Blueprint() const;
	string Get_Worker_Tool_Equiped() const;
	bool Get_In_Use() const;
	bool Get_Mass_Production() const;
	bool Get_Unlocked() const;
	double Get_Progress() const;
	double Get_Worker() const;
	double Get_Worker_Tool_Power() const;
	double Get_Worker_Ascension_Power() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;

	// setter

	void Set_Resource(string name);
	void Set_Blueprint(string name);
	void Set_Worker_Tool_Equiped(string name);
	void Set_In_Use(bool b);
	void Set_Mass_Production(bool b);
	void Set_Unlocked(bool b);
	void Set_Progress(double amount);
	void Set_Worker(double amount);
	void Set_Worker_Tool_Power(double amount);
	void Set_Worker_Ascension_Power(double amount);
	void Set_Worker_Cost(double amount);
	void Set_Production_Rate(double amount);
	
	//adders
	void Add_Progress(double amount);
	void Add_Worker(double amount);
	void Add_Worker_Tool_Power(double amount);
	void Add_Worker_Ascension_Power(double amount);

	//updaters
	void Update_Production_Rate();


private:
	string name;
	string resource;
	string blueprint;
	bool in_Use;
	double progress;
	bool Mass_Production;
	bool unlocked;

	string worker_Tool_Equiped;
	double workers;
	double worker_Tool_Power;
	double worker_Ascension_Power;
	double worker_Cost;
	double production_Rate;
};

