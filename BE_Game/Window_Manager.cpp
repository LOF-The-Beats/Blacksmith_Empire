#include "precomp.h"
#include "Window_Manager.h"

Window_Manager::Window_Manager()
{
}

string Window_Manager::get_Active_Window() const

{
	for (const auto& active_Windows : active_Window)
	{
		if (active_Windows.second)
		{
			return active_Windows.first;
		}
	}
	return "";
}

void Window_Manager::set_Active_Window(const string name)
{
	for (auto& active_Windows : active_Window)
	{
		active_Windows.second = false;
	}

	if (active_Window.find(name) != active_Window.end())
	{
		active_Window[name] = true;
	}
}

void Window_Manager::set_NO_Active_Window()
{
	for (auto& active_Windows : active_Window)
	{
		active_Windows.second = false;
	}
}

void Window_Manager::add_Window(const string name, bool is_Active)
{
	active_Window[name] = is_Active;
	return;
}

bool Window_Manager::is_Active() const
{
	for (const auto& pair : active_Window) {
		if (pair.second)
		{
			return true;
		}
	}
	return false;
}
