#include "Employee.h"

double Employee::basicSalary = 1000.0;

double Employee::getSalary()
{
	return level * basicSalary;
}

Employee::Employee(std::string name, int age, int level):name(name),age(age),level(level)
{
}


Employee::~Employee()
{
}
