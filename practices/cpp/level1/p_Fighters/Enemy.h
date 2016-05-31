#pragma once
#include"Plane.h"
#include<random>
#include<cmath>
#include<SFML\Graphics.hpp>
class Enemy :public Plane
{
public:
	Enemy():Plane(0,0) {}
	Enemy(int x, int y);
	Enemy(const Enemy &enemy);
	int getposition();
	void move();
	void iniEnemy();
	int isBoom();
	void randomMove();
};