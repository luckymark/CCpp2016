#include<iostream>
#include<string>
#include"Sales.h"

using namespace std;

int main()
{
	Employee employee("John");
	Sales saler("Wonston");

	employee.set_level(1);
	employee.set_age(20);

	saler.set_level(2);
	saler.set_age(25);
	saler.set_saled(1000);
	saler.plus_saled(1000);
	cout << employee.get_name() << endl << employee.get_age() << endl << employee.get_salary() << endl << endl;
	cout << saler.get_name() << endl << saler.get_age() << endl << saler.get_saled() << endl << saler.get_salary() << endl;

	system("pause");

	return 0;
}