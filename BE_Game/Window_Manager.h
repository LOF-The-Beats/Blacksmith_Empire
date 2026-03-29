#pragma once
#include <unordered_map>

class Window_Manager
{
public:
	Window_Manager();

	// getter

	string get_Active_Window() const;

	// setter

	void set_Active_Window(const string name);
	void set_NO_Active_Window();

	// adder

	void add_Window(const string name, bool is_Active = false);

	// checkers

	bool is_Active() const;

private:
	unordered_map<string, bool> active_Window;
};

