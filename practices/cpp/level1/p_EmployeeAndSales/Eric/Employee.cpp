#include "Employee.h"

#include <string>
#include <iostream>

#define SALARY_PER_RANK 1000

void Employee::calBaseSalary()
{
	baseSalary = rank * SALARY_PER_RANK;
	calSalary();
}
void Employee::showInfo()
{
	std::cout << name << " age " << age << " rank : " << rank << " $ " << totalSalary << std::cout;
}
void Employee::setRank(int newRank)
{
	rank = newRank;
	calBaseSalary();
}
void Employee::calSalary()
{
	totalSalary = baseSalary;
}