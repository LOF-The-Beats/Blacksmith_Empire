#pragma once
class Craftingtable
{
public:
	Craftingtable(string name);

	// getters
	string Get_Resource() const;
	string Get_Blueprint() const;
	bool Get_In_Use() const;
	double Get_Progress() const;

	// setter

	void Set_Resource(string name);
	void Set_Blueprint(string name);
	void Set_In_Use(bool b);
	void Set_Progress(double amount);
	
	//adders
	void Add_Progress(double amount);


private:
	string name;
	string resource;
	string blueprint;
	bool in_Use;
	double progress;
};

