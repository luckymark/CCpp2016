#ifndef BUTTON_H
#define BUTTON_H

#include "Item.h"
#include "Config.h"
#include <vector>

class Button
{
private:
  std::vector<Item*> childItem;
public:
#ifdef DEBUG
  bool notify();
#endif
  void bind(Item *);
  void on();
  void off();
};
#endif
