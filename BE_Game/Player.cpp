#include "precomp.h"
#include "Player.h"

Player::Player()
	:player_X(0.0), player_Y(0.0)
{
}

double Player::Get_Player_X()
{
	return player_X;
}

double Player::Get_Player_Y()
{
	return player_Y;
}

void Player::Set_Player_Pos(double x, double y)
{
	player_X = x;
	player_Y = y;
	return;
}
