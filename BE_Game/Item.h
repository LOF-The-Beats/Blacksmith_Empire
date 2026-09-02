#pragma once
class Item
{
public:
	Item(string name, string resource, string blueprint, string equip_Slot, double level, double value, double power, double weight, double strength, double agility, double vitality, double luck, double armor);

	//getters
	string Get_Name() const;
	string Get_Resource() const;
	string Get_Blueprint() const;
	string Get_Equip_Slot() const;
	double Get_Level() const;
	double Get_Power() const;
	double Get_Quantity() const;
	double Get_Value() const;
	double Get_Weight() const;
	double Get_Strength() const;
	double Get_Agility() const;
	double Get_Vitality() const;
	double Get_Luck() const;
	double Get_Armor() const;

	//setters
	void Set_Name(string n);
	void Set_Resource(string n);
	void Set_Blueprint(string n);
	void Set_Equip_Slot(string n);
	void Set_Level(double amount);
	void Set_Power(double amount);
	void Set_Quantity(double amount);
	void Set_Value(double amount);
	void Set_Weight(double amount);
	void Set_Strength(double amount);
	void Set_Agility(double amount);
	void Set_Vitality(double amount);
	void Set_Luck(double amount);
	void Set_Armor(double amount);

	//adders
	void Add_Level(double amount);
	void Add_Power(double amount);
	void Add_Quantity(double amount);

	
	//Subtrackters
	void Sub_Level(double amount);
	void Sub_Power(double amount);
	void Sub_Quantity(double amount);

private:

	string name , resource, blueprint, equip_Slot;
	double level, power, quantity, value;

	double weight, strength, agility, vitality, luck, armor;
};

