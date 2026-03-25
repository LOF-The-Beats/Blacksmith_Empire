#include "precomp.h"
#include "Game_Manager.h"
#include "Player.h"

extern GLFWwindow* window;

Game_Manager::Game_Manager()
{
}

void Game_Manager::Update_Mouse_Pos(Player* player)
{
	double px = player->Get_Player_X();
	double py = player->Get_Player_Y();
	glfwGetCursorPos(window, &px, &py);
	player->Set_Player_Pos(px, py);
	return;
}

void Game_Manager::If_Clicked(Player* player)
{
}
