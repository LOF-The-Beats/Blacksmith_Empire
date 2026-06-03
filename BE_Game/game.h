// Template, 2024 IGAD Edition
// Get the latest version from: https://github.com/jbikker/tmpl8
// IGAD/NHTV/BUAS/UU - Jacco Bikker - 2006-2024

#pragma once

class UI;
class Game_Manager;
class Player;
class Resource_Manager;
class Window_Manager;
class Craftingtable_Manager;
class Blueprint_Manager;
class Item_Manager;
class Draft_Manager;
class Unlock_Manager;
class Tutorial;


namespace Tmpl8
{

class Game : public TheApp
{
public:
	// game flow methods
	void Init();
	void Tick( float deltaTime );
	void Shutdown() { /* implement if you want to do something on exit */ }
	// input handling
	void MouseUp( int ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { mousePos.x = x, mousePos.y = y; }
	void MouseWheel( float ) { /* implement if you want to handle the mouse wheel */ }
	void KeyUp( int ) { /* implement if you want to handle keys */ }
	void KeyDown( int ) { /* implement if you want to handle keys */ }
	// data members
	int2 mousePos;

	UI* m_UI;
	Game_Manager* m_Game_Manager;
	Player* m_Player;
	Resource_Manager* m_Resource_Manager;
	Window_Manager* m_Window_Manager;
	Craftingtable_Manager* m_Craftingtable_Manager;
	Blueprint_Manager* m_Blueprint_Manager;
	Item_Manager* m_Item_Manager;
	Draft_Manager* m_Draft_Manager;
	Unlock_Manager* m_Unlock_Manager;
	Tutorial* m_Tutorial;

};

} // namespace Tmpl8