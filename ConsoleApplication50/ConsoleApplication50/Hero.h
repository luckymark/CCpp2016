#pragma once	//��ֹ�ض���		
#include<iostream>
#include"Plane.h"
#include"Sprite.h"//�Ƿ��Ҫ��
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
	int whetherWD = 0;//�Ƿ��޵�
	int HeroBomb;//��Щ��ĺ���Ҫ���ʵ���Ҫ��Ϊprivate��
private:
	Texture a;

};

