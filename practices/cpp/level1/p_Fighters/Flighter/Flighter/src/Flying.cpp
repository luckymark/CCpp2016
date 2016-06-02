#include "Flying.hpp"

Flying::Flying(float x, float y,float speedx,float speedy,float originx,float originy,float radius)
{
	Flying::x = x;
	Flying::y = y;
	Flying::speedx = speedx;
	Flying::speedy = speedy;
	Flying::setOrigin(originx, originy); 
	Flying::radius = radius;
	accelerationx = 0;
	accelerationy = 0;
	setPosition(x, y);
	ifboom = 0;
}

Flying::~Flying()
{
	
}

void Flying::setSpeed(float inputx, float inputy)
{
	speedx = inputx;
	speedy = inputy;
	speed = sqrt(inputx*inputx + inputy*inputy);
}

void Flying::setAcceleration(float inputx, float inputy)
{
	accelerationx = inputx;
	accelerationy = inputy;
	acceleration = sqrt(inputx*inputx + inputy*inputy);
}

float Flying::getSpeedx()
{
	return speedx;
}

float Flying::getSpeedy()
{
	return speedy;
}

float Flying::getSpeed()
{
	atan(speedx / speedy);
	return speed;
}

float Flying::getAcceleration()
{
	atan(accelerationx / accelerationy);
	return acceleration;
}

void Flying::resetPosition(float x,float y)
{
	Flying::x = x;
	Flying::y = y;
}

void Flying::setY(float y)
{
	Flying::y = y;
}

void Flying::setX(float x)
{
	Flying::x = x;
}

float Flying::getY()
{
	return y;
}

float Flying::getX()
{
	return x;
}

void Flying::move()
{
	x += speedx;
	y += speedy;
	this->setPosition(sf::Vector2f(x, y));
	speedx += accelerationx;
	speedy += accelerationy;
}

float Flying::getRadius()
{
	return radius;
}

sf::Time Flying::getCountdown()
{
	return boomcountdown;
}

void Flying::setCountdown(sf::Time time)
{
	boomcountdown = time;
}

bool Flying::getIfboom()
{
	return ifboom;
}

void Flying::setIfboom(bool ifboom)
{
	Flying::ifboom = ifboom;
}
