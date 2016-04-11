#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
protected:
	std::string name;
	unsigned age;
	int rank = 1;
	int baseSalary;
	int totalSalary;
	void calBaseSalary();
public:
	Employee(std::string name, unsigned age, int rank) : name(name), age(age), rank(rank)
	{
		calBaseSalary();
	}
	virtual void showInfo();
	void setRank(int newRank);
	virtual void calSalary();
};
#endif