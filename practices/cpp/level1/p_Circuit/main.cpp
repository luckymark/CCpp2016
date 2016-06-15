#include <iostream>
#include"Button.h"
#include"Circuit.h"
#include"Lamp.h"
#include"Fan.h"
#include"Electric.h"
using namespace std;

int main()
{
    Circuit circuit;

    Lamp lamp;
    Fan fan;
    Button button;

    circuit.setSwitch(&button);
    circuit.append(&lamp);
    circuit.append(&fan);

    button.on();
    button.off();

    return 0;
}
