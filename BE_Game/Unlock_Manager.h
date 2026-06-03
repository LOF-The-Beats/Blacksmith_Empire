#pragma once
#include "unordered_map"
#include "Unlocker.h"

class Resource_Manager;
class Player;

class Unlock_Manager
{
public:
	Unlock_Manager();

	//getters
	Unlocker* Get_Unlocked(const string name) const;

	// adder
	void Add_Unlocked(string name);

	//creation of all unlocks.
	void Create_All_Unlocks();

	//Unlocking of unlocks
	void Check_Unlock(Resource_Manager* resource_Manager, Player* player);

private:
	unordered_map<string, Unlocker*> unlocked;
};

