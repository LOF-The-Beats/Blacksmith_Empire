#pragma once
#include "Blueprints.h"
#include "unordered_map"
class Blueprint_Manager
{
public:
	Blueprint_Manager();

	//getters
	Blueprints* Get_Blueprints(const string name) const;
	vector<Blueprints*> Get_Sorted_Blueprints_Numbers();
	vector<Blueprints*> Get_All_Blueprints();
	vector<Blueprints*> Get_All_Unlocked_Blueprints();






	//adders
	void Add_Blueprints(const string name, string equip_Slot, const double conversion_Rate, double cost, double value, int order, double weight_Value, double strength_Value, double agility_Value, double vitality_Value, double luck_Value, double armor);

	//creator
	void Create_All_Blueprints();


private:
	unordered_map<string, Blueprints*> blueprints;
};


