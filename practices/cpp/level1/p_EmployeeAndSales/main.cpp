#include"Employee.h"
#include"Sales.h"
#include <iostream>

using namespace std;

int main()
{
    Employee emp("zhang",30,3);
    emp.GetSalary();
    Sales sales("wang",20,2,200);
    sales.GetSum();
    return 0;
}
