#pragma once
class Stats
{
public:
	Stats(string name, double power);

	// Getters
	string Get_Name() const;
	string Get_Tool_Name() const;
	double Get_Power() const;
	double Get_Ascension_Power() const;
	double Get_Tool_Power() const;
	double Get_Exp() const;
	double Get_Exp_Gain() const;
	double Get_Exp_Needed() const;
	double Get_Level() const;
	double Get_Growth() const;
	double Get_Crit_Chance() const;
	double Get_Crit_Power() const;
	
	// Setters
	void Set_Name(string n);
	void Set_Tool_Name(string n);
	void Set_Power(double amount);
	void Set_Ascension_Power(double amount);
	void Set_Tool_Power(double amount);
	void Set_Exp(double amount);
	void Set_Exp_Gain(double amount);
	void Set_Exp_Needed(double amount);
	void Set_Level(double amount);
	void Set_Growth(double amount);
	void Set_Crit_Chance(double amount);
	void Set_Crit_Power(double amount);

	// adders
	void Add_Power(double amount);
	void Add_Ascension_Power(double amount);
	void Add_Exp(double amount);
	void Add_Exp_Gain(double amount);
	void Add_Exp_Needed(double amount);
	void Add_Level(double amount);
	void Add_Growth(double amount);
	void Add_Crit_Chance(double amount);
	void Add_Crit_Power(double amount);

	// Subtracters

	void Sub_Power(double amount);
	void Sub_Exp(double amount);
	void Sub_Exp_Needed(double amount);
	void Sub_Level(double amount);

	// checkers
	bool is_Crit();

private:
	string name;
	string tool_Name;
	double power;
	double ascension_Power;
	double tool_Power;
	double exp;
	double exp_Gain;
	double exp_Needed;
	double level;
	double growth;
	double crit_Chance;
	double crit_Power;
};


