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
	inline bool ifcollide(T *t);
	bool getInvincible();
	void beInvincible();
	void outofInvincible();

private:
	float movespeed;
	bool invincible;
};

template<typename T>
inline void Myplane::collision(T * t[], int i)
{
	for (size_t j = 0; j < i; j++)
	{
		if (t[j] != NULL)
		{
			if (ifcollide<T>(t[j]))
			{
				this->times -= t[j]->times;
				t[j]->times -= 50;
			}
		}
	}
}

template<typename T>
inline bool Myplane::ifcollide(T *t)
{
	return sqrt((t->getX() - this->getX())*(t->getX() - this->getX()) + (t->getY() - this->getY())*(t->getY() - this->getY())) <= t->getRadius() + this->getRadius();
}
