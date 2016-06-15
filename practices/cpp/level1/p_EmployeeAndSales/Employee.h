#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<string>
using namespace std;

class Employee
{
    public:
        Employee(string name,int age,int level);
        void SetName(string name);
        void SetAge(int age);

        void SetLevel(int level);

        string GetName();
        int GetAge();

        int GetLevel();
        void GetSalary();

    protected:

    private:
        string name;
        int age;
        int level;

        int salary;
        /*public:
                    Employee(int age, string name, int time);
        void        SetName(string name);
        void        SetAge(int age);
        void        SetTime(int time);
        int         GetSalary();
        int         GetTime();
        string      GetName();
        int         GetSum();
        private:
        string  name;
        int age;
        int     time;
        int     salary;*/
};

#endif // EMPLOYEE_H
