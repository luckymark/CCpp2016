#define _CRT_SECURE_NO_WARNINGS

#include"Game.hpp"
#include<time.h>


sf::Clock Game::clock;

Game::Game()
	:background1(-2400),
	background2(-5500),
	type("PLAY!"),
	gameover("Game Over"),
	tryagain("Try Again")
{
	str[0] = "Level  1";
	str[1] = "Level  2";
	str[2] = "Level  3";
	str[3] = "Level  4";
	str[4] = "Level  5";
	str[5] = "Level  6";
	str[6] = "Level  7";
	str[7] = "Level  8";
	str[8] = "Level  9";
	str[9] = "Level  10";

	for (size_t i = 0; i < 10; i++)
	{
		customspasstype[i] = new Type(str[i]);
		customspasstype[i]->setPosition(200, 320);
		customspasstype[i]->setCharacterSize(60);
	}
	for (size_t i = 0; i < 10; i++)
	{
		customspasstype[i]->setFont(load.font);
	}
	multiple = 1;
	customspass = 1;
	customspassing = 1;
	score = 0;
	lastscore = 0;
	srand(time(0));
	timeNow = sf::seconds(0.00f);
	type.setPosition(270, 350);
	gameover.setPosition(250, 350);
	tryagain.setPosition(250, 420);

	for (size_t i = 0; i < 300; i++)
	{
		myshoot[i] = NULL;
	}
	for (size_t i = 0; i < 20; i++)
	{
		enemy[i] = NULL;
	}
	for (size_t i = 0; i < 200; i++)
	{
		enemyshoot[i] = NULL;
	}
	for (size_t i = 0; i < 5; i++)
	{
		boss[i] = NULL;
	}

}

void Game::play()
{
	record_time();
	loop();
}

void Game::record_time()
{
	if (clock.getElapsedTime() - timeNow >= sf::seconds(0.01f))
	{
		if (clock.getElapsedTime()-timeNow>=sf::seconds(0.02f))
		{
			timeNow = clock.getElapsedTime();
		}
		else
		{
		timeNow += sf::seconds(0.01f);
		}
		ifRefrash = true;
	}
	else
	{
		ifRefrash = false;
	}
}

//////////////////////////////////主循环//////////////////////////////////
void Game::loop()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "My window");

	window.setFramerateLimit(400);

	load.bgm.setLoop(1);
	load.bgm.setVolume(50);/*
	load.bgm.play();*/

	shootSound.setBuffer(load.buffer);
	bossShootSound.setBuffer(load.bossshootSound);
	myShootSound.setBuffer(load.myshootSound);
	enemyBoom.setBuffer(load.enemyBoom);
	
	while (window.isOpen())
	{
		giveTexture();
		record_time();
		sf::Event event;
		while(window.pollEvent(event));
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::LostFocus)
			{
				continue;
			}
		}

		mouseManager(window);//mouse if pressed

		keyboardManager(window);//keyboard if pressed

		if (ifRefrash)
		{
			if (type.getifConceled())//create enemies autoly
			{
				if (customspassing)
				{
					if (clock.getElapsedTime() - passing_time >= sf::seconds(1))
					{
						customspassing = 0;
					}
				}
				else
				{
					if (score >= (200 * multiple) + lastscore)
					{
						passing_time = clock.getElapsedTime();
						lastscore = score;
						customspass += 1;
						multiple *= 1.1;
						customspassing = 1;
						for (size_t i = 0; i < 200; i++)
						{
							if (enemyshoot[i] != NULL)
							{
								delete enemyshoot[i];
								enemyshoot[i] = NULL;
							}
						}
						for (size_t i = 0; i < 20; i++)
						{
							if (enemy[i] != NULL)
							{
								delete enemy[i];
								enemy[i] = NULL;
							}
						}
						for (size_t i = 0; i < 5; i++)
						{
							if (boss[i] != NULL)
							{
								delete boss[i];
								boss[i] = NULL;
							}
						}
					}
					else
					{
						ifalpha<Enemy>(enemy, 20);
						ifalpha<Boss>(boss, 5);
						createenemy();
						shootall();
						collision();
						deletethem();
						countingdown();
					}
				}
			}

			window.clear();

			drawall(window);

			window.display();
		}
		
	}
}
//////////////////////////////////主循环//////////////////////////////////

