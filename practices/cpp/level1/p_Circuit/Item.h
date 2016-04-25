#ifndef ITEM_H
#define ITEM_H
class Item
{
public:
  //actionClass 1 - turn on and 0 - turn off
  virtual bool operate(bool actionClass) = 0;
  virtual bool getStatus() = 0;
  virtual void printStatus() = 0;
  virtual Item *toBind() = 0;
};
#endif
