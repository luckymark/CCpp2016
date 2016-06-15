#ifndef BUTTON_H
#define BUTTON_H
#include"Circuit.h"
class Circuit;

class Button
{
    public:
        Button();
        virtual ~Button();
        void on();
        void off();
        void setCircuit(Circuit* x)
        {
            xCircuit=x;
        }
    protected:
    private:
        Circuit* xCircuit;
};
#endif // BUTTON_H
