#pragma once
#include "Employee.h"
class Salesman :
	public Employee
{
public:
	Salesman(std::string name, int age, int level,double sale);
	~Salesman();
	double getSalary();
private:
	double sale;
};

