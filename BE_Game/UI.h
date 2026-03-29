#pragma once
class Resource_Manager;
class Player;
class Window_Manager;
class Craftingtable_Manager;

class UI
{
public:

	UI();
	//Layouts
	void Draw_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable);
	void UI_Layout(Surface* screen);
	void Forest_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player);
	void Forge_UI(Surface* screen, Resource_Manager* resource_Manager, Player* player, Window_Manager* window_Manager, Craftingtable_Manager* craftingtable);


	//Buttons
	void button_Standard(string name, string cost, int x1, int y1, Surface* screen);
	void button_Standard_Selected(string name, int x1, int y1, Surface* screen);

private:
};

