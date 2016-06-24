#include "stdafx.h"
#include "Plane.h"
void Plane::fire() {
	this->gun.fire();
}
void Plane::launch() {
	this->launchtoolpoint.launch();
}

