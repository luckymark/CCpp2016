#pragma once

#include"Flying.hpp"
#include"Myshoot.hpp"

class Myplane:public Flying
{
public:
	Myplane();
	~Myplane();
	void moveMe();
	float getSpeed();
	void shoot( Myshoot *myshoot[],int i);
	int times;
	int life;
	template<typename T>
	void collision(T *t[], int i);
	template<typename T>
	void collisiongift(T *t[], int i, sf::Time gunclock);
	template<typename T>
	inline bool ifcollide(T *t);
	bool getInvincible();
	void beInvincible();
	void outofInvincible();
	int getGun();

private:
	float movespeed;
	bool invincible;
	int gun;
	sf::Time gunclock;
};

template<typename T>
inline void Myplane::collision(T * t[], int i)
{
	for (size_t j = 0; j < i; j++)
	{
		if (t[j] != NULL && (t[j]->getIfboom() == 0))
		{
			if (ifcollide<T>(t[j]))
			{
				t[j]->setColor(sf::Color(255, 255, 255, 80));
				this->times -= t[j]->times;
				t[j]->times -= 100;
			}
		}
	}
}

template<typename T>
inline void Myplane::collisiongift(T * t[], int i, sf::Time gunclock)
{
	if (gunclock - Myplane::gunclock > sf::seconds(10))
	{
		gun = 0;
	}
	for (size_t j = 0; j < i; j++)
	{
		if (t[j] != NULL && (t[j]->getIfboom() == 0))
		{
			if (ifcollide<T>(t[j]))
			{
				this->times += t[j]->times;
				if (this->times > 20)
				{
					if (life < 3)
					{
						life += 1;
						this->times -= 20;
					}
					else
					{
						this->times = 20;
					}
				}
				t[j]->times = -1;

				if (t[j]->getGuntype() != 0)
				{
					gun = t[j]->getGuntype();
					Myplane::gunclock = gunclock;
				}
			}
		}
	}
}

template<typename T>
inline bool Myplane::ifcollide(T *t)
{
	return sqrt((t->getX() - this->getX())*(t->getX() - this->getX()) + (t->getY() - this->getY())*(t->getY() - this->getY())) <= t->getRadius() + this->getRadius();
}
