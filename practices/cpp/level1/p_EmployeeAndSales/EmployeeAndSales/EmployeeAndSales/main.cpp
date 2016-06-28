#include "Employee.h"
#include "Salesman.h"
#include <iostream>
int main()
{
	Employee aEmployee("Alice", 27, 5);
	Salesman aSalesman("Bob", 27, 4, 5540.2);
	std::cout << "Alice's Salary:" << aEmployee.getSalary() << std::endl;
	std::cout << "Bob's Salary:" << aSalesman.getSalary() << std::endl;
	return 0;
}