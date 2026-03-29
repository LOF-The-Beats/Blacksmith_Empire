#pragma once
class Resources
{
public:
	Resources(string name, double quantity = 0);

	//getters
	string Get_Name() const;
	double Get_Quantity() const;
	double Get_Workers() const;
	double Get_Worker_Cost() const;
	double Get_Production_Rate() const;

	//setters
	void Set_Name(string n);
	void Set_Quantity(double d);
	void Set_Workers(double d);
	void Set_Worker_Cost(double d);


	//adders
	void Add_Quantity(double d);
	void Add_Workers(double d);
	void Add_Worker_Cost(double d);



	//subtrackters
	void Sub_Quantity(double d);

	//updaters
	void Update_Production_Rate();

private:
	string name;
	double quantity;
	double workers;
	double worker_Cost;
	double production_Rate;

};

