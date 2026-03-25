#pragma once
class Player
{
public:
	Player();

	// getters
	double Get_Player_X();
	double Get_Player_Y();

	//setters

	void Set_Player_Pos(double x, double y);

private:
	double player_X;
	double player_Y;
};

