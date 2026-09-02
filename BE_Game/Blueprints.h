#pragma once
class Blueprints
{
public:
	Blueprints(string name, string equip_Slot, double base_Conversion_Rate, double cost, double value, int order, double weight_Value, double strength_Value, double agility_Value, double vitality_Value, double luck_Value, double armor);

	// getters
	string Get_Name() const;
	string Get_Equip_Slot() const;
	int Get_Order() const;
	double Get_Level() const;
	double Get_Cost() const;
	double Get_value() const;
	double Get_Conversion_Rate() const;
	double Get_Base_Conversion_Rate() const;
	bool Get_Unlocked() const;
	bool Get_Researched() const;
	double Get_Weight_Value() const;
	double Get_Strength_Value() const;
	double Get_Agility_Value() const;
	double Get_Vitality_Value() const;
	double Get_Luck_Value() const;
	double Get_Armor() const;

	//setters
	void Set_Name(string n);
	void Set_Level(double amount);
	void Set_Cost(double amount);
	void Set_value(double amount);
	void Set_Conversion_Rate(double amount);
	void Set_Base_Conversion_Rate(double amount);
	void Set_Unlocked(bool b);
	void Set_Researched(bool b);


	// adders
	void Add_Level(double amount);
	void Add_Cost(double amount);
	void Add_Conversion_Rate(double amount);



	// Subtracters
	void Sub_Level(double amount);
	void Sub_Cost(double amount);
	void Sub_Conversion_Rate(double amount);

private:
	string name;
	string equip_Slot;
	int order;
	double level;
	double cost;
	double value;
	double conversion_Rate;
	double base_Conversion_Rate;
	bool unlocked;
	bool researched;

	double weight_Value, strength_Value, agility_Value, vitality_Value, luck_Value, armor;

};

