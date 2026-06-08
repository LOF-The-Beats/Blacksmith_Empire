#pragma once
class UI;
class Game_Manager;
class Player;
class Resource_Manager;
class Craftingtable_Manager;
class Unlock_Manager;
class Window_Manager;

class Tutorial
{
public:
	Tutorial();

	// getter
	bool Get_Enabled() const;
	int Get_Tutorial_Step() const;
	int Get_Page() const;

	// setter

	void Set_Enabled(bool b);
	void Set_Tutorial_Step(int amount);
	void SetPage(int amount);


	void Draw_Tutorial_UI(Surface* screen, UI* ui, Player* player, Window_Manager* window_Manager);
	void Tutorial_Buttons(Game_Manager* game_Manager, Player* player, Resource_Manager* resourcemanager, Craftingtable_Manager* craftingtable_Manager, Unlock_Manager* unlock_Manager);

private:
	
	bool enabled;
	int tutorial_Step;
	int page;
};

