#include "Bulb.h"
#include <iostream>

bool Bulb::operate(bool actionClass)
{
  if(actionClass == status)
  {
    return ALREADY_IN_THIS_STATUS;
  }
  else
  {
    status = actionClass;
    return 0;
  }
}
bool Bulb::getStatus()
{
  return status;
}
void Bulb::printStatus()
{
  if(status == ON)
  {
    std::cout << "The bulb is on" << std::endl;
  }
  else
  {
    std::cout << "The bulb is off" << std::endl;
  }
}
Item *Bulb::toBind()
{
  return this;
}
