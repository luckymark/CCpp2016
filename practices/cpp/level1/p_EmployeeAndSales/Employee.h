#pragma once

#include<iostream>
#include<string>

class Employee
{
public:
	Employee(std::string name);
	~Employee();
	void set_name(std::string name);
	std::string get_name();
	void set_age(int age);
	int get_age();
	void set_level(int level);
	int get_level();
	int get_salary();
private:
	std::string name;
	int age;
	int level;
	int salary;
};

Employee::Employee(std::string name)
{
	set_name(name);
}

Employee::~Employee()
{
}

inline void Employee::set_name(std::string name)
{
	Employee::name = name;
}

inline std::string Employee::get_name()
{
	return name;
}

inline void Employee::set_age(int age)
{
	Employee::age = age;
}

inline int Employee::get_age()
{
	return age;
}

inline void Employee::set_level(int level)
{
	Employee::level = level;
	salary = level * 1000;
}

inline int Employee::get_level()
{
	return level;
}

inline int Employee::get_salary()
{
	return salary;
}
