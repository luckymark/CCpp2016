#include "stdafx.h"
#include "LaunchToolPoint.h"
#include"Plane.h"
#include"ToolPoint.h"
#include"Sky.h"
void LaunchToolPoint::launch() {
	sf::Vector2f pos((this->owner)->getPosition());//
	ToolPoint* toolpoint = new ToolPoint(pos.x, pos.y);
	Sky::getInstance()->add(toolpoint);
	Sky::getInstance()->addToolPoint(toolpoint);
}
void LaunchToolPoint::setOwner(Plane* owner) {//第一次将owner打成了other，导致没有给类中的owner赋值
	this->owner = owner;//经验：访问位置冲突  经验 尝试把Plane* owner打成Plane* other,看看结果
}
sf::Vector2f LaunchToolPoint::getPosition() {
	sf::Vector2f ff;
	return ff;
}





