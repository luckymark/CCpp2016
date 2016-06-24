#pragma once
#include"Texture.h"
#include"Gun.h"
#include"Plane.h"
#include"ToolPoint.h"
class Enemy :public Plane {
public:
	int state = 0;
	Enemy(int enemytype);
	void heartBeat();
	void hit();
	bool needClear();
	bool isDead();
	~Enemy() {};
	int enemyliferemain;
private:
	int enemytype;
	Texture A;
};

