#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:
	std::string name;
	unsigned age;
	int rank = 0;
	int baseSalary;
	int totalSalary;
}
#endif