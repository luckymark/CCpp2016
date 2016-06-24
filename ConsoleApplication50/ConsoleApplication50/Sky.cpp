#include "stdafx.h"
#include "Sky.h"
#include"Enemy.h"
#include"Texture.h"
//实验性质【】【】【】【】

Sky* Sky::instance = nullptr;
//实验性质
Sky::Sky() {//创建背景
	stageofsky = 0;
	this->window = new sf::RenderWindow(sf::VideoMode(1224, 768), "1");
}
	//什么意思
/*sf::Image icon;
if (icon.loadFromFile(path))
{
	this->window->setIcon(icon.getSize().x, icon.getSie().y, icon.getPixelsPtr());
}
this->background = new sf::Sprite(Texture::SKY);
}//换图标？为什么background是指针？*/
void Sky::add(Sprite* sprite) {
	this->sprites.insert(sprite);
}
void Sky::addMyBullet(Bullet* bullet) {
	this->myBullets.insert(bullet);
}
void Sky::addEnemyBullet(Bullet *bullet)
{
		this->enemyBullets.insert(bullet);
}
void Sky::addToolPoint(ToolPoint* toolpoint) {
	this->toolPoints.insert(toolpoint);
}
void Sky::refresh() {//需要增加吃点和dongturntopower的实现
	//this->window->draw(*this->background);//draw是什么，为什么this前面要加指针，window是什么？？？
	if (stageofsky == 0) {
		this->window->clear();
		this->clear();
		this->collision();//collision是什么 答案：碰撞检测
		this->createEnemies();
		for (auto &sprite : this->sprites) {//容器？
			sprite->heartBeat();//这哪个类里的 答案：用于计算鸡蛋路径
			this->window->draw(*sprite);
		}
		this->window->display();
	}
	else {
		;//此处输入boss战处理;
		if (!this->whethercreateboss) {
			createBoss();
			whethercreateboss = 1;
		}
		//std::cout << "A";
		this->clearbossfight();
		this->collisionbossfight();
		this->window->clear();
		for (auto &sprite : this->sprites) {//容器？
			sprite->heartBeat();//这哪个类里的 答案：用于计算鸡蛋路径
			this->window->draw(*sprite);//画图函数
		}
		this->window->display();
	}
}
void Sky::bombclear()
{
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end();) {
		{
			delete *it_enemy;//清理小怪
			this->sprites.erase(*it_enemy);//这什么...
			it_enemy = (this->enemies).erase(it_enemy);
		}
	}
	for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
		{
			delete *it_enemybullet;//清理小怪
			this->sprites.erase(*it_enemybullet);//这什么...
			it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
		}
	}
}
void Sky::whetherIdied(Hero* hero) {//一开始出错了，是因为把头文件放在cpp文件里
	if (hero->whetherWD==0) {
		if (this->whethercreateboss == 0) {//分为boss战和普通
			for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end(); ++it_enemy) {
				if ((*it_enemy)->intersects(hero))
				{
					if ((hero->life) > 0) {
						hero->life--;
						hero->setPosition(512, 768);
						hero->whetherWD = 1;
						hero->clockWD.restart();
						for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
							//死亡消弹
							delete *it_enemybullet;
							this->sprites.erase(*it_enemybullet);
							it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
						}
					}
					else
					{
						this->clear();//结束程序，并且出现死亡画面 待改进
					}

				}
			}
		}
		else {
			auto it_boss = booss;
			if ((it_boss)->intersects(hero))
			{
				if ((hero->life) > 0) {
					hero->life--;
					hero->setPosition(512, 768);
					hero->whetherWD = 1;
					hero->clockWD.restart();
					for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
						//死亡消弹
						delete *it_enemybullet;
						this->sprites.erase(*it_enemybullet);
						it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
					}
				}
			}

		}
		for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end(); ++it_enemybullet) {
			if ((*it_enemybullet)->intersects(hero))
			{
				if ((hero->life) > 0) {
					hero->life--;//设置一个更好的位置，并且添加4s无敌
					hero->setPosition(512,768);
					hero->whetherWD = 1;
					hero->clockWD.restart();
					for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
						//死亡消弹
						delete *it_enemybullet;
						this->sprites.erase(*it_enemybullet);
						it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
					}
					break;
				}
				else
				{
					this->clear();//结束程序，并且出现死亡画面 待改进
				}

			}
		}
	}
	else
	{
		if (hero->clockWD.getElapsedTime() >= t5)
			hero->whetherWD = 0;
	}
}
void Sky::whetherIgetDong(Hero * hero)
{
	for (auto it_toolpoint = this->toolPoints.begin(); it_toolpoint != this->toolPoints.end(); ++it_toolpoint) {
		if ((*it_toolpoint)->intersects(hero)) {
			delete *it_toolpoint;
			this->sprites.erase(*it_toolpoint);
			(this->toolPoints).erase(it_toolpoint);
			hero->HeroDong++;
			break;
		}
	}
}
void Sky::clear() {//清理出界怪物和子弹
	for (auto it_mybullet = this->myBullets.begin(); it_mybullet != this->myBullets.end();)
		if ((*it_mybullet)->getPosition().y < 0 || (*it_mybullet)->getPosition().x < 0 || (*it_mybullet)->getPosition().x>1024 || (*it_mybullet)->getPosition().y >768) {//可以考虑写个need clear函数
			delete *it_mybullet;//研究STL的遍历？
			this->sprites.erase(*it_mybullet);
			it_mybullet = (this->myBullets).erase(it_mybullet);
		}//早先错误：it_mybullet++放在for里边，探究为什么这样会出错，同时内存占用和卡的关系？？(因为消除出界子弹后即使内存一直在升高还是不卡,但是早先没有消除出界子弹，内存低却卡
		else
			it_mybullet++;//此处与下面合并减少计算量？
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end();) {
		if ((*it_enemy)->needClear()) {
			delete *it_enemy;//清理小怪
			this->sprites.erase(*it_enemy);//这什么...
			it_enemy = (this->enemies).erase(it_enemy);
		}
		else {
			++it_enemy;
		}
	}
	for (auto it_toolpoint = this->toolPoints.begin(); it_toolpoint != this->toolPoints.end();)
		if ((*it_toolpoint)->getPosition().y < 0 || (*it_toolpoint)->getPosition().x < 0 || (*it_toolpoint)->getPosition().x>1024 || (*it_toolpoint)->getPosition().y >768) {//可以考虑写个need clear函数
			delete *it_toolpoint;//研究STL的遍历？ 错误：第一次把或写成与了
			this->sprites.erase(*it_toolpoint);
			it_toolpoint = (this->toolPoints).erase(it_toolpoint);
		}//早先错误：it_mybullet++放在for里边，探究为什么这样会出错，同时内存占用和卡的关系？？(因为消除出界子弹后即使内存一直在升高还是不卡,但是早先没有消除出界子弹，内存低却卡
		else
			it_toolpoint++;//此处与下面合并减少计算量？
	for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();)
		if ((*it_enemybullet)->getPosition().x < 0 || (*it_enemybullet)->getPosition().y < 0 || (*it_enemybullet)->getPosition().x > 1024 || (*it_enemybullet)->getPosition().y>768)
		{
			delete *it_enemybullet;
			this->sprites.erase(*it_enemybullet);
			it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
		}
		else
			it_enemybullet++;
}
void Sky::clearbossfight()//只需要便利自己的子弹
{
	for (auto it_mybullet = this->myBullets.begin(); it_mybullet != this->myBullets.end();)
		if ((*it_mybullet)->getPosition().y < 0 || (*it_mybullet)->getPosition().x < 0 || (*it_mybullet)->getPosition().x>1024 || (*it_mybullet)->getPosition().y >768) {//可以考虑写个need clear函数
			delete *it_mybullet;//研究STL的遍历？
			this->sprites.erase(*it_mybullet);
			it_mybullet = (this->myBullets).erase(it_mybullet);
		}//早先错误：it_mybullet++放在for里边，探究为什么这样会出错，同时内存占用和卡的关系？？(因为消除出界子弹后即使内存一直在升高还是不卡,但是早先没有消除出界子弹，内存低却卡
		else
			it_mybullet++;//
	for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) 
		{
			if ((*it_enemybullet)->getPosition().x < 0 || (*it_enemybullet)->getPosition().y < 0 || (*it_enemybullet)->getPosition().x > 1024 || (*it_enemybullet)->getPosition().y>768)
			{
				delete *it_enemybullet;//清理小怪
				this->sprites.erase(*it_enemybullet);//这什么...
				it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
			}
			else
			{
				it_enemybullet++;
			}
		}
}
void Sky::collision() {//碰撞检测
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end(); ++it_enemy) {
		if ((*it_enemy)->isDead())//【】【】【】【】【】【】【】【】【】【】【】【】【】【】【】【】【】【】修改isdead的定义来构造不同敌人的血量
		{
			//(*it_enemy)->state++;
			continue;//
		}
		for (auto it_bullet = this->myBullets.begin(); it_bullet != this->myBullets.end(); ++it_bullet) {
			if ((*it_enemy)->intersects(*it_bullet)) {
				delete *it_bullet;
				this->sprites.erase(*it_bullet);
				(this->myBullets).erase(it_bullet);
				(*it_enemy)->hit();
				break;
				}
			}//遍历，对每一个飞机，是否会被每一颗子弹击中
		}


	}