void Game::giveTexture()
{
	background1.setTexture(load.background);
	background2.setTexture(load.background);
	type.setFont(load.font);
	gameover.setFont(load.font);
	tryagain.setFont(load.font);
	myplane.setTexture(load.myplane);
	for (size_t i = 0; i < 20; i++)
	{
		if (enemy[i] != NULL && enemy[i]->getIfboom() == 0)
		{
			enemy[i]->setTexture(load.enemy);
		}
	}
	for (size_t i = 0; i < 200; i++)
	{
		if (enemyshoot[i] != NULL)
		{
			enemyshoot[i]->setTexture(load.enemyshoot);
		}
	}
	for (size_t i = 0; i < 300; i++)
	{
		if (myshoot[i] != NULL)
		{
			myshoot[i]->setTexture(load.myshoot);
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL && boss[i]->getIfboom() == 0)
		{
			boss[i]->setTexture(load.boss);
		}
	}
}

/////////////////////////////////绘制图形/////////////////////////////////

void Game::drawall(sf::RenderWindow &window)
{
	background1.move();//background1
	background1.ifBottom();
	window.draw(background1);

	background2.move();//background2
	background2.ifBottom();
	window.draw(background2);

	if (!type.getifConceled())
	{
		window.draw(type);//menu
	}
	else
	{
		myplane.moveMe();//myplane
		window.draw(myplane);

		for (size_t i = 0; i < 300; i++)
		{
			if (myshoot[i] != NULL)
			{
				myshoot[i]->move();
				window.draw(*myshoot[i]);
			}
		}

		if (customspassing)
		{
			window.draw(*customspasstype[customspass - 1]);
		}
		else
		{
			if (myplane.life <= 0)
			{
				window.draw(gameover);
				window.draw(tryagain);
				return;
			}

			for (size_t i = 0; i < 200; i++)
			{
				if (enemyshoot[i] != NULL)
				{
					enemyshoot[i]->move();
					window.draw(*enemyshoot[i]);
				}
			}

			for (size_t i = 0; i < 20; i++)
			{
				if (enemy[i] != NULL)
				{
					enemy[i]->move();
					window.draw(*enemy[i]);
				}
			}

			for (size_t i = 0; i < 5; i++)
			{
				if (boss[i] != NULL)
				{
					if (!(boss[i]->getSpeedy() <= 0))
					{
						boss[i]->move();
						window.draw(*boss[i]);
					}
					else
					{
						boss[i]->setSpeed();
						window.draw(*boss[i]);
					}
				}
			}
		}
	}
	
}
/////////////////////////////////绘制图形/////////////////////////////////

///////////////////////////////////碰撞///////////////////////////////////
void Game::collision()
{
	for (size_t j = 0; j < 300; j++)
	{
		if (myshoot[j] != NULL)
		{
			myshoot[j]->collision<Enemy>(enemy, 20);
			myshoot[j]->collision<Boss>(boss, 5);
		}
	}
	if (!myplane.getInvincible())//是否无敌
	{
		myplane.collision<Enemy>(enemy, 20);
		myplane.collision<Boss>(boss, 5);
		myplane.collision<Enemyshoot>(enemyshoot, 200);
	}
	else
	{
		if (clock.getElapsedTime() - invicible_time < sf::seconds(1))
		{
			myplane.setColor(sf::Color(0, 200, 100, 80));
		}
		if (clock.getElapsedTime() - invicible_time >= sf::seconds(1) && clock.getElapsedTime() - invicible_time < sf::seconds(2))
		{
			myplane.setColor(sf::Color(0, 200, 100, 255));
		}
		if (clock.getElapsedTime() - invicible_time >= sf::seconds(2) && clock.getElapsedTime() - invicible_time < sf::seconds(3))
		{
			myplane.setColor(sf::Color(0, 200, 100, 80));
		}
		if (clock.getElapsedTime() - invicible_time >= sf::seconds(3))
		{
			myplane.setColor(sf::Color(0, 200, 100, 255));
			myplane.outofInvincible();
		}
	}
	
}
///////////////////////////////////碰撞///////////////////////////////////

