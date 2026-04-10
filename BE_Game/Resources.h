#pragma once
class Resources
{
public:
	Resources(string name, double quantity, double hardness);

	//getters
	string Get_Name() const;
	string Get_Worker_Tool_Equiped() const;
	double Get_Quantity() const;
	double Get_Workers() const;
	double Get_Workers_Tool_Power() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;
	double Get_Hardness() const;

	//setters
	void Set_Name(string n);
	void Set_Worker_Tool_Equiped(string n);
	void Set_Quantity(double d);
	void Set_Workers(double d);
	void Set_Workers_Tool_Power(double d);
	void Set_Worker_Cost(double d);
	void Set_Hardness(double d);


	//adders
	void Add_Quantity(double d);
	void Add_Workers(double d);
	void Add_Workers_Tool_Power(double d);
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
	double quantity;
	double workers;
	double worker_Tool_Power;
	double worker_Cost;
	double production_Rate;
	double hardness;

};

