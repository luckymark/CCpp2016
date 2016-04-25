// #include "Circuit.h"

#include "Door.h"
#include "Button.h"
int main()
{
  Button button;
  // Fan fan;
  Door door;

  // button.bind(fan);
  // button.on();
  // button.off();

  button.bind(door.toBind());
  button.on();
  button.notify();
  button.off();
  button.notify();
  return 0;
}
