#include "Salesman.h"



Salesman::Salesman(std::string name, int age, int level, double sale):Employee(name,age,level),sale(sale)
{
}


Salesman::~Salesman()
{
}

double Salesman::getSalary()
{
	return Employee::getSalary() + sale*0.2;
}
