#ifndef SALES_H
#define SALES_H
#include "Employee.h"
#include <iostream>
using namespace std;

class Sales:public Employee
{
    public:
        Sales(string name,int age,int level,int SalesNum);
        void SetSalesNum(int SalesNum);
        int GetSalesNum();
        void GetSum();
    protected:

    private:
        string name;
        int age;
        int level;
        int SalesNum;
        int salary;
        /*public:
                    Sales(int money, string name, int time, int add);
        void        SetAdd(int money);
        int         GetAdd();
        int         GetSum();
        private:
        string  name;
        int     time;
        int     salary;
        int     add;*/

};

#endif // SALES_H
