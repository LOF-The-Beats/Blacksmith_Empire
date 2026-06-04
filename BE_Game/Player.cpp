#include "precomp.h"
#include "Player.h"

Player::Player()
	:player_X(0.0), player_Y(0.0)
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

void Player::Set_Player_Pos(double x, double y)
{
	player_X = x;
	player_Y = y;
	return;
}

void Player::Add_Stats(const string name, double power)
{
	if (stats.find(name) == stats.end())
	{
		stats[name] = new Stats(name, power);
	}
}