void Game::deletethem()
{
	ifdelete<Enemy>(enemy, 20);
	ifdelete<Boss>(boss, 5);
	ifdelete<Enemyshoot>(enemyshoot, 200);
	ifdelete<Myshoot>(myshoot, 300);

	//死亡   life-1 刷新飞机
	if (myplane.times <= 0)
	{
		myplane.times = 20;
		myplane.life -= 1;
		myplane.beInvincible();
		invicible_time = clock.getElapsedTime();
	}
}

void Game::countingdown()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (enemy[i] != NULL && enemy[i]->getIfboom())
		{
			enemy[i]->countdown(load);
			if (enemy[i]->gettimeNow() - enemy[i]->getCountdown() > sf::seconds(0.75))
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL && boss[i]->getIfboom())
		{
			boss[i]->countdown(load);
			if (boss[i]->gettimeNow() - boss[i]->getCountdown() > sf::seconds(0.75))
			{
				delete boss[i];
				boss[i] = NULL;
			}
		}
	}
}

void Game::keyboardManager(sf::Window &window)
{
	//shoot的时间间隔
	if (type.getifConceled())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (myplane.getX()>25)
				myplane.setX(myplane.getX() - myplane.getSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (myplane.getX()<575)
				myplane.setX(myplane.getX() + myplane.getSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (myplane.getY()>35)
				myplane.setY(myplane.getY() - myplane.getSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (myplane.getY()<770)
				myplane.setY(myplane.getY() + myplane.getSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			static sf::Time shoot_time = sf::seconds(0);
			if (clock.getElapsedTime() - shoot_time >= sf::seconds(0.1))
			{
				myShootSound.play();
				shoot_time = clock.getElapsedTime();
				myplane.shoot(myshoot, 300);
			}
		}
	}
}

void Game::mouseManager(sf::Window &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		if (type.getifConceled() == 0 && localPosition.x < 350 && localPosition.x > 270 && localPosition.y < 400 && localPosition.y > 340)
		{
			type.setifConceled(1);
			invicible_time = clock.getElapsedTime();
			passing_time = clock.getElapsedTime();
		}
		if (myplane.life <= 0 && localPosition.x < 400 && localPosition.x > 250 && localPosition.y < 480 && localPosition.y > 420)
		{
			myplane.life = 3;

			for (size_t i = 0; i < 300; i++)
			{
				myshoot[i] = NULL;
			}
			for (size_t i = 0; i < 20; i++)
			{
				enemy[i] = NULL;
			}
			for (size_t i = 0; i < 200; i++)
			{
				enemyshoot[i] = NULL;
			}
			for (size_t i = 0; i < 5; i++)
			{
				boss[i] = NULL;
			}
		}
	}
	
	
}

void Game::createenemy()
{
	if (timeNow % sf::seconds(5) < sf::seconds(0.01))
	{
		int i = create<Enemy>(enemy, 20);
		enemy[i]->setSpeed(0, 1.5*multiple);
	}

	if (timeNow % sf::seconds(30) < sf::seconds(0.01))
	{
		int i = create<Boss>(boss, 5);
	}
}

void Game::shootall()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (enemy[i] != NULL && enemy[i]->getIfboom() == 0)
		{
			enemy[i]->shoot(enemyshoot, 200, myplane.getX(), myplane.getY(), shootSound);
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL && boss[i]->getIfboom() == 0)
		{
			boss[i]->shoot(enemyshoot, 200, bossShootSound);
		}
	}
}
