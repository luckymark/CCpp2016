#include <iostream>
#include<Employee.h>
#include<SalePeople.h>
using namespace std;

int main()
{
    Employee employee;
    employee.setImformation("Yang",18,6);
    cout<<employee.money()<<endl;
    SalePeople salePeople;
    salePeople.setImformation("Ding",20,4);
    salePeople.setSale(20000);
    cout<<salePeople.money()<<endl;
    return 0;
}
