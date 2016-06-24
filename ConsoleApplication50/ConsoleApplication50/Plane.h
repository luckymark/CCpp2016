#pragma once
#include<SFML/Graphics.hpp>
#include"Sound.h"
#include"Gun.h"
#include"LaunchToolPoint.h"
#include<iostream>
#include"Sprite.h"
class Plane:public Sprite{
public:
	void fire();
	void launch();
protected:
	Gun gun;	
	LaunchToolPoint launchtoolpoint;
};

