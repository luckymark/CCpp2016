#pragma once

#include<string>
#include<iostream>
#include<ctime>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Background.hpp"
#include"Type.hpp"
#include"Load.hpp"
#include"Myplane.hpp"
#include"Enemy.hpp"
#include"Boss.hpp"
#include"Enemyshoot.hpp"
#include"Myshoot.hpp"

class Game
{
public:
	Game();
	void play();
	void record_time();
	void loop();
	void giveTexture();
	void drawall(sf::RenderWindow &window);
	void collision();
	template<typename T>
	void ifalpha(T *t[], int i);
	void deletethem();
	template<typename T>
	void ifdelete(T *t[], int i);
	void countingdown();
	void keyboardManager(sf::Window &window);
	void mouseManager(sf::Window &window);
	template <typename T>
	int create(T *t[], int i);
	void createenemy();
	void shootall();
	
private:
	static sf::Clock clock;
	Load load;
	bool ifRefrash = false;
	sf::Time timeNow;
	Background background1;
	Background background2;
	Type type;
	Myplane myplane;
	Myshoot *myshoot[300];
	Enemy *enemy[20];
	Enemyshoot *enemyshoot[200];
	Boss *boss[5];
	sf::Time invicible_time;
	Type gameover;
	Type tryagain;
	sf::Sound shootSound;
	sf::Sound bossShootSound;
	sf::Sound myShootSound;
	sf::Sound enemyBoom;
	bool customspassing;
	int score;
	int lastscore;
	int customspass;
	float multiple;
	Type *customspasstype[10];
	sf::Time passing_time;
	std::string str[10];

};

template<typename T>
inline void Game::ifalpha(T * t[], int i)
{
	for (size_t j = 0; j < i; j++)
	{
		if (t[j] != NULL&&t[j]->getColor() == sf::Color(255, 255, 255, 80))
		{
			t[j]->setColor(sf::Color(255, 255, 255, 255));
		}
	}
}

template<typename T>
inline void Game::ifdelete(T * t[], int i)
{
	if (i < 100)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (t[j] != NULL && t[j]->getIfboom() == 0 && (t[j]->times <= 0 || t[j]->getX() <= -43 || t[j]->getX() >= 643 || t[j]->getY() <= -200 || t[j]->getY() >= 843))
			{
				if (t[j]->times <= 0)
				{
					enemyBoom.play();
					if (i < 10)
					{
						score += 100;
					}
					else
					{
						score += 20;
					}
				}
				t[j]->setIfboom(1);
				t[j]->setCountdown(t[j]->gettimeNow());
				/*delete t[j];
				t[j] = NULL;*/
			}
		}
	}
	else
	{
		for (size_t j = 0; j < i; j++)
		{
			if (t[j] != NULL && (t[j]->times <= 0 || t[j]->getX() <= -43 || t[j]->getX() >= 643 || t[j]->getY() <= -200 || t[j]->getY() >= 843))
			{
				delete t[j];
				t[j] = NULL;
			}
		}
	}
}

template<typename T>
int Game::create(T *t[], int i)
{
	int m_rand = rand();
	for (int j = 0; j < i; j++)
	{
		if (t[j] == NULL)
		{
			t[j] = new T(m_rand, 1.5);
			return j;
		}
	}
}
