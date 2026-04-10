#pragma once
class Blueprints
{
public:
	Blueprints(string name);

	// getters
	string Get_Name() const;
	double Get_Level() const;
	double Get_Cost() const;
	bool Get_Unlocked() const;
	bool Get_Researched() const;

	//setters
	void Set_Name(string n);
	void Set_Level(double amount);
	void Set_Cost(double amount);
	void Set_Unlocked(bool b);
	void Set_Researched(bool b);


	// adders
	void Add_Level(double amount);
	void Add_Cost(double amount);



	// Subtracters
	void Sub_Level(double amount);
	void Sub_Cost(double amount);

private:
	string name;
	double level;
	double cost;
	bool unlocked;
	bool researched;

};

