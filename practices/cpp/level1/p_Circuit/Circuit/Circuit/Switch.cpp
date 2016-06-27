#include "Switch.h"



Switch::Switch()
{
}


Switch::~Switch()
{
}

Switch::Switch(Equipment * _equ)
{
	aEquipment = _equ;
}

void Switch::bindEquipment(Equipment * _equ)
{
	aEquipment = _equ;
}

void Switch::on()
{
	aEqueipment->on();
}

void Switch::off()
{
	aEquipment->off();
}
