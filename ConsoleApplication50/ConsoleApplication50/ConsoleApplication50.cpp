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
#include"Sky.h"//������ӵ���
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
	int usebomb = 0;//�Ƿ�ʹ��ըҩ
	//int stage = 0;//0=С�֣�1=bossս
	sf::Time t1 = sf::seconds(20);//ʵ������[][][]��������������������������������������������������
	sf::Clock clock1;//ʵ������[][][]��������������������������������������������������
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
		{//�ƺ���û������Ĵ�����
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
			//�о���ס�벻��ס
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
				if (hero.havebomb()) //bossս������
				{
					sky->bombclear();//�Ľ�������޵�ʱ��
					hero.bomblost();
					hero.clockWD.restart();
					hero.whetherWD = 1;
				}
			}
			sky->whetherIdied(&hero);
			sky->refresh();
			sky->whetherIgetDong(&hero);//��仰������ȽϺã�
		}
	}
	return EXIT_SUCCESS;
}


