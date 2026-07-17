#pragma once
#include "Smelter.h"
#include <unordered_map>

class Smelter_Manager
{
public:
	Smelter_Manager();

	// Getters
	Smelter* Get_Smelter(string name);
	vector<Smelter*> Get_All_smelters();
	string Get_Active_Smelter() const;

	// Setters
	void Set_Active_Smelter(string n);

	// Adders
	void Add_Smelter(string name);

private:
	unordered_map<string, Smelter*> smelter;
	string active_Smelter;
};

