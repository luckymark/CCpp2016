#include <iostream>
#include<Button.h>
#include<Light.h>
#include<SwitchAble.h>
#include<Fan.h>
using namespace std;

int main()
{
    SwitchAble *s;
    Button button;
    Fan fan;
    Light light;
    button.bind(fan);
    button.on();
    button.off();
    button.bind(light);
    button.on();
    button.off();
    return 0;
}
