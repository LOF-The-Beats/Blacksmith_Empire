#pragma once
#include "Craftingtable.h"
#include <unordered_map>

class Craftingtable_Manager
{
public:
	Craftingtable_Manager();

	//getters
	Craftingtable* get_Craftingtable(const string name) const;
	vector<Craftingtable*> Get_All_Craftingtables() const;

	//adders
	void Add_Craftingtable(const string name);

	


private:
	unordered_map<string, Craftingtable*> craftingtable;
};

