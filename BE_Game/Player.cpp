#include "precomp.h"
#include "Player.h"

Player::Player()
	:player_X(0.0), player_Y(0.0), lumberjack_Power(1.0), lumberjack_Exp(0.0), lumberjack_Exp_Needed_Level_Up(50.0), lumberjack_Level(1.0), crafting_Power(1.0), crafting_Exp(0.0), crafting_Exp_Needed_Level_Up(50.0), crafting_Level(1.0)
{
}

double Player::Get_Player_X() const
{
	return player_X;
}

double Player::Get_Player_Y() const
{
	return player_Y;
}

double Player::Get_Lumberjack_Power() const
{
	return lumberjack_Power;
}

double Player::Get_Lumberjack_Exp() const
{
	return lumberjack_Exp;
}

double Player::Get_Lumberjack_Exp_Needed_Level_Up() const
{
	return lumberjack_Exp_Needed_Level_Up;
}

double Player::Get_Lumberjack_Level() const
{
	return lumberjack_Level;
}

double Player::Get_Crafting_Power() const
{
	return crafting_Power;
}

double Player::Get_Crafting_Exp() const
{
	return crafting_Exp;
}

double Player::Get_Crafting_Exp_Needed_Level_Up() const
{
	return crafting_Exp_Needed_Level_Up;
}

double Player::Get_Crafting_Level() const
{
	return crafting_Level;
}

void Player::Set_Player_Pos(double x, double y)
{
	player_X = x;
	player_Y = y;
	return;
}

void Player::Set_Lumberjack_Power(double amount)
{
	lumberjack_Power = amount;
	return;
}

void Player::Set_Lumberjack_Exp(double amount)
{
	lumberjack_Exp = amount;
	return;
}

void Player::Set_Lumberjack_Exp_Needed_Level_Up(double amount)
{
	lumberjack_Exp_Needed_Level_Up = amount;
	return;
}

void Player::Set_Lumberjack_Exp_Level(double amount)
{
	lumberjack_Level = amount;
	return;
}

void Player::Set_Crafting_Power(double amount)
{
	crafting_Power = amount;
	return;
}

void Player::Set_Crafting_Exp(double amount)
{
	crafting_Exp = amount;
	return;
}

void Player::Set_Crafting_Exp_Needed_Level_Up(double amount)
{
	crafting_Exp_Needed_Level_Up = amount;
	return;
}

void Player::Set_Crafting_Exp_Level(double amount)
{
	crafting_Level = amount;
	return;
}

void Player::Add_Lumberjack_Power(double amount)
{
	lumberjack_Power += amount;
	return;
}

void Player::Add_Lumberjack_Exp(double amount)
{
	lumberjack_Exp += amount;
	return;
}

void Player::Add_Lumberjack_Exp_Needed_Level_Up(double amount)
{
	lumberjack_Exp_Needed_Level_Up += amount;
	return;
}

void Player::Add_Lumberjack_Level(double amount)
{
	lumberjack_Level += amount;
	return;
}

void Player::Add_Crafting_Power(double amount)
{
	crafting_Power += amount;
	return;
}

void Player::Add_Crafting_Exp(double amount)
{
	crafting_Exp += amount;
	return;
}

void Player::Add_Crafting_Exp_Needed_Level_Up(double amount)
{
	crafting_Exp_Needed_Level_Up += amount;
	return;
}

void Player::Add_Crafting_Level(double amount)
{
	crafting_Level += amount;
	return;
}
