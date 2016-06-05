#pragma once

#include"Employee.h"

class Sales :public Employee
{
public:
	Sales(std::string name);
	~Sales();
	int get_salary();
	int get_saled();
	void set_saled(int saled);
	void plus_saled(int plus);
private:
	int saled;

};

Sales::Sales(std::string name) :Employee(name)
{
}

Sales::~Sales()
{
}

inline int Sales::get_salary()
{
	return Employee::get_salary() + 0.2*saled;
}

inline int Sales::get_saled()
{
	return saled;
}

inline void Sales::set_saled(int saled)
{
	Sales::saled = saled;
}

inline void Sales::plus_saled(int plus)
{
	saled += plus;
}
