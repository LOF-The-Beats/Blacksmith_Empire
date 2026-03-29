#pragma once
class Player
{
public:
	Player();

	// getters
	double Get_Player_X() const;
	double Get_Player_Y() const;
	double Get_Lumberjack_Power() const;
	double Get_Lumberjack_Exp() const;
	double Get_Lumberjack_Exp_Needed_Level_Up() const;
	double Get_Lumberjack_Level() const;
	double Get_Crafting_Power() const;
	double Get_Crafting_Exp() const;
	double Get_Crafting_Exp_Needed_Level_Up() const;
	double Get_Crafting_Level() const;

	//setters

	void Set_Player_Pos(double x, double y);
	void Set_Lumberjack_Power(double amount);
	void Set_Lumberjack_Exp(double amount);
	void Set_Lumberjack_Exp_Needed_Level_Up(double amount);
	void Set_Lumberjack_Exp_Level(double amount);
	void Set_Crafting_Power(double amount);
	void Set_Crafting_Exp(double amount);
	void Set_Crafting_Exp_Needed_Level_Up(double amount);
	void Set_Crafting_Exp_Level(double amount);

	//adders
	void Add_Lumberjack_Power(double amount);
	void Add_Lumberjack_Exp(double amount);
	void Add_Lumberjack_Exp_Needed_Level_Up(double amount);
	void Add_Lumberjack_Level(double amount);
	void Add_Crafting_Power(double amount);
	void Add_Crafting_Exp(double amount);
	void Add_Crafting_Exp_Needed_Level_Up(double amount);
	void Add_Crafting_Level(double amount);

private:
	//mouse positions
	double player_X;
	double player_Y;

	// player stats
	double lumberjack_Power;
	double lumberjack_Exp;
	double lumberjack_Exp_Needed_Level_Up;
	double lumberjack_Level;
	
	double crafting_Power;
	double crafting_Exp;
	double crafting_Exp_Needed_Level_Up;
	double crafting_Level;
};

