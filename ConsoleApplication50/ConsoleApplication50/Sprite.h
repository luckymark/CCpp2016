#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Sprite:public sf::Sprite//�����Ժ��sprite
{
public:
	virtual void heartBeat() {};//���������ʲô�ã�
	void draw();	
	bool intersects(Sprite* other);
};

