#pragma once
#include "Sprite.h"
#include"Texture.h"
#include"GetHeroPosition.h"
#include"Hero.h"//1111111111111111111111111111111111111111
class Bullet:public Sprite//��Ҫ�õ�getposition��Ҫ�̳и����sprite��
{
public:
	Bullet(float x, float ,int kind);//Bullet��kind��chx���ҵ�
	void heartBeat();//�⺯����ʲô�õ�(�ӵ��켣��
private:
	Texture A;
	int kind;
	float x;
	float y;
	float savex;//�Ի��ѵĸ��ý��������
	float savey;
	int whetherIsetdirection=0;
};

