#include <iostream>

#include "base.h"
#include "door.h"
#include "fan.h"
#include "button.h"

int main() {
    Button button;
    Fan fan;
    Door door;

    button.bind(&fan);
    button.on();
    button.off();

    button.bind(&door);
    button.on();
    button.off();
    return 0;
}