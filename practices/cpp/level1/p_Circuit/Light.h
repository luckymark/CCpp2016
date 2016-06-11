#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>
#include <SwitchAble.h>

using namespace std;
class Light : public SwitchAble
{
    public:
        Light();
        virtual ~Light();
        virtual void on(){
            cout<<"¿ªµÆ"<<endl;
        }
        virtual void off(){
            cout<<"¹ØµÆ"<<endl;
        }
    protected:
    private:
};

#endif // LIGHT_H
