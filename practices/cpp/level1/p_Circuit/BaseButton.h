#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include "Item.h"

class BaseButton
{
public:
  virtual bool notify() = 0;
  virtual void bind(Item*) = 0;
  virtual void on() = 0;
  virtual void off() = 0;
};
#endif
