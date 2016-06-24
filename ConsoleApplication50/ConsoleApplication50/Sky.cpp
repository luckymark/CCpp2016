#include "stdafx.h"
#include "Sky.h"
#include"Enemy.h"
#include"Texture.h"
//ʵ�����ʡ���������������

Sky* Sky::instance = nullptr;
//ʵ������
Sky::Sky() {//��������
	stageofsky = 0;
	this->window = new sf::RenderWindow(sf::VideoMode(1224, 768), "1");
}
	//ʲô��˼
/*sf::Image icon;
if (icon.loadFromFile(path))
{
	this->window->setIcon(icon.getSize().x, icon.getSie().y, icon.getPixelsPtr());
}
this->background = new sf::Sprite(Texture::SKY);
}//��ͼ�ꣿΪʲôbackground��ָ�룿*/
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
void Sky::refresh() {//��Ҫ���ӳԵ��dongturntopower��ʵ��
	//this->window->draw(*this->background);//draw��ʲô��Ϊʲôthisǰ��Ҫ��ָ�룬window��ʲô������
	if (stageofsky == 0) {
		this->window->clear();
		this->clear();
		this->collision();//collision��ʲô �𰸣���ײ���
		this->createEnemies();
		for (auto &sprite : this->sprites) {//������
			sprite->heartBeat();//���ĸ������ �𰸣����ڼ��㼦��·��
			this->window->draw(*sprite);
		}
		this->window->display();
	}
	else {
		;//�˴�����bossս����;
		if (!this->whethercreateboss) {
			createBoss();
			whethercreateboss = 1;
		}
		//std::cout << "A";
		this->clearbossfight();
		this->collisionbossfight();
		this->window->clear();
		for (auto &sprite : this->sprites) {//������
			sprite->heartBeat();//���ĸ������ �𰸣����ڼ��㼦��·��
			this->window->draw(*sprite);//��ͼ����
		}
		this->window->display();
	}
}
void Sky::bombclear()
{
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end();) {
		{
			delete *it_enemy;//����С��
			this->sprites.erase(*it_enemy);//��ʲô...
			it_enemy = (this->enemies).erase(it_enemy);
		}
	}
	for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
		{
			delete *it_enemybullet;//����С��
			this->sprites.erase(*it_enemybullet);//��ʲô...
			it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
		}
	}
}
void Sky::whetherIdied(Hero* hero) {//һ��ʼ�����ˣ�����Ϊ��ͷ�ļ�����cpp�ļ���
	if (hero->whetherWD==0) {
		if (this->whethercreateboss == 0) {//��Ϊbossս����ͨ
			for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end(); ++it_enemy) {
				if ((*it_enemy)->intersects(hero))
				{
					if ((hero->life) > 0) {
						hero->life--;
						hero->setPosition(512, 768);
						hero->whetherWD = 1;
						hero->clockWD.restart();
						for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
							//��������
							delete *it_enemybullet;
							this->sprites.erase(*it_enemybullet);
							it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
						}
					}
					else
					{
						this->clear();//�������򣬲��ҳ����������� ���Ľ�
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
						//��������
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
					hero->life--;//����һ�����õ�λ�ã��������4s�޵�
					hero->setPosition(512,768);
					hero->whetherWD = 1;
					hero->clockWD.restart();
					for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) {
						//��������
						delete *it_enemybullet;
						this->sprites.erase(*it_enemybullet);
						it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
					}
					break;
				}
				else
				{
					this->clear();//�������򣬲��ҳ����������� ���Ľ�
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
void Sky::clear() {//������������ӵ�
	for (auto it_mybullet = this->myBullets.begin(); it_mybullet != this->myBullets.end();)
		if ((*it_mybullet)->getPosition().y < 0 || (*it_mybullet)->getPosition().x < 0 || (*it_mybullet)->getPosition().x>1024 || (*it_mybullet)->getPosition().y >768) {//���Կ���д��need clear����
			delete *it_mybullet;//�о�STL�ı�����
			this->sprites.erase(*it_mybullet);
			it_mybullet = (this->myBullets).erase(it_mybullet);
		}//���ȴ���it_mybullet++����for��ߣ�̽��Ϊʲô���������ͬʱ�ڴ�ռ�úͿ��Ĺ�ϵ����(��Ϊ���������ӵ���ʹ�ڴ�һֱ�����߻��ǲ���,��������û�����������ӵ����ڴ��ȴ��
		else
			it_mybullet++;//�˴�������ϲ����ټ�������
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end();) {
		if ((*it_enemy)->needClear()) {
			delete *it_enemy;//����С��
			this->sprites.erase(*it_enemy);//��ʲô...
			it_enemy = (this->enemies).erase(it_enemy);
		}
		else {
			++it_enemy;
		}
	}
	for (auto it_toolpoint = this->toolPoints.begin(); it_toolpoint != this->toolPoints.end();)
		if ((*it_toolpoint)->getPosition().y < 0 || (*it_toolpoint)->getPosition().x < 0 || (*it_toolpoint)->getPosition().x>1024 || (*it_toolpoint)->getPosition().y >768) {//���Կ���д��need clear����
			delete *it_toolpoint;//�о�STL�ı����� ���󣺵�һ�ΰѻ�д������
			this->sprites.erase(*it_toolpoint);
			it_toolpoint = (this->toolPoints).erase(it_toolpoint);
		}//���ȴ���it_mybullet++����for��ߣ�̽��Ϊʲô���������ͬʱ�ڴ�ռ�úͿ��Ĺ�ϵ����(��Ϊ���������ӵ���ʹ�ڴ�һֱ�����߻��ǲ���,��������û�����������ӵ����ڴ��ȴ��
		else
			it_toolpoint++;//�˴�������ϲ����ټ�������
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
void Sky::clearbossfight()//ֻ��Ҫ�����Լ����ӵ�
{
	for (auto it_mybullet = this->myBullets.begin(); it_mybullet != this->myBullets.end();)
		if ((*it_mybullet)->getPosition().y < 0 || (*it_mybullet)->getPosition().x < 0 || (*it_mybullet)->getPosition().x>1024 || (*it_mybullet)->getPosition().y >768) {//���Կ���д��need clear����
			delete *it_mybullet;//�о�STL�ı�����
			this->sprites.erase(*it_mybullet);
			it_mybullet = (this->myBullets).erase(it_mybullet);
		}//���ȴ���it_mybullet++����for��ߣ�̽��Ϊʲô���������ͬʱ�ڴ�ռ�úͿ��Ĺ�ϵ����(��Ϊ���������ӵ���ʹ�ڴ�һֱ�����߻��ǲ���,��������û�����������ӵ����ڴ��ȴ��
		else
			it_mybullet++;//
	for (auto it_enemybullet = this->enemyBullets.begin(); it_enemybullet != this->enemyBullets.end();) 
		{
			if ((*it_enemybullet)->getPosition().x < 0 || (*it_enemybullet)->getPosition().y < 0 || (*it_enemybullet)->getPosition().x > 1024 || (*it_enemybullet)->getPosition().y>768)
			{
				delete *it_enemybullet;//����С��
				this->sprites.erase(*it_enemybullet);//��ʲô...
				it_enemybullet = (this->enemyBullets).erase(it_enemybullet);
			}
			else
			{
				it_enemybullet++;
			}
		}
}
void Sky::collision() {//��ײ���
	for (auto it_enemy = this->enemies.begin(); it_enemy != this->enemies.end(); ++it_enemy) {
		if ((*it_enemy)->isDead())//�������������������������������������������������������������������������޸�isdead�Ķ��������첻ͬ���˵�Ѫ��
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
			}//��������ÿһ���ɻ����Ƿ�ᱻÿһ���ӵ�����
		}


	}

void Sky::collisionbossfight()
{
	auto it_boss = booss;
	for (auto it_bullet = this->myBullets.begin(); it_bullet != this->myBullets.end(); ++it_bullet) {
		if ((*it_bullet)->intersects(it_boss)) {//ʲôʱ���ָ����ţ�ʲôʱ�򲻼�
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
	static int count = 0;//֡����ʵ�ַ��������޸�
	switch (enemystage)
	{
	case 0:
		if (clock1.getElapsedTime()<= t15) 
		{//��һ�׶γ���ʱ��
			if (++count >= 60)
			{
				Enemy* enemy = new Enemy(2);//ʵ������enemyʱ�Զ�����
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				count = 0;//���Ƶ�������
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
				Enemy* enemy = new Enemy(3);//ʵ������enemyʱ�Զ�����
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				count = 0;//���Ƶ�������
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
				Enemy* enemy = new Enemy(2);//ʵ������enemyʱ�Զ�����
				this->sprites.insert(enemy);
				this->enemies.insert(enemy);
				Enemy* enemy1 = new Enemy(3);//ʵ������enemyʱ�Զ�����
				this->sprites.insert(enemy1);
				this->enemies.insert(enemy1);
				count = 0;//���Ƶ�������
			}
		}
		else
		{
			enemystage++;
			clock1.restart();
		}
		break;

	}
	case 3://�ȼ���ڶ��׶ν���bossս���������ֳ�
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
	this->booss = boss;//�������������
}
Sky* Sky::getInstance() {
	if (!instance) {//ʲô��˼
		instance = new Sky;
	}
	return instance;
}

