#ifndef BUTTON_H
#define BUTTON_H
#include<SwitchAble.h>
#include<iostream>
using namespace std;
class Button
{
    public:
        Button();
        virtual ~Button();
        void bind(SwitchAble &target){
            this->target = &target;
        }
        void on(){
            target->on();
        }
        void off(){
            target->off();
        }
        SwitchAble *target;
    protected:
    private:

};

#endif // BUTTON_H
