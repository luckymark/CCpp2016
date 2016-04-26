// #include "Circuit.h"

#include "Door.h"
#include "Bulb.h"
#include "Button.h"

int main()
{
  Button button;
  // Fan fan;
  Door door;
  Bulb bulb;

  // button.bind(fan);
  // button.on();
  // button.off();

  button.bind(door.toBind());
  button.on();
  button.bind(bulb.toBind());
#ifdef DEBUG
  button.notify();
#endif
  button.on();
#ifdef DEBUG
  button.notify();
#endif
  button.off();
#ifdef DEBUG
  button.notify();
#endif
  return 0;
}
