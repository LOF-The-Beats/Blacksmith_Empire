#pragma once
class Player;

class Ascension_Upgrade_Screen
{
public:
	Ascension_Upgrade_Screen();

	// getters
	double Get_Camera_X() const;
	double Get_Camera_Y() const;
	double Get_Last_Mouse_X() const;
	double Get_Last_Mouse_Y() const;
	bool Get_Dragging() const;

	//Setters
	void Set_Camera_X(double amount);
	void Set_Camera_Y(double amount);
	void Set_Last_Mouse_X(double amount);
	void Set_Last_Mouse_Y(double amount);
	void Set_Dragging(bool b);

	// other functions
	void Update_Drag(Player* player);
	bool Is_In_View(double screen_X, double screen_Y, double view_X, double view_Y, double view_W, double view_H);
	void Center_On(double world_X, double world_Y);

private:
	double camera_X;
	double camera_Y;
	double last_Mouse_X;
	double last_Mouse_Y;
	bool dragging;

};

