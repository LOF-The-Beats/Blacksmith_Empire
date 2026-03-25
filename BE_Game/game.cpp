#include "precomp.h"
#include "game.h"
#include "UI.h"
#include "Game_Manager.h"
#include "Player.h"


extern GLFWwindow* window;


void Game::Init()
{
	
	m_UI = new UI;
	m_Game_Manager = new Game_Manager;
	m_Player = new Player;

}


void Game::Tick(float deltaTime)
{
	screen->Clear(0);
	m_Game_Manager->Update_Mouse_Pos(m_Player);
	m_UI->UI_Layout(screen);
	m_Game_Manager->If_Clicked(m_Player);

	//printf("X= %f\n", m_Player->Get_Player_X());
	//printf("Y= %f\n", m_Player->Get_Player_Y());

}


