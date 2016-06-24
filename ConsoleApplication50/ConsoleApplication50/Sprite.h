#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Sprite:public sf::Sprite//改造以后的sprite
{
public:
	virtual void heartBeat() {};//这个函数有什么用？
	void draw();	
	bool intersects(Sprite* other);
};

