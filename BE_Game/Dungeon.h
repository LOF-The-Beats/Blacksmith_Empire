#pragma once
#include "Creatures.h"
#include <unordered_map>
class Dungeon
{
public:
	Dungeon();

private:
	unordered_map<string, Creatures*> creatures;

};

