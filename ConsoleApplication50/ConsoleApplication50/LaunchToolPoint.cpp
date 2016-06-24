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
void LaunchToolPoint::setOwner(Plane* owner) {//��һ�ν�owner�����other������û�и����е�owner��ֵ
	this->owner = owner;//���飺����λ�ó�ͻ  ���� ���԰�Plane* owner���Plane* other,�������
}
sf::Vector2f LaunchToolPoint::getPosition() {
	sf::Vector2f ff;
	return ff;
}





