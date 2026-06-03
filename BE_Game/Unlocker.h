#pragma once
class Unlocker
{
public:
	Unlocker(string name);

	//getters
	string Get_Name() const;
	bool Get_Unlocked() const;

	//setters
	void Set_Name(string n);
	void Set_Unlocked(bool b);


private:
	string name;
	bool unlocked;
};

