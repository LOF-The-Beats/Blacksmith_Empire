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

	double Get_Timer() const;
	double Get_Idle_Timer() const;
	double Get_Idle_Multiplier() const;
	double Get_Idle_Deep_Timer() const;
	double Get_Idle_Deep_Multiplier() const;

	//setters

	void Set_Player_Pos(double x, double y);
	void Set_Timer(double amount);
	void Set_Idle_Timer(double amount);
	void Set_Idle_Multiplier(double amount);
	void Set_Idle_Deep_Timer(double amount);
	void Set_Idle_Deep_Multiplier(double amount);


	//adders
	void Add_Stats(const string name, double power);
	void Add_Timer(double amount);
	void Add_Idle_Timer(double amount);
	void Add_Idle_Multiplier(double amount);
	void Add_Idle_Deep_Timer(double amount);
	void Add_Idle_Deep_Multiplier(double amount);

	// Checkers
	

private:
	//mouse positions
	double player_X;
	double player_Y;

	double timer;
	double idle_Timer;
	double idle_Multiplier;
	double idle_Deep_Timer;
	double idle_Deep_Multiplier;

	unordered_map<string, Stats*> stats;
};

