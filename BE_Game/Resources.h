#pragma once
class Resources
{
public:
	Resources(string name, double quantity, double hardness, int order, bool crafting_Resource);

	//getters
	string Get_Name() const;
	string Get_Worker_Tool_Equiped() const;
	int Get_Order() const;
	double Get_Quantity() const;
	double Get_Mined() const;
	double Get_Depth() const;
	double Get_Gain_On_Reset() const;
	double Get_Workers() const;
	double Get_Workers_Tool_Power() const;
	double Get_Workers_Ascension_Power() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;
	double Get_Hardness() const;
	bool Get_Crafting_Resource() const;

	//setters
	void Set_Name(string n);
	void Set_Worker_Tool_Equiped(string n);
	void Set_Quantity(double d);
	void Set_Mined(double d);
	void Set_Depth(double d);
	void Set_Gain_On_Reset(double d);
	void Set_Workers(double d);
	void Set_Workers_Tool_Power(double d);
	void Set_Workers_Ascension_Power(double d);
	void Set_Worker_Cost(double d);
	void Set_Production_Rate(double d);
	void Set_Hardness(double d);


	//adders
	void Add_Quantity(double d);
	void Add_Mined(double d);
	void Add_Depth(double d);
	void Add_Workers(double d);
	void Add_Workers_Tool_Power(double d);
	void Add_Workers_Ascension_Power(double d);
	void Add_Worker_Cost(double d);
	void Add_Hardness(double d);



	//subtrackters
	void Sub_Quantity(double d);
	void Sub_Hardness(double d);

	//updaters
	void Update_Production_Rate();

private:
	string name;
	string worker_Tool_Equiped;
	int order;
	double quantity;
	double mined;
	double depth;
	double gain_On_Reset;
	double workers;
	double worker_Tool_Power;
	double worker_Ascension_Power;
	double worker_Cost;
	double production_Rate;
	double hardness;
	bool crafting_Resource;

};

