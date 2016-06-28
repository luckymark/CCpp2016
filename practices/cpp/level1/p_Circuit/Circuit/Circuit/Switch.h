#pragma once
#include "Equipment.h"
class Switch :
	public Equipment
{
public:
	Switch(Equipment* _equ);
	void bindEquipment(Equipment* _equ);
	void on();
	void off();
private:
	Equipment* aEquipment;
};