void Sky::collisionbossfight()
{
	auto it_boss = booss;
	for (auto it_bullet = this->myBullets.begin(); it_bullet != this->myBullets.end(); ++it_bullet) {
		if ((*it_bullet)->intersects(it_boss)) {//什么时候加指针符号，什么时候不加
			delete *it_bullet;
			this->sprites.erase(*it_bullet);
			(this->myBullets).erase(it_bullet);
			it_boss->hit();
			break;
		}
	}
}


void Sky::createEnemies(){
	if (whethersetenemyclock == 0)
	{
		clock1.restart();
		this->whethersetenemyclock = 1;
	}
	static int count = 0;//帧数的实现方法，可修改
	switch (enemystage)
	{
	case 0:
		if (clock1.getElapsedTime()<= t15) 
		{//第一阶段持续时间
			if (++count >= 60)
			{
				Enemy* enemy = new Enemy(2);//实现生成enemy时自动输入
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				count = 0;//控制敌人生成
			}
		}
		else 
		{
			enemystage++;
			clock1.restart();
		}
		break;
	case 1: 
	{
		if (clock1.getElapsedTime() <= t5)
		{
			if (++count >= 60)
			{
				Enemy* enemy = new Enemy(3);//实现生成enemy时自动输入
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				count = 0;//控制敌人生成
			}
		}
		else
			{
				enemystage++;
				clock1.restart();
			}
			break;
		}
	case 2:
	{
		if (clock1.getElapsedTime() <= t15)
		{
			if (++count > 50)
			{
				Enemy* enemy = new Enemy(2);//实现生成enemy时自动输入
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				Enemy* enemy1 = new Enemy(3);//实现生成enemy时自动输入
				this->sprites.insert(enemy1);
				this->enemies.insert(enemy1);
				count = 0;//控制敌人生成
			}
		}
		else
		{
			enemystage++;
			clock1.restart();
		}
		break;

	}
	case 3://先假设第二阶段进入boss战，先清理现场
	{
		if (enemies.empty() && enemies.empty() && toolPoints.empty())
			this->stageofsky = 1;
		break;
	}
	break;
	}

}


void Sky::createBoss()
{
	Boss* boss = new Boss;
	std::cout << "B";
	this->sprites.insert(boss);
	this->booss = boss;//这样储存可以吗？
}
Sky* Sky::getInstance() {
	if (!instance) {//什么意思
		instance = new Sky;
	}
	return instance;
}

