#pragma once
class Blueprint_Manager;

class Draft_Manager
{
public:
	Draft_Manager();

	//getter
	string Get_Blueprint_Card_1() const;
	string Get_Blueprint_Card_2() const;
	string Get_Blueprint_Card_3() const;
	double Get_Cost() const;

	//setter
	void Set_Blueprint_Card_1(string n);
	void Set_Blueprint_Card_2(string n);
	void Set_Blueprint_Card_3(string n);
	


	// randomiser

	void Calculate_Cost();
	void Open_Draft_Screen(Blueprint_Manager* blueprint_Manager);
	void Draft_Blueprint_Cards(Blueprint_Manager* blueprint_Manager);

private:

	string blueprint_Card_1;
	string blueprint_Card_2;
	string blueprint_Card_3;
	double cost;
};

