#pragma once
#include "Boss.h"
#include"Texture.h"
#include"Gun.h"
#include"Plane.h"
class Boss:public Plane
{
public:
	Boss();
	int boosliferemain;//boss剩余生命
	int whetherConversationEnd = 0;
	int whetherCOnversationEnd2 = 0;
	int state= 0;
	void heartBeat();
	bool needclear();
	void hit();
	sf::Time t5 = sf::seconds(5);
	sf::Time t1 = sf::seconds(1);
	sf::Time t10 = sf::seconds(10);
	sf::Time t20 = sf::seconds(20);
	sf::Clock clock1;
	sf::Clock clock2;//用于1s发射一颗子弹
	/*
	标准boss模板
	生命值
	设置材质
	初始位置
	子弹设置
	道具设置
	开火?
	*/
private:
	Texture A;
};
/*
  	int state = 0;
	Enemy(int enemytype);
	void heartBeat();
	void hit();
	bool needClear();
	bool isDead();//我也不知道要不要
	~Enemy() {};
	int enemyliferemain;
private:
	int enemytype;
	Texture A;*/

