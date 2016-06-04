#include "Employee.h"

Employee::Employee(const Employee & employee)
{
	this->name = employee.name;
	this->rank = employee.rank;
	this->age = employee.age;
	this->salary = employee.salary;
}

int Employee::caculateSalary()
{
	this->salary = rank * 1000;
	return rank * 1000;
}

int Sales::caculateSalary()
{
	this->salary = rank * 1000 + sale / 4;
	return rank * 1000 + sale / 4;
}
