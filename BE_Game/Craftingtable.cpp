#include "precomp.h"
#include "Craftingtable.h"

Craftingtable::Craftingtable(string name)
	:name(name), resource(""), blueprint(""), in_Use(false), progress(0.0)
{
}

string Craftingtable::Get_Resource() const
{
	return resource;
}

string Craftingtable::Get_Blueprint() const
{
	return blueprint;
}

bool Craftingtable::Get_In_Use() const
{
	return in_Use;
}

double Craftingtable::Get_Progress() const
{
	return progress;
}

void Craftingtable::Set_Resource(string name)
{
	resource = name;
	return;
}

void Craftingtable::Set_Blueprint(string name)
{
	blueprint = name;
	return;
}

void Craftingtable::Set_In_Use(bool b)
{
	in_Use = b;
	return;
}

void Craftingtable::Set_Progress(double amount)
{
	progress = amount;
	return;
}

void Craftingtable::Add_Progress(double amount)
{
	progress += amount;
	return;
}
