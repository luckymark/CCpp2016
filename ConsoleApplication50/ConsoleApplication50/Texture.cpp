#include "stdafx.h"
#include "texture.h"//这个类用于读取

void Texture::load(int i) {
	switch (i)
	{
	case 1: {
		HERO.loadFromFile("hero.png");
		break; 
	}
	case 2: {
		ENEMY1.loadFromFile("enemy1.png");
		break;
	}
	case 3: {
		ENEMY_DOWN_1.loadFromFile("4.png");
		break;
	}
	case 4: {
		ENEMY_DOWN_2.loadFromFile("4.png");
		break; }
	case 5: {
		ENEMY_DOWN_3.loadFromFile("4.png");
		break;
	}
	case 6: {
		ENEMY_DOWN_4.loadFromFile("4.png");
		break;
	}
	case 7: {
		BULLET.loadFromFile("4.png");
		break; }
	case 8: {
		SKY.loadFromFile("4.png");
		break;
	}
	case 9:{
		DONGPOINT.loadFromFile("dongpoint.png");
		break;
	}
	case 10: {
		POWERPOINT.loadFromFile("4.png");
		break;
	}
	case 11: {
		ENEMY2.loadFromFile("enemytype2.png");
		break;
	}
	case 12: {
		ENEMYBULLET.loadFromFile("enemybullet.png");
		break;
	}
	case 13: {
		BOSS.loadFromFile("boss.png");//待修改材质
		break;
	}
	case 14: {
		LIGHT.loadFromFile("light.png");
	}
			break;

	}
}


