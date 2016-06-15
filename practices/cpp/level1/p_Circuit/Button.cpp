#include "Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}
void Button::on()
{
   xCircuit->display(1);
}
void Button::off()
{
   xCircuit->display(0);
}
