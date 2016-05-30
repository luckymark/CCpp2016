#include "Collision.h"
#include<iostream>
#include<cmath>
using namespace std;
void Collision::doCollision(vector<Boom*> &boom, vector<Enemy*> &enemy,vector<Explode *> &lexplode)
{
	
	Boom *middleBoom = new Boom();
	Enemy *middleEnemy;
	Explode *middle;
	middleBoom = boom[0];
	for (int i = 0; i < enemy.size(); i++)
	{
		middleEnemy = enemy.at(i);
		if ((middleBoom->gety()>middleEnemy->gety())&&(middleBoom->gety() - middleEnemy->gety() <= 72)||(middleBoom->gety()<middleEnemy->gety()&&middleEnemy->gety()-middleBoom->gety()<=300))
		{			
			if ((middleBoom->getx()>middleEnemy->getx())&&(middleBoom->getx() - middleEnemy->getx() <= 72))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				middle = new Explode(*middleEnemy);
				lexplode.push_back(middle);
				n++;
				if (!buffer.loadFromFile("D://DearDeer.ogg"))
				{
					exit(0);
				}

				sound.setBuffer(buffer);
				sound.play();
			}
			else if ((middleBoom->getx()<middleEnemy->getx()) && (middleEnemy->getx() - middleBoom->getx() <= 20))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				middle = new Explode(*middleEnemy);
				lexplode.push_back(middle);
				n++;
				if (!buffer.loadFromFile("D://DearDeer.ogg"))
				{
					exit(0);
				}

				sound.setBuffer(buffer);
				sound.play();
			}
		}
	}
	
}

bool Collision::godCollision(vector<Enemy*> &enemy, vector<Boom*> &boom, Plane * plane)
{
	Boom *middleBoom;
	Enemy *middleEnemy;
	vector<Boom *>::iterator iBoom;
	vector<Enemy *>::iterator iEnemy;
	for (int i = 0; i < boom.size(); i++)
	{
		middleBoom = boom[i];
		if ((middleBoom->getx() < plane->getx()) && (plane->getx() - middleBoom->getx() < 1))
		{
			if ((middleBoom->gety() < plane->gety()) && (plane->gety() - middleBoom->gety() < 1))
			{
				iBoom = boom.begin() + i;
				boom.erase(iBoom);
				life--;
				return true;
			}
			else if ((middleBoom->gety() > plane->gety()) && (middleBoom->gety() - plane->gety() < 72))
			{
				iBoom = boom.begin() + i;
				boom.erase(iBoom);
				life--;
				return true;
			}
		}
		else if ((middleBoom->getx() > plane->getx()) && (middleBoom->getx() - plane->getx() < 62))
		{
			if ((middleBoom->gety() < plane->gety()) && (plane->gety() - middleBoom->gety() < 1))
			{
				iBoom = boom.begin() + i;
				boom.erase(iBoom);
				life--;
				return true;
			}
			else if ((middleBoom->gety() > plane->gety()) && (middleBoom->gety() - plane->gety() < 72))
			{
				iBoom = boom.begin() + i;
				boom.erase(iBoom);
				life--;
				return true;
			}
		}
	}
	for (int i = 0; i < enemy.size(); i++)
	{
		middleEnemy = enemy[i];
		if ((middleEnemy->getx() < plane->getx()) && (plane->getx() - middleEnemy->getx() - 52 < 1))
		{
			if ((middleEnemy->gety() < plane->gety()) && (plane->gety() - middleEnemy->gety() - 72 < 1))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				life--;
				return true;
			}
			else if ((middleEnemy->gety() > plane->gety()) && (middleEnemy->gety() - plane->gety() - 72 < 72))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				life--;
				return true;
			}
		}
		else if ((middleEnemy->getx() > plane->getx()) && (middleEnemy->getx() - plane->getx() - 52 < 1))
		{
			if ((middleEnemy->gety() < plane->gety()) && (plane->gety() - middleEnemy->gety() - 72 < 1))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				life--;
				return true;
			}
			else if ((middleEnemy->gety() > plane->gety()) && (middleEnemy->gety() - plane->gety() - 72 < 72))
			{
				iEnemy = enemy.begin() + i;
				enemy.erase(iEnemy);
				life--;
				return true;
			}
		}
	}
	return false;
}
