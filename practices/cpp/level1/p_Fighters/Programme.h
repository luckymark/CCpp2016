#pragma once
#include"Backround.h"
#include"Sound.h"
#include"Plane.h"
#include"Text.h"
#include"Boom.h"
#include"Collision.h"
#include"explode.h"
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;
extern int n;
extern int life;
extern int bigBoom;
#define SPEED 0.125
#define BOOMAMMOUNT 4
#define AFTERBOOM 3000
class Programme
{
private:
	Text *text;
	Sound *sound; 
	sf::SoundBuffer godBuffer;
	sf::Sound godSound;
	Backround *backround;
	sf::RenderWindow window;
	Plane *plane;
	Boom *boom;
	int isCreateEnemy;
	Enemy *enemy;
	Explode *explode;
	int enemyPosition;
	vector<Boom *>::iterator iBoom;
	vector<Enemy *>::iterator iEnemy;
	vector<Boom *>::iterator iEnemyBoom;
	vector<Boom *> lBoom;
	vector<Enemy *> lenemy;
	Collision docollision;
	vector<Boom *> lEnemyBoom;
	vector<Explode *> lExplode;
	vector<Explode *>::iterator iExplode;
	int afterCollision;
	int isDraw;
public:
	Programme():window(sf::VideoMode(800, 800), "Fighters!!")
	{
		
	}
	
	void run();
	void playsound();
	void iniBackround();
	void drawBackround();
	void drawPlane();
	void drawText();
	void iniBoom();
	void drawBoom();
	void addBoom(Boom *boom);
	void drawEnemy();
	void iniEnemy();
	void collision();
	void addEnemyBoom();
	void drawEnemyBoom();
	void randomMove();
	bool godCollision();
	void drawExplode();
	void drawBegin();
};