#include "stdafx.h"
#include "Gun.h"
#include"Plane.h"
#include"Bullet.h"
#include"Sky.h"
void Gun::fire() {
		sf::Vector2f pos((this->owner)->getPosition());
		switch (kind)
		{
		case 1:
		{
			Bullet* bullet = new Bullet(pos.x, pos.y, 1);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet);
			Sky::getInstance()->addMyBullet(bullet);
			break;
		}
		case 2://�����ӵ�
		{
			Bullet* bullet = new Bullet(pos.x+30, pos.y+30, 4);//1���Լ����ӵ���2�ǵ��˵��ӵ������޸�
			Sky::getInstance()->add(bullet);
			Sky::getInstance()->addEnemyBullet(bullet);
			Bullet* bullet2 = new Bullet(pos.x - 30, pos.y-30, 2 );//1���Լ����ӵ���2�ǵ��˵��ӵ������޸�
			Sky::getInstance()->add(bullet2);
			Sky::getInstance()->addEnemyBullet(bullet2);
			Bullet* bullet3 = new Bullet(pos.x , pos.y, 3);//1���Լ����ӵ���2�ǵ��˵��ӵ������޸�
			Sky::getInstance()->add(bullet3);
			Sky::getInstance()->addEnemyBullet(bullet3);

			break;
		}
		case 3://��ʬ��
		{
			Bullet* bullet1 = new Bullet(pos.x + 100, pos.y, 6);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet1);
			Sky::getInstance()->addEnemyBullet(bullet1);
			Bullet* bullet2 = new Bullet(pos.x + 200, pos.y - 100, 6);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet2);
			Sky::getInstance()->addEnemyBullet(bullet2);
			Bullet* bullet3 = new Bullet(pos.x, pos.y, 2);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet3);
			Sky::getInstance()->addEnemyBullet(bullet3);
			Bullet* bullet4 = new Bullet(pos.x - 100, pos.y, 5);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet4);
			Sky::getInstance()->addEnemyBullet(bullet4);
			Bullet* bullet5 = new Bullet(pos.x + 200, pos.y - 100, 5);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet5);
			Sky::getInstance()->addEnemyBullet(bullet5);
			break;
		}
		case 4: {//Բ���ӵ� �����о�
			Bullet* bullet1 = new Bullet(pos.x + 100, pos.y, 6);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			//bullet1->getpos(&hero);
			Sky::getInstance()->add(bullet1);
			Sky::getInstance()->addEnemyBullet(bullet1);
			break;
		}
		case 5: {//bossԲ���ӵ� boss��һ�׶εĵ�һ�ֹ��� �ٶ������
			Bullet* bullet1 = new Bullet(pos.x +10, pos.y, 8);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet1);
			Sky::getInstance()->addEnemyBullet(bullet1);
			Bullet* bullet2 = new Bullet(pos.x + 8.7, pos.y - 5.1, 9);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet2);
			Sky::getInstance()->addEnemyBullet(bullet2);
			Bullet* bullet3 = new Bullet(pos.x+5.1, pos.y-8.7, 10);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet3);
			Sky::getInstance()->addEnemyBullet(bullet3);
			Bullet* bullet4 = new Bullet(pos.x ,pos.y-10, 11);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet4);
			Sky::getInstance()->addEnemyBullet(bullet4);
			Bullet* bullet5 = new Bullet(pos.x -5.1, pos.y - 8.7, 12);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet5);
			Sky::getInstance()->addEnemyBullet(bullet5);
			Bullet* bullet6 = new Bullet(pos.x -8.7, pos.y-5.1, 13);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet6);
			Sky::getInstance()->addEnemyBullet(bullet6);
			Bullet* bullet7 = new Bullet(pos.x -10, pos.y , 14);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet7);
			Sky::getInstance()->addEnemyBullet(bullet7);
			Bullet* bullet8 = new Bullet(pos.x-8.7, pos.y+5.1, 15);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet8);
			Sky::getInstance()->addEnemyBullet(bullet8);
			Bullet* bullet9 = new Bullet(pos.x-5.1, pos.y+8.7, 16);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet9);
			Sky::getInstance()->addEnemyBullet(bullet9);
			Bullet* bullet10 = new Bullet(pos.x, pos.y + 10, 17);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet10);
			Sky::getInstance()->addEnemyBullet(bullet10);
			Bullet* bullet11 = new Bullet(pos.x + 5.1, pos.y +8.7, 18);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet11);
			Sky::getInstance()->addEnemyBullet(bullet5);
			Bullet* bullet12 = new Bullet(pos.x +8.7, pos.y +5.1, 19);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
			Sky::getInstance()->add(bullet12);
			Sky::getInstance()->addEnemyBullet(bullet12);

			break;
		}
		case 6: 
		{
			Bullet* bullet1 = new Bullet(pos.x+5.000000, pos.y+20.000000, 20);
			Sky::getInstance()->add(bullet1);
			Sky::getInstance()->addEnemyBullet(bullet1);
			Bullet* bullet2 = new Bullet(pos.x+0.000000, pos.y+20.000000, 21);
			Sky::getInstance()->add(bullet2);
			Sky::getInstance()->addEnemyBullet(bullet2);
			Bullet* bullet3 = new Bullet(pos.x-5.000000, pos.y+20.000000, 22);
			Sky::getInstance()->add(bullet3);
			Sky::getInstance()->addEnemyBullet(bullet3);
			Bullet* bullet4 = new Bullet(pos.x+4.000000, pos.y+15.000000, 23);
			Sky::getInstance()->add(bullet4);
			Sky::getInstance()->addEnemyBullet(bullet4);
			Bullet* bullet5 = new Bullet(pos.x-4.000000, pos.y+15.000000, 24);
			Sky::getInstance()->add(bullet5);
			Sky::getInstance()->addEnemyBullet(bullet5);
			Bullet* bullet6 = new Bullet(pos.x+0.000000, pos.y+10.000000, 25);
			Sky::getInstance()->add(bullet6);
			Sky::getInstance()->addEnemyBullet(bullet6);
			Bullet* bullet7 = new Bullet(pos.x-2.500000, pos.y+10.000000, 26);
			Sky::getInstance()->add(bullet7);
			Sky::getInstance()->addEnemyBullet(bullet7);
			break;
		}
		case 7://boss�����
		{
			for (int i = 0; i < 30; i++)
			{
				int a = rand() % 1024;
				int b = rand() % 300;
				int c = 27 + a % 2;
				Bullet* bullet1 = new Bullet(a, b, c);
				Sky::getInstance()->add(bullet1);
				Sky::getInstance()->addEnemyBullet(bullet1);
			}
			break;
		}
		case 8://һ�׷�����
		{
			for (int i = 0; i < 20;i++)
			{
				int a1 = 200+rand() % 500;
				int b2 = rand() % 500;
				Bullet* bullet1 = new Bullet(a1, b2, 29);
				Sky::getInstance()->add(bullet1);
				Sky::getInstance()->addEnemyBullet(bullet1);
			}
			break;
		}
		}
	/*}
	else {
		sf::Vector2f pos((this->owner)->getPosition());
		Bullet* bullet = new Bullet(pos.x + 15, pos.y + 15);//+15��Ϊ�˺�ģ��Э�������޸ģ�����
		Sky::getInstance()->add(bullet);
		Sky::getInstance()->addEnemyBullet(bullet);
	}*/
}
sf::Vector2f Gun::getPosition() {
	sf::Vector2f ff;
	return ff;//�����κβ�����
}
void Gun::setOwner(Plane* owner,int kind) {
	this->owner = owner;
	this->kind = kind;
}