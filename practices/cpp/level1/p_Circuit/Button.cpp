#include "Button.h"
#ifdef DEBUG
bool Button::notify()
{
  for(auto it = childItem.begin(); it != childItem.end(); it++)
  {
    (*it)->printStatus();
  }
}
#endif
void Button::bind(Item * target)
{
  //set all item off
  off();

  childItem.push_back(target);
}
void Button::on()
{
  for(auto it = childItem.begin(); it != childItem.end(); it++)
  {
    (*it)->operate(TURN_ON);
  }
}
void Button::off()
{
  for(auto it = childItem.begin(); it != childItem.end(); it++)
  {
    (*it)->operate(TURN_OFF);
  }
}
