#pragma once
#include <string>
class Employee
{
public:
	virtual double getSalary();
	Employee(std::string name,int age,int level);
	~Employee();
protected:
	static double basicSalary;
private:
	std::string name;
	int age;
	int level;
};

