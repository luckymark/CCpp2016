#include "Salesperson.h"
#include <iostream>

void Salesperson::showInfo()
{
	std::cout << name << " age " << age << " rank : " << rank << " sales-volume : " << salesVolume << " $ " << totalSalary << std::endl;
}
void Salesperson::calSalary()
{
	totalSalary = baseSalary + salesVolume * SALES_VOLUME_TO_SALARY_RATE;
}
void Salesperson::setSalesVolume(int volume)
{
	salesVolume = volume;
	calSalary();
}