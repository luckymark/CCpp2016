#include<iostream>
#include"Employee.h"
using namespace std;
int main()
{
	Employee *employee;
	Employee employeee("aaa", 20, 6);
	Sales employees("bbb", 20, 6, 10000);
	employee = &employeee;
	cout << employee->caculateSalary() << endl;
	employee = &employees;
	cout << employee->caculateSalary() << endl;
}