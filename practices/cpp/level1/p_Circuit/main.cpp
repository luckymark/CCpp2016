#include "Door.h"
#include "Bulb.h"
#include "Button.h"

int main()
{
  Button button;
  Door door;
  Bulb bulb;

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
