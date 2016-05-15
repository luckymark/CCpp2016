#include "Door.h"
#include <iostream>

bool Door::operate(bool actionClass)
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
bool Door::getStatus()
{
  return status;
}
void Door::printStatus()
{
  if(status == OFF)
  {
    std::cout << "The door is off" << std::endl;
  }
  else
  {
    std::cout << "The door is on" << std::endl;
  }
}
Item *Door::toBind()
{
  return this;
}
