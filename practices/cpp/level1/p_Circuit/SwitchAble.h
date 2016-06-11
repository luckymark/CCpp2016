#ifndef SWITCHABLE_H
#define SWITCHABLE_H
#include<iostream>
using namespace std;

class SwitchAble
{
    public:
        SwitchAble();
        virtual ~SwitchAble();
        virtual void on(){}
        virtual void off(){}
    protected:
    private:
};

#endif // SWITCHABLE_H
