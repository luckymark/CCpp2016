#ifndef FAN_H
#define FAN_H
#include"Electric.h"
#include<iostream>

class Fan :public Electric
{
    public:
        Fan();
        virtual ~Fan();
        void display(int num)
        {
            if(num==1)
                std::cout<<"The Fan is Opened!"<<std::endl;
            else
                std::cout<<"The Fan is Closed!"<<std::endl;
        }
    protected:
    private:
};
#endif // FAN_H
