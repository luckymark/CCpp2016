#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Plane;
class Gun
{
public:
	void setOwner(Plane* owner,int kind);
	void fire();
//	Gun(int i) {
	//	this->kind = i;
//	};
private:
	sf::Vector2f getPosition();//��ʲô��������
	Plane* owner;
	int kind;
};

