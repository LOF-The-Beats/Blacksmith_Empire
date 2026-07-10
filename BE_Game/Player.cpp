#include "precomp.h"
#include "Player.h"

Player::Player()
	:player_X(0.0), player_Y(0.0), timer(0.0), idle_Timer(10.0), idle_Multiplier(1.0), idle_Deep_Timer(60.0), idle_Deep_Multiplier(1.0)
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

Stats* Player::Get_Stats(const string name) const
{
	auto it = stats.find(name);
	if (it != stats.end())
	{
		return it->second;
	}
	return nullptr;
}

vector<Stats*> Player::Get_All_Stats() const
{
	vector<Stats*> all_Stats;

	for (auto& stat : stats)
	{
		all_Stats.push_back(stat.second);
	}

	return all_Stats;
}

double Player::Get_Timer() const
{
	return timer;
}

double Player::Get_Idle_Timer() const
{
	return idle_Timer;
}

double Player::Get_Idle_Multiplier() const
{
	return idle_Multiplier;
}

double Player::Get_Idle_Deep_Timer() const
{
	return idle_Deep_Timer;
}

double Player::Get_Idle_Deep_Multiplier() const
{
	return idle_Deep_Multiplier;
}

void Player::Set_Player_Pos(double x, double y)
{
	player_X = x;
	player_Y = y;
	return;
}

void Player::Set_Timer(double amount)
{
	timer = amount;
	return;
}

void Player::Set_Idle_Timer(double amount)
{
	idle_Timer = amount;
	return;
}

void Player::Set_Idle_Multiplier(double amount)
{
	idle_Multiplier = amount;
	return;
}

void Player::Set_Idle_Deep_Timer(double amount)
{
	idle_Deep_Timer = amount;
	return;
}

void Player::Set_Idle_Deep_Multiplier(double amount)
{
	idle_Deep_Multiplier = amount;
	return;
}

void Player::Add_Stats(const string name, double power)
{
	if (stats.find(name) == stats.end())
	{
		stats[name] = new Stats(name, power);
	}
}

void Player::Add_Timer(double amount)
{
	timer += amount;
	return;
}

void Player::Add_Idle_Timer(double amount)
{
	idle_Timer += amount;
	return;
}

void Player::Add_Idle_Multiplier(double amount)
{
	idle_Multiplier += amount;
	return;
}

void Player::Add_Idle_Deep_Timer(double amount)
{
	idle_Deep_Timer += amount;
	return;
}

void Player::Add_Idle_Deep_Multiplier(double amount)
{
	idle_Deep_Multiplier += amount;
	return;
}

