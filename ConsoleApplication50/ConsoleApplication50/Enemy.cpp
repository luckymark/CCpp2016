#include "stdafx.h"
#include "Enemy.h"
#include "Texture.h"
//#include "Sound.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int enemytype) {
	this->enemytype = enemytype;
	float a = rand();//��ɾ��
	/*
	��׼����ģ��
	����ֵ
	���ò���
	��ʼλ��
	�ӵ�����
	��������
	����
	*/
	switch (enemytype)
	{
	case 1://��ͨ�ĵ���
	{
		float a = rand() % 500;
		float b = rand() % 100;
		A.load(2);
		this->enemyliferemain = 10;//����ֵ�����޸�
		this->setTexture(A.ENEMY1);
		this->setPosition(a, b);//�����������
		this->gun.setOwner(this, 2);
		this->launchtoolpoint.setOwner(this);
		this->fire();
		break;
	}
	case 2://����3���ӵ��ĵ���
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
	case 3: {//������ʬ���ĵ���
		float a = rand() % 1024;
		A.load(11);
		this->enemyliferemain = 1;
		this->setTexture(A.ENEMY2);
		this->setPosition(a, 50);//������
		this->gun.setOwner(this, 3);
		this->launchtoolpoint.setOwner(this);
		break;
	}
	case 4: {//б������͵���//�Ի��ѣ�
		break;
	}
	/*case 5: {//�ص�С�֣�
		this->enemyliferemain = 500;//���ֵ������
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
	{//���Ƶ��˶���
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
			;//�����䡾������������������
		}
		break;
		}
		break;//������switch��Ҫ����break
	}
	case 1://����
			this->setTexture(A.ENEMY_DOWN_1);//����Ч1...
			this->state++;
			break;
	case 2:
		this->setTexture(A.ENEMY_DOWN_2);
		this->state++;
		if(this->enemytype==1)
			this->launch();
		if (this->enemytype == 2)
			this->launch();//��ʬ��
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
		//this->setTexture(A.ENEMY1);//������Ч1
		//Sound::ENEMY_DOWN.play();
		this->state++;
}

bool Enemy::needClear() {
	return (this->getPosition().x<0||this->getPosition().x>1024||this->getPosition().y<0||this->getPosition().y>768||this->state==3);
}

bool Enemy::isDead() {
	return this->state !=0;//��isdead��ô��[][][][][][][][][][][][][][]
}
