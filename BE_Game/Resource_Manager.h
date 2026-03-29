#pragma once
#include "Resources.h"
#include <unordered_map>

class Resource_Manager
{
public:
	Resource_Manager();

	//getters
	Resources* Get_Resource(const string name) const;
	double Get_Resource_Quantity(const string name) const;
	
	//adders
	void Add_Resource(const string name, double quantity);
	void Add_Resource_Quantity(const string name, double amount);
	
	//subtrackters
	void Sub_Resource_Quantity(const string name, double amount);

	//removers
	void Remove_Resource(const string name);

private:
	unordered_map<string, Resources*> resources;

};

