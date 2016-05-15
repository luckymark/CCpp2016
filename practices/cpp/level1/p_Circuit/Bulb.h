#ifndef BULB_H
#define BULB_H
#include "Item.h"
#include "Config.h"

class Bulb : public Item
{
private:
  bool status = OFF;
public:
  bool operate(bool actionClass) override;
  bool getStatus() override;
  void printStatus() override;
  Item *toBind() override;
};
#endif
