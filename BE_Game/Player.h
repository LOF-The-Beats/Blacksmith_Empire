#pragma once
#include "Stats.h"
#include "unordered_map"
class Player
{
public:
	Player();

	// getters
	double Get_Player_X() const;
	double Get_Player_Y() const;
	Stats* Get_Stats(const string name) const;
	vector<Stats*> Get_All_Stats() const;

	//setters

	void Set_Player_Pos(double x, double y);


	//adders
	void Add_Stats(const string name, double power);

	// Checkers
	

private:
	//mouse positions
	double player_X;
	double player_Y;

	unordered_map<string, Stats*> stats;
};

