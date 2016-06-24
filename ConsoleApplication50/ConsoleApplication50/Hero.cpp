
#include "stdafx.h"
#include "Hero.h"
#include"Texture.h"
Hero::~Hero() {
	;
}
Hero::Hero()
{
	HeroBomb = 1;
	HeroDong = 0;
	HeroPower = 0;
	life = 20;
	a.load(1);
	this->setTexture(a.HERO);//什么意思
	this->setPosition(800, 600);
	this->gun.setOwner(this,1);//什么意思
}

void Hero::move2left() {
	if(this->getPosition().x-10>0)
	this->move(-10, 0);
}
void Hero::move2leftslow() {
	this->move(-3, 0);
}
void Hero::move2right() {
	if((this->getPosition().x + 10)<1024)
	this->move(10, 0);
}
void Hero::move2rightslow() {
	this->move(3, 0);
}
void Hero::move2up() {
	if((this->getPosition().y - 10)>0)
	this->move(0, -10);
}
void Hero::move2upslow() {
	this->move(0, -3);
}
void Hero::move2down() {
	if((this->getPosition().y + 10)<768)
	this->move(0, 10);
}
void Hero::move2downslow() {
	this->move(0, 3);
}

void Hero::bomblost()
{
	this->HeroBomb--;
}

void Hero::dongTurnToPower()
{
	if (this->HeroDong > 20) {
		this->HeroPower++;
		this->HeroDong = 0;
	}
}

bool Hero::havebomb()
{
	return HeroBomb;
}
