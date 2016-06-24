#include "stdafx.h"
#include "ToolPoint.h"
void ToolPoint::heartBeat()
{
	this->move(0, 5);
}

ToolPoint::ToolPoint(float x,float y)
{
	A.load(9);
	this->setTexture(A.DONGPOINT);
	this->setPosition(x, y);
}
