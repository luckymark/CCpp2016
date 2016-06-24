#pragma once
#include<SFML/Graphics.hpp>
#include"Sprite.h"
#include"Enemy.h"
#include"Bullet.h"
#include<vector>
#include"Hero.h"
#include"ToolPoint.h"
#include"Boss.h"
#include<unordered_set>
using namespace std;
class Sky
{
public://ʵ������:ȡ��hero��λ��
static Sky* getInstance();//��sf���ָ����Ϊ��̬������������������������������������������������
	sf::RenderWindow* getWindow() {
		return this->window;
	}//ʵ�ִ��ڵķ���
	void add(Sprite* sprite);//Ϊ�������Ԫ��
	void addMyBullet(Bullet*);//�ӵ�
	void addEnemyBullet(Bullet*);
	void addToolPoint(ToolPoint*);
	void refresh();//������
	void bombclear();
	void whetherIdied(Hero* hero);
	void whetherIgetDong(Hero* hero);//�ж��Ƿ�õ��˶���
private:
	Sky();
	sf::RenderWindow* window;
	unordered_set<Sprite*> sprites;
	unordered_set<Enemy*> enemies;
	unordered_set<Bullet*> myBullets;
	unordered_set<Bullet*>enemyBullets;
	unordered_set<ToolPoint*> toolPoints;
	//unordered_set<Boss*>booss;
	Boss* booss;
	sf::Sprite* background = nullptr;
	static Sky*instance;
	void clear();
	void clearbossfight();
	void collision();
	void collisionbossfight();
	void createEnemies();
	void createBoss();
	sf::Time t20 = sf::seconds(20);//20s
	sf::Time t15 = sf::seconds(15);
	sf::Time t30 = sf::seconds(30);
	sf::Time t5 = sf::seconds(5);
	sf::Clock clock1;
	int stageofsky;//�׶Σ�Ϊ0ʱ��С�֣�Ϊ1ʱ��boss
	int enemystage=0;//��С�ֵĽ׶Σ�������������������������������������������������������ʱ�ĳ�10��
	int whethercreateboss =	0;//�Ƿ������boss�� ������ı�������ȥ��һ��
	int whethersetenemyclock = 0;//�����������С���ã����Ϊ0��û�����ù�clock1
};

