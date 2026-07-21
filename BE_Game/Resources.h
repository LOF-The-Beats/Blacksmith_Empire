#pragma once
class Resources
{



public:
	enum class Resource_Type
	{
		None,
		Fuel,
		Ore,
		Crafting,
		Currency
	};

	Resources(string name, string gathering_Destination, double quantity, double hardness, double worker_Cost, int order, bool crafting_Resource, Resource_Type resource_Type_1, Resource_Type resource_Type_2, string smelting_Output);

	//getters
	string Get_Name() const;
	string Get_Worker_Tool_Equiped() const;
	string Get_Gathering_Destination() const;
	int Get_Order() const;
	double Get_Quantity() const;
	double Get_Mined() const;
	double Get_Depth() const;
	double Get_Depth_Cost() const;
	double Get_Gain_On_Reset() const;
	double Get_Workers() const;
	double Get_Workers_Tool_Power() const;
	double Get_Workers_Ascension_Power() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;
	double Get_Hardness() const;
	bool Get_Unlocked() const;
	double Get_Time() const;
	double Get_Time_Escalation() const;
	double Get_Time_Upgrade_Cost() const;
	double Get_Collect_Time() const;
	double Get_Collect_Workers() const;
	double Get_Collect_Workers_Tool_Power() const;
	double Get_Collect_Workers_Ascension_Power() const;
	double Get_Collect_Rate() const;
	double Get_Collect_Cost() const;
	double Get_Heat_Minimal() const;
	double Get_Smelting_Time() const;
	string Get_Smelting_Output() const;

	//setters
	void Set_Name(string n);
	void Set_Worker_Tool_Equiped(string n);
	void Set_Gathering_Destination(string n);
	void Set_Quantity(double d);
	void Set_Mined(double d);
	void Set_Depth(double d);
	void Set_Depth_Cost(double d);
	void Set_Gain_On_Reset(double d);
	void Set_Workers(double d);
	void Set_Workers_Tool_Power(double d);
	void Set_Workers_Ascension_Power(double d);
	void Set_Worker_Cost(double d);
	void Set_Production_Rate(double d);
	void Set_Hardness(double d);
	void Set_Unlocked(bool b);
	void Set_Time(double d);
	void Set_Time_Escalation(double d);
	void Set_Time_Upgrade_Cost(double d);
	void Set_Collect_Time(double d);
	void Set_Collect_Workers(double d);
	void Set_Collect_Workers_Tool_Power(double d);
	void Set_Collect_Workers_Ascension_Power(double d);
	void Set_Collect_Rate(double d);
	void Set_Collect_Cost(double d);
	void Set_Heat_Minimal(double d);
	void Set_Smelting_Time(double d);
	void Set_Smelting_Output(string n);


	//adders
	void Add_Quantity(double d);
	void Add_Mined(double d);
	void Add_Depth(double d);
	void Add_Workers(double d);
	void Add_Workers_Tool_Power(double d);
	void Add_Workers_Ascension_Power(double d);
	void Add_Worker_Cost(double d);
	void Add_Hardness(double d);
	void Add_Time(double d);
	void Add_Time_Escalaction(double d);
	void Add_Collect_Time(double d);
	void Add_Collect_Workers(double d);
	void Add_Collect_Workers_Tool_Power(double d);
	void Add_Collect_Workers_Ascension_Power(double d);



	//subtrackters
	void Sub_Quantity(double d);
	void Sub_Hardness(double d);
	void Sub_Collect_Time(double d);

	//updaters
	void Update_Production_Rate();
	void Update_Collect_Rate();


	bool Check_Resource_Type(Resource_Type resource_Type) const;

	

private:
	string name;
	string worker_Tool_Equiped;
	string gathering_Destination;
	int order;
	double quantity;
	double mined;
	double depth;
	double depth_Cost;
	double gain_On_Reset;
	double workers;
	double worker_Tool_Power;
	double worker_Ascension_Power;
	double worker_Cost;
	double production_Rate;
	double hardness;
	bool unlocked;
	double time;
	double time_Escalation;
	double time_Upgrade_Cost;
	double collect_Time;
	double collect_Workers;
	double collect_Worker_Tool_Power;
	double collect_Worker_Ascension_Power;
	double collect_Rate;
	double collect_Cost;
	Resource_Type resource_Type_1;
	Resource_Type resource_Type_2;
	double heat_Minimal;
	double smelting_Time;
	string smelting_Output;


};

