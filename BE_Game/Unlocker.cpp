#include "precomp.h"
#include "Unlocker.h"

Unlocker::Unlocker(string name)
	:name(name), unlocked(false)
{
}

string Unlocker::Get_Name() const
{
	return name;
}

bool Unlocker::Get_Unlocked() const
{
	return unlocked;
}

void Unlocker::Set_Name(string n)
{
	name = n;
	return;
}

void Unlocker::Set_Unlocked(bool b)
{
	unlocked = b;
	return;
}
