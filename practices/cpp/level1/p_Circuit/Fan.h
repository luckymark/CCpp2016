#ifndef FAN_H
#define FAN_H

#include <SwitchAble.h>
#include<iostream>
using namespace std;

class Fan : public SwitchAble
{
    public:
        Fan();
        virtual ~Fan();
        virtual void on(){
            cout<<"开风扇"<<endl;
        }
        virtual void off(){
            cout<<"关风扇"<<endl;
        }
    protected:
    private:
};

#endif // FAN_H
