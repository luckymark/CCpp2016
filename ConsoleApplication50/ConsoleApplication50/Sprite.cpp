#include "stdafx.h"
#include "Sprite.h"
#include "Sky.h"
#include "Enemy.h"
void Sprite::draw(){
	Sky::getInstance()->getWindow()->draw(*this);
}
bool Sprite::intersects(Sprite* other) {
	bool t = this->getGlobalBounds().intersects(other->getGlobalBounds());//��ʲô��˼
	return t;//getGlobalBounds ��ʲô
}
