#pragma once
#include<vector>
#include<iterator>
#include"Boom.h"
#include"Enemy.h"
#include"explode.h"
#include"SFML\Audio.hpp"
using namespace std;
extern int n;
extern int life;
class Collision
{
public:
	sf::Sound sound;
	sf::SoundBuffer buffer;
	vector<Enemy *>::iterator iEnemy;
	void doCollision(vector<Boom *> &boom, vector<Enemy *> &enemy, vector<Explode *>&explode);
	bool godCollision(vector<Enemy *> &enemy,vector<Boom *> &boom,Plane *plane);
};