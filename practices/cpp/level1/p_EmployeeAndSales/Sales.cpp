#include "Sales.h"
#include<iostream>
using namespace std;
Sales::Sales(string name,int age,int level,int SalesNum) : Employee(name,age,level)
{
    SetName(name);
    SetAge(age);
    SetLevel(level);
    SetSalesNum(SalesNum);

}
void Sales::SetSalesNum(int SalesNum)
{
    this->SalesNum=SalesNum;
}
int Sales::GetSalesNum()
{
    return this->SalesNum;
}
void Sales::GetSum()
{
    cout<<GetSalesNum()*0.2+GetLevel()*1000<<endl;
}

/*Sales::Sales(int money, string name, int time, int add) : Employee(money, name, time)
{
    SetName(name);
    SetSalary(money);
    SetTime(time);
    SetAdd(add);
}

void Sales::SetAdd(int add)
{
    this->add = add;
}

int Sales::GetAdd()
{
    return this->add;
}

int Sales::GetSum()
{
    cout << GetSalary() * GetTime() + GetAdd() << endl;
}
*/
