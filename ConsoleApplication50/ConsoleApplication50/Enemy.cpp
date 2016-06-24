#include "stdafx.h"
#include "Enemy.h"
#include "Texture.h"
//#include "Sound.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int enemytype) {
	this->enemytype = enemytype;
	float a = rand();//待删除
	/*
	标准敌人模板
	生命值
	设置材质
	初始位置
	子弹设置
	道具设置
	开火
	*/
	switch (enemytype)
	{
	case 1://普通的敌人
	{
		float a = rand() % 500;
		float b = rand() % 100;
		A.load(2);
		this->enemyliferemain = 10;//生命值，待修改
		this->setTexture(A.ENEMY1);
		this->setPosition(a, b);//待补充随机数
		this->gun.setOwner(this, 2);
		this->launchtoolpoint.setOwner(this);
		this->fire();
		break;
	}
	case 2://发射3颗子弹的敌人
	{
		float a = rand() % 100;
		A.load(11);
		this->enemyliferemain = 10;
		this->setTexture(A.ENEMY2);
		this->setPosition(a, 100);
		this->gun.setOwner(this, 2);
		this->launchtoolpoint.setOwner(this);
		this->fire();
		break;
	}
	case 3: {//发射死尸弹的敌人
		float a = rand() % 1024;
		A.load(11);
		this->enemyliferemain = 1;
		this->setTexture(A.ENEMY2);
		this->setPosition(a, 50);//待调整
		this->gun.setOwner(this, 3);
		this->launchtoolpoint.setOwner(this);
		break;
	}
	case 4: {//斜角射击型敌人//自机狙？
		break;
	}
	/*case 5: {//关底小怪？
		this->enemyliferemain = 500;//这个值待调整
		this->setTexture(A.ENEMY2);
		this->setPosition(487, 50);
		this->gun.setOwner(this, 4);
		this->launchtoolpoint.setOwner(this);
		break;
	}*/

	break;
	}
}
void Enemy::heartBeat() {
	A.load(3);
	A.load(4);
	A.load(5);
	switch (this->state) 
	{//控制敌人动作
	case 0:
	{
		switch (enemytype)
		{
		case 1:
		{
			this->move(5, 0);
			break;
		}
		case 2:
		{
			static int count = 0;
			this->move(10, 0);
			if (count++ > 60)
			{
				this->fire();
				count =0;
			}
			break;
		}
		case 3:
		{
			this->move(0, 3);
			break;
		}
		case 5:
		{
			;//待补充【】【】【】【】【】
		}
		break;
		}
		break;//有两个switch就要两个break
	}
	case 1://死亡
			this->setTexture(A.ENEMY_DOWN_1);//播特效1...
			this->state++;
			break;
	case 2:
		this->setTexture(A.ENEMY_DOWN_2);
		this->state++;
		if(this->enemytype==1)
			this->launch();
		if (this->enemytype == 2)
			this->launch();//死尸弹
		if (this->enemytype == 3)
			this->gun.fire();
		break;
/*	case 3:
		this->setTexture(A.ENEMY_DOWN_3);
		this->state++;
		this->launch();
		break;
	default:
		break;*/
	}
}

void Enemy::hit() {
	this->enemyliferemain--;
	if ((this->enemyliferemain) <= 0)
		//this->setTexture(A.ENEMY1);//死亡特效1
		//Sound::ENEMY_DOWN.play();
		this->state++;
}

bool Enemy::needClear() {
	return (this->getPosition().x<0||this->getPosition().x>1024||this->getPosition().y<0||this->getPosition().y>768||this->state==3);
}

bool Enemy::isDead() {
	return this->state !=0;//这isdead怎么办[][][][][][][][][][][][][][]
}
