#pragma once
#include "Sprite.h"
#include"Texture.h"
#include"GetHeroPosition.h"
#include"Hero.h"//1111111111111111111111111111111111111111
class Bullet:public Sprite//需要用到getposition都要继承改造的sprite类
{
public:
	Bullet(float x, float ,int kind);//Bullet和kind是chx教我的
	void heartBeat();//这函数是什么用的(子弹轨迹）
private:
	Texture A;
	int kind;
	float x;
	float y;
	float savex;//自机狙的更好解决方案？
	float savey;
	int whetherIsetdirection=0;
};

