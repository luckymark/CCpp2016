#include"stdafx.h"
#define Ten 10
#include<iostream>
#include<stdlib.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
//#include<SFML/Audio.hpp>
//#include"Sound.h"
#include"Texture.h"
#include"Hero.h"
#include"Sky.h"//自行添加的类
#include<vector>

int main() {
	//Sound::load();
	/*sf::Texture DongPoint;
	sf::Texture PowerPoint;
	DongPoint.loadFromFile("DongPoint.JPG");
	PowerPoint.loadFromFile("Ppoint.JPG");
	sf::Sprite DongPoint1(DongPoint);
	sf::Sprite PowerPoint1(PowerPoint);
	DongPoint1.setPosition(sf::Vector2f(1052, 64));
	PowerPoint1.setPosition(sf::Vector2f(1052, 164));
	*/
	Sky* sky = Sky::getInstance();
	sf::RenderWindow* window = sky->getWindow();
	//Sound::BACK_GROUND.play();
	Hero hero;
	sky->add(&hero);
	int a = 0;
	int usebomb = 0;//是否使用炸药
	//int stage = 0;//0=小怪，1=boss战
	sf::Time t1 = sf::seconds(20);//实验性质[][][]【】【】【】【】【】【】【】【】【】【】【【】【】
	sf::Clock clock1;//实验性质[][][]【】【】【】【】【【【】【】【】【】【】【】【】【
	window->setFramerateLimit(100);
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) 
			{
				window->close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
			{
				window->close();
			}
		}
		{//似乎是没有意义的大括号
			if (event.type == sf::Event::Closed) 
			{
				window->close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
			{
				window->close();
			}//

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
					hero.move2leftslow();
				else
					hero.move2left();
			//研究按住与不安住
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
					hero.move2rightslow();
				else
					hero.move2right();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
					hero.move2upslow();
				else
					hero.move2up();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
					hero.move2downslow();
				else
					hero.move2down();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) 
			{
				hero.fire();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) 
			{
				if (hero.havebomb()) //boss战不能用
				{
					sky->bombclear();//改进，添加无敌时间
					hero.bomblost();
					hero.clockWD.restart();
					hero.whetherWD = 1;
				}
			}
			sky->whetherIdied(&hero);
			sky->refresh();
			sky->whetherIgetDong(&hero);//这句话放哪里比较好？
		}
	}
	return EXIT_SUCCESS;
}


