#pragma once
#include<string>
using namespace std;
class Employee
{
protected:
	string name;
	int age;
	int rank;
	int salary;
public:
	Employee(string name, int age, int rank) :name(name), age(age), rank(rank) {}
	Employee(const Employee &employee);
	virtual int caculateSalary();
};
class Sales :public Employee
{
private:
	int sale;
public:
	Sales(Employee &employee, int sale) :Employee(employee), sale(sale) {}
	Sales(string name, int age, int rank, int sale) :Employee(name, age, rank), sale(sale) {}
	int caculateSalary();
};