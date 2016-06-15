#include "Circuit.h"
Circuit::Circuit()
{
    eUsage=0;
    bUsage=0;
}

Circuit::~Circuit()
{
    //dtor
}

void Circuit::setSwitch(Button* button)
{
    butt[bUsage]=button;
    butt[bUsage]->setCircuit(this);
    bUsage++;
}
void Circuit::append(Electric* electric)
{
   elect[eUsage]=electric;
   eUsage++;
}

void Circuit::display(int num)
{
    for(int i=0;i<eUsage;i++)
    {
        elect[i]->display(num);
    }
}
