#include "stdafx.h"
#include "Bullet.h"
#include "Texture.h"//��Ҫ���ʵ�Ҫ�õ�texture��

Bullet::Bullet(float x, float y, int kind)
{
	this->setPosition(x, y);
	this->kind = kind;
	A.load(7);
	switch (kind)
	{
	case 1://�Ի�
	{
		A.load(7);
		this->setTexture(A.BULLET);//��bullet����ô����
		break;
	}
	case 2: {//��ͨ�����ӵ�
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 3: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 4: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 5: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 6: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 7: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 8: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 9: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 10: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 11: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 12: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 13: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 14: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 15: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 16: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 17: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 18: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 19: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 20: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 21: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 22: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 23: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 24: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 25: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 26: {
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 27://light
	{
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 28://light
	{
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	case 29://light
	{
		A.load(12);
		this->setTexture(A.ENEMYBULLET);
		break;
	}
	}
}
void Bullet::heartBeat() {
	switch (kind)
	{
	case 1://�Լ����ӵ�Ϊ1�������Ĳ�ͬ���������ø����ӵ�����
	{
		this->move(0, -50);
		break;
	}
	case 2:
	{
		this->move(0, 10);//
		//this->move((savex - x) / 10, (savey - y) / 10);
		break;
	}
	case 3://����б��
	{
		this->move(5, 5);
		break;
	}
	case 4://����б��
	{
		this->move(-5, 5);
		break;
	}
	case 5://�������Ƶ�����
	{
		this->move(2, 5);
		break;
	}
	case 6://�������Ƶ�����
	{
		this->move(-2, 5);
		break;
	}
	case 7://������б��(�޷�ʵ��)
	{
		if (!whetherIsetdirection) {
			savex = rand() % 100;
			savey = rand() % 100;
			this->whetherIsetdirection = 1;
		}
		this->move(savex, savey);
	}
	case 8: {//0
		this->move(10, 0);
		break;
	}
	case 9: {//30
		this->move(8.7, -5.1);
		break;
	}
	case 10: {//60
		this->move(5.1, -8.7);
		break;
	}
	case 11: {
		this->move(0, -10);
		break;
	}
	case 12: {//120
		this->move(-5.1, -8.7);
		break;
	}
	case 13: {//150
		this->move(-8.7, -5.1);
		break;
	}
	case 14: {//180
		this->move(-10, 0);
		break;
	}
	case 15: {
		this->move(-8.7, 5.1);
		break;
	}
	case 16: {
		this->move(-5.1, 8.7);
		break;
	}
	case 17: {
		this->move(0, 10);
		break;
	}
	case 18: {
		this->move(5.1, 8.7);
		break;
	}
	case 19: {
		this->move(8.7, 5.1);
		break;
	}
	case 20://�ڶ���
	{
		this->move(2.000, 8.000);
		break;
	}
	case 21:
	{
		this->move(0.000, 8.000);
		break;
	}
	case 22:
	{
		this->move(-2.000, 8.000);
		break;
	}
	case 23:
	{
		this->move(1.600, 6.000);
		break;
	}
	case 24:
	{
		this->move(-1.600, 6.000);
		break;
	}
	case 25:
	{
		this->move(0.000, 4.000);
		break;
	}
	case 26:
	{
		this->move(-1.000, 4.000);
		break;
	}
	case 27:
	{
		float a = rand() % 4;//���ڿ��ƹ켣
		this->move(a, 8);
		break;
	}
	case 28:
	{
		float a = -rand() % 4;//���ڿ��ƹ켣
		this->move(a, 8);
		break;
	}
	case 29:
	{
		static int a;
		static int b;
		static int condition = 0;
		switch (condition)
		{
		case 0:
			a = -(rand() % 10);
			b = rand() % 10;
			this->move(a, b);
			condition++;
			break;
		case 1:
			if (this->getPosition().x < 11)
			{
				a = -a;
				this->move(a, b);
				condition++;
				break;
			}
			else
				this->move(a, b);
			break;
		case 2:
			if (this->getPosition().y > 763)
			{
				b = -b;
				this->move(a, b);
				break;
			}
			else
				this->move(a, b);
			break;
		}
	}
	}
}


