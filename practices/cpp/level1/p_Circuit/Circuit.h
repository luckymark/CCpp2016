#ifndef CIRCUIT_H
#define CIRCUIT_H
#include"Electric.h"
#include"Button.h"
class Button;
class Circuit
{
    public:
        Circuit();
        virtual ~Circuit();
        void setSwitch(Button* button);
        void append(Electric* electric);
        void display(int num);
    protected:
    private:
        Electric* elect[30];
        int eUsage,bUsage;
        Button* butt[30];
};

#endif // CIRCUIT_H
