#pragma once
class Stats
{
public:
	Stats(string name, double power);

	// Getters
	string Get_Name() const;
	double Get_Power() const;
	double Get_Exp() const;
	double Get_Exp_Needed() const;
	double Get_Level() const;
	
	// Setters
	void Set_Name(string n);
	void Set_Power(double amount);
	void Set_Exp(double amount);
	void Set_Exp_Needed(double amount);
	void Set_Level(double amount);

	// adders
	void Add_Power(double amount);
	void Add_Exp(double amount);
	void Add_Exp_Needed(double amount);
	void Add_Level(double amount);

	// Subtracters

	void Sub_Power(double amount);
	void Sub_Exp(double amount);
	void Sub_Exp_Needed(double amount);
	void Sub_Level(double amount);


private:
	string name;
	double power;
	double exp;
	double exp_Needed;
	double level;
};


