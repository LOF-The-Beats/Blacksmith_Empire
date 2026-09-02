#pragma once
#include "Creatures.h"
#include <unordered_map>

class Item_Manager;

class Creature_Manager
{
public:
	Creature_Manager();

	Creatures* Get_Creatures(const string name) const;

	void Add_Creature(Item_Manager* item_Manager, string name, string race);



private:
	unordered_map<string, Creatures*> creatures;
};

