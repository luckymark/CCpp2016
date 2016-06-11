#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

class Employee
{
    public:
        Employee();
        virtual ~Employee();
        virtual int money();
        void setImformation(std::string name,int age,int level);
    protected:
        std::string name;
        int age;
        int level;
    private:
};

#endif // EMPLOYEE_H
