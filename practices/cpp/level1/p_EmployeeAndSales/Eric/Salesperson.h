#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "Employee.h"

#define SALES_VOLUME_TO_SALARY_RATE 0.2

class Salesperson : public Employee
{
private:
	int salesVolume = 0;
public:
	Salesperson(std::string name, unsigned age, int rank) : Employee(name, age, rank){}
	void showInfo() override;
	void calSalary() override;
	void setSalesVolume(int volume);
};
#endif