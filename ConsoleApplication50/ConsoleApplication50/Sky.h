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
public://实验性质:取得hero的位置
static Sky* getInstance();//将sf类的指针作为静态变量？？？？？【】【】【】【】【】【】【】【】】
	sf::RenderWindow* getWindow() {
		return this->window;
	}//实现窗口的方法
	void add(Sprite* sprite);//为画布添加元素
	void addMyBullet(Bullet*);//子弹
	void addEnemyBullet(Bullet*);
	void addToolPoint(ToolPoint*);
	void refresh();//清屏用
	void bombclear();
	void whetherIdied(Hero* hero);
	void whetherIgetDong(Hero* hero);//判断是否得到了东点
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
	int stageofsky;//阶段，为0时打小怪，为1时打boss
	int enemystage=0;//打小怪的阶段！！！！！！！！！！！！！！！！！！！！！！！！！！！暂时改成10了
	int whethercreateboss =	0;//是否产生了boss？ 和上面的变量可以去掉一个
	int whethersetenemyclock = 0;//用于最初产生小怪用，如果为0则还没有重置过clock1
};

