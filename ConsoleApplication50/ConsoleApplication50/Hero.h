#pragma once	//防止重定义		
#include<iostream>
#include"Plane.h"
#include"Sprite.h"//是否必要？
#include"Texture.h"
class Hero:public Plane
{
public:
	Hero();
	~Hero();
	void move2left();
	void move2leftslow();
	void move2rightslow();
	void move2right();
	void move2up();
	void move2upslow();
	void move2down();
	void move2downslow();
	void bomblost();
	void dongTurnToPower();
	bool havebomb();
	sf::Clock clockWD;
	sf::Time t5 = sf::seconds(5);
	int life;
	int HeroDong;
	int HeroPower;
	int whetherWD = 0;//是否无敌
	int HeroBomb;//这些别的函数要访问的量要作为private类
private:
	Texture a;

};

