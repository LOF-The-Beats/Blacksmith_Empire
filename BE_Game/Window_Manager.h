#pragma once
#include <unordered_map>

class Window_Manager
{
public:
	Window_Manager();

	// getter
	string get_Active_Window() const;
	bool Get_Fullscreen() const;

	// setter
	void set_Active_Window(const string name);
	void set_NO_Active_Window();
	void Set_Fullscreen(bool b);

	// window settings
	void Apply_Fullscreen_Mode();
	void Apply_Windowed_Mode(int width, int height);

	// adder
	void add_Window(const string name, bool is_Active = false);

	// checkers
	bool is_Active() const;

private:
	unordered_map<string, bool> active_Window;

	bool fullscreen;
};