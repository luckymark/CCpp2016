#include "stdafx.h"
#include "Sound.h"
sf::Music Sound::BACK_GROUND;
sf::Music Sound::ENEMY_DOWN;	
void Sound::load() {
	BACK_GROUND.openFromFile("th.mp3");
	ENEMY_DOWN.openFromFile("th3.m4a");
}	