#pragma once
#include "Blueprints.h"
#include "unordered_map"
class Blueprint_Manager
{
public:
	Blueprint_Manager();

	//getters
	Blueprints* Get_Blueprints(const string name) const;

	//adders
	void Add_Blueprints(const string name);
	
	//creator
	void Create_All_Blueprints();

private:
	unordered_map<string, Blueprints*> blueprints;
};

