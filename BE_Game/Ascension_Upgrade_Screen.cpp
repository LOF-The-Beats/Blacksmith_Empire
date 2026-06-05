#include "precomp.h"
#include "Ascension_Upgrade_Screen.h"
#include "Player.h"


extern GLFWwindow* window;

Ascension_Upgrade_Screen::Ascension_Upgrade_Screen()
	:camera_X(0), camera_Y(0), last_Mouse_X(0), last_Mouse_Y(0),dragging(false)
{
}

double Ascension_Upgrade_Screen::Get_Camera_X() const
{
	return camera_X;
}

double Ascension_Upgrade_Screen::Get_Camera_Y() const
{
	return camera_Y;
}

double Ascension_Upgrade_Screen::Get_Last_Mouse_X() const
{
	return last_Mouse_X;
}

double Ascension_Upgrade_Screen::Get_Last_Mouse_Y() const
{
	return last_Mouse_Y;
}

bool Ascension_Upgrade_Screen::Get_Dragging() const
{
	return dragging;
}

void Ascension_Upgrade_Screen::Set_Camera_X(double amount)
{
	camera_X = amount;
	return;
}

void Ascension_Upgrade_Screen::Set_Camera_Y(double amount)
{
	camera_Y = amount;
	return;
}

void Ascension_Upgrade_Screen::Set_Last_Mouse_X(double amount)
{
	last_Mouse_X = amount;
	return;
}

void Ascension_Upgrade_Screen::Set_Last_Mouse_Y(double amount)
{
	last_Mouse_Y = amount;
	return;
}

void Ascension_Upgrade_Screen::Set_Dragging(bool b)
{
	dragging = b;
	return;
}

void Ascension_Upgrade_Screen::Update_Drag(Player* player)
{

	double view_X = 150;
	double view_Y = 50;
	double view_W = SCRWIDTH / 3 * 2;
	double view_H = 1000;

	bool mouse_Inside =
		player->Get_Player_X() >= view_X &&
		player->Get_Player_X() <= view_X + view_W &&
		player->Get_Player_Y() >= view_Y &&
		player->Get_Player_Y() <= view_Y + view_H;

	double mouse_X = player->Get_Player_X();
	double mouse_Y = player->Get_Player_Y();

	if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
	{
		if (!dragging && mouse_Inside)
		{
			dragging = true;
			last_Mouse_X = mouse_X;
			last_Mouse_Y = mouse_Y;
		}

		if (dragging)
		{
			double delta_X = mouse_X - last_Mouse_X;
			double delta_Y = mouse_Y - last_Mouse_Y;

			camera_X -= delta_X;
			camera_Y -= delta_Y;

			last_Mouse_X = mouse_X;
			last_Mouse_Y = mouse_Y;
		}
	}
	else
	{
		dragging = false;
	}
}

bool Ascension_Upgrade_Screen::Is_In_View(double screen_X, double screen_Y, double view_X, double view_Y, double view_W, double view_H)
{
	double button_W = 110;
	double button_H = 50;

	if (screen_X >= view_X &&
		screen_X + button_W <= view_X + view_W &&
		screen_Y >= view_Y &&
		screen_Y + button_H <= view_Y + view_H)
	{
		return true;
	}

	return false;
}

void Ascension_Upgrade_Screen::Center_On(double world_X, double world_Y)
{
	double view_X = 100;
	double view_Y = 50;
	double view_W = SCRWIDTH / 3 * 2 - 150;
	double view_H = 950;

	double button_W = 110;
	double button_H = 50;

	camera_X = world_X - (view_X + (view_W / 2)) + (button_W / 2);
	camera_Y = world_Y - (view_Y + (view_H / 2)) + (button_H / 2);
}
