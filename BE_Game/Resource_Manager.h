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
	vector<Resources*> Get_Sorted_Resources_Numbers();
	vector<Resources*> Get_All_Resources();


	
	//adders
	void Add_Resource(const string name, string gathering_Destination, double quantity, double hardness, double worker_Cost, int order, bool crafting_Resource);
	void Add_Resource_Quantity(const string name, double amount);
	
	//subtrackters
	void Sub_Resource_Quantity(const string name, double amount);

	//removers
	void Remove_Resource(const string name);

private:
	unordered_map<string, Resources*> resources;

};

