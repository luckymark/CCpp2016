#ifndef SALEPEOPLE_H
#define SALEPEOPLE_H
#include<Employee.h>

class SalePeople:public Employee
{
    public:
        SalePeople();
        virtual ~SalePeople();
        virtual int money();
        void setSale(int sale);
    protected:
    private:
        int sale = 2000;
};

#endif // SALEPEOPLE_H
