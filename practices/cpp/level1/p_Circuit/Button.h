#ifndef BUTTON_H
#define BUTTON_H

#include "BaseButton.h"
#include "Item.h"
#include "Config.h"
#include <vector>

class Button : public BaseButton
{
private:
  std::vector<Item*> childItem;
public:
#ifdef DEBUG
  bool notify() override;
#endif
  void bind(Item *) override;
  void on() override;
  void off() override;
};
#endif
