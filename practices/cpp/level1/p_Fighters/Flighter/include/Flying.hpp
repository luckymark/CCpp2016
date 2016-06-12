#pragma once

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include<string>
#include<iostream>
#include<math.h>

class Flying:public sf::Sprite
{
public:
	Flying(float x, float y,float speedx,float speedy,float ox,float oy,float radius);
	~Flying();
	void setSpeed(float inputx = 0.f, float inputy = 0.f);
	void setAcceleration(float inputx = 0.f, float inputy = 0.f);
	float getSpeedx();
	float getSpeedy();
	float getSpeed();
	float getAcceleration();
	void resetPosition(float x,float y);
	void setY(float y);
	void setX(float x);
	float getY();
	float getX();
	void move();
	float getRadius();
	
private:
	float x;
	float y;
	float speedx;
	float speedy;
	float speed;
	float accelerationx;
	float accelerationy;
	float acceleration;
	float radius;

};