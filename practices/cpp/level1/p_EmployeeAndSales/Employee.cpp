#include "Employee.h"
Employee::Employee(string name,int age,int level)
{
    SetName(name);
    SetAge(age);
    SetLevel(level);

}
void Employee::SetName(string name)
{
    this->name=name;
}
void Employee::SetAge(int age)
{
    this->age=age;
}
void Employee::SetLevel(int level)
{
    this->level=level;
}
string Employee::GetName()
{
    return this->name;
}
int Employee::GetAge()
{
    return this->age;
}
int Employee::GetLevel()
{
    return this->level;
}

void Employee::GetSalary()
{
    cout<<GetLevel()*1000<<endl;
}



/*Employee::Employee(int money, string name, int level)
{
    SetName(name);
    SetSalary(money);
    SetTime(time);
}

void Employee::SetSalary(int money)
{
    this->salary = money;
}

void Employee::SetTime(int time)
{
    this->time = time;
}

void Employee::SetName(string name)
{
    this->name = name;
}

int Employee::GetSalary()
{
    return this->salary;
}

int Employee::GetTime()
{
    return this->time;
}

string Employee::GetName()
{
    return this->name;
}

int Employee::GetSum()
{
    cout << GetTime() * GetSalary() << endl;
}*/
