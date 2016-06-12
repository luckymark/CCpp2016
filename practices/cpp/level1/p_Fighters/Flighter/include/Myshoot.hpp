#pragma once

#include"Flying.hpp"
#include"Enemy.hpp"

class Myshoot:public Flying
{
public:
	Myshoot(float x,float y);
	~Myshoot();
	template<typename T>
	void collision(T *t[],int i);
	template<typename T>
	bool ifcollide(T *t);
	int times;

private:

};

template<typename T>
inline void Myshoot::collision(T * t[], int i)
{
	for (size_t j = 0; j < i; j++)
	{
		if (t[j] != NULL)
		{
			if (ifcollide<T>(t[j]))
			{
				t[j]->times -= 1;
				this->times = 0;
			}
		}
	}
}

template<typename T>
bool Myshoot::ifcollide(T *t)
{
	return sqrt((t->getX() - this->getX())*(t->getX() - this->getX()) + (t->getY() - this->getY())*(t->getY() - this->getY())) <= t->getRadius() + this->getRadius();
}
