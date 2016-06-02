#define _CRT_SECURE_NO_WARNINGS

#include"Game.hpp"
#include<time.h>


sf::Clock Game::clock;

Game::Game()
	:background1(-2400),
	background2(-5500),
	type("PLAY!"),
	gameover("Game Over"),
	tryagain("Try Again"),
	customspasstype("Level  "),
	recordscore("Score  ")
{
	str = "Level  ";
	customspasstype.setPosition(200, 320);
	customspasstype.setCharacterSize(60);
	customspasstype.setFont(load.font);
	multiple = 1;
	multiple1 = 1;
	customspass = 1;
	levelnum = std::to_string(customspass);
	customspasstype.setString(str + levelnum);
	customspassing = 1;
	score = 0;
	lastscore = 0;
	srand(time(0));
	timeNow = sf::seconds(0.00f);
	type.setPosition(270, 350);
	gameover.setPosition(250, 350);
	tryagain.setPosition(250, 420);

	recordscore.setFont(load.font);

	for (size_t i = 0; i < 101; i++)
	{
		myshoot[i] = NULL;
		myshoot1[i] = NULL;
		myshoot2[i] = NULL;
		myshoot3[i] = NULL;
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
	for (size_t i = 0; i < 5; i++)
	{
		giftplus[i] = NULL;
	}
	for (size_t i = 0; i < 5; i++)
	{
		giftgun[i] = NULL;
	}

	bloodframe.setPosition(440, 0);
	blood.setPosition(443, 3);
	blood.setColor(sf::Color(34, 172, 56, 255));

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
	load.bgm.setVolume(50);
	load.bgm.play();

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
				for (size_t i = 0; i < 20; i++)
				{
					delete enemy[i];
					enemy[i] = NULL;
				}
				for (size_t i = 0; i < 5; i++)
				{
					delete boss[i];
					boss[i] = NULL;
				}
				for (size_t i = 0; i < 200; i++)
				{
					delete enemyshoot[i];
					enemyshoot[i] = NULL;
				}
				for (size_t i = 0; i < 101; i++)
				{
					delete myshoot[i];
					delete myshoot1[i];
					delete myshoot2[i];
					delete myshoot3[i];
					myshoot[i] = NULL;
					myshoot1[i] = NULL;
					myshoot2[i] = NULL;
					myshoot3[i] = NULL;
				}
				for (size_t i = 0; i < 5; i++)
				{
					delete giftplus[i];
					giftplus[i] = NULL;
				}
				for (size_t i = 0; i < 5; i++)
				{
					delete giftgun[i];
					giftgun[i] = NULL;
				}
				window.close();
			}

			if (event.type == sf::Event::LostFocus)
			{
				/*continue;*/
			}
		}

		mouseManager(window);//mouse if pressed

		keyboardManager(window);//keyboard if pressed

		if (ifRefrash)
		{
			getscore = std::to_string(score);
			recordscore.setString("Score  " + getscore);

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
						levelnum = std::to_string(customspass);
						customspasstype.setString(str + levelnum);
						multiple *= 1.1;
						multiple1 *= 0.9;
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
						for (size_t i = 0; i < 5; i++)
						{
							if (giftplus[i] != NULL)
							{
								delete giftplus[i];
								giftplus[i] = NULL;
							}
						}
						for (size_t i = 0; i < 5; i++)
						{
							if (giftgun[i] != NULL)
							{
								delete giftgun[i];
								giftgun[i] = NULL;
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

	switch (myplane.getGun())
	{
	case 0:
		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot[i] != NULL)
			{
				myshoot[i]->setTexture(load.myshoot0);
			}
		}
		break;
	case 1:
		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot1[i] != NULL)
			{
				myshoot1[i]->setTexture(load.myshoot1);
			}
		}
		break;
	case 2:
		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot2[i] != NULL)
			{
				myshoot2[i]->setTexture(load.myshoot2);
			}
		}
		break;
	case 3:
		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot3[i] != NULL)
			{
				myshoot3[i]->setTexture(load.myshoot3);
			}
		}
		break;
	default:
		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot[i] != NULL)
			{
				myshoot[i]->setTexture(load.myshoot0);
			}
		}
		break;
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL && boss[i]->getIfboom() == 0)
		{
			boss[i]->setTexture(load.boss);
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (giftplus[i] != NULL)
		{
			giftplus[i]->setTexture(load.giftplus);
		}
	}
	for (size_t i = 0; i < 5; i++)
	{
		if (giftgun[i] != NULL)
		{
			switch (giftgun[i]->getGuntype())
			{
			case 1:
				giftgun[i]->setTexture(load.giftgun1);
				break;
			case 2:
				giftgun[i]->setTexture(load.giftgun2);
				break;
			case 3:
				giftgun[i]->setTexture(load.giftgun3);
				break;
			default:
				break;
			}
		}
	}
	bloodframe.setTexture(load.bloodframe);
	blood.setTexture(load.blood);
	blood.setTextureRect(sf::IntRect(0, 0, myplane.times * 154 / 20, 34));
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

	window.draw(recordscore);

	if (!type.getifConceled())
	{
		window.draw(type);//menu
	}
	else
	{
		myplane.moveMe();//myplane
		window.draw(myplane);
		window.draw(bloodframe);
		window.draw(blood);

		for (size_t i = 0; i < 101; i++)
		{
			if (myshoot[i] != NULL)
			{
				myshoot[i]->move();
				window.draw(*myshoot[i]);
			}
			if (myshoot1[i] != NULL)
			{
				myshoot1[i]->move();
				window.draw(*myshoot1[i]);
			}
			if (myshoot2[i] != NULL)
			{
				myshoot2[i]->move();
				window.draw(*myshoot2[i]);
			}
			if (myshoot3[i] != NULL)
			{
				myshoot3[i]->move();
				window.draw(*myshoot3[i]);
			}
		}

		if (customspassing)
		{
			window.draw(customspasstype);
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
			for (size_t i = 0; i < 5; i++)
			{
				if (giftplus[i] != NULL)
				{
					giftplus[i]->move();
					window.draw(*giftplus[i]);
				}
			}
			for (size_t i = 0; i < 5; i++)
			{
				if (giftgun[i] != NULL)
				{
					giftgun[i]->move();
					window.draw(*giftgun[i]);
				}
			}
		}
	}
	
}
/////////////////////////////////绘制图形/////////////////////////////////

///////////////////////////////////碰撞///////////////////////////////////
void Game::collision()
{
	for (size_t j = 0; j < 101; j++)
	{
		if (myshoot[j] != NULL)
		{
			myshoot[j]->collision<Enemy>(enemy, 20);
			myshoot[j]->collision<Boss>(boss, 5);
		}
		if (myshoot1[j] != NULL)
		{
			myshoot1[j]->collision<Enemy>(enemy, 20);
			myshoot1[j]->collision<Boss>(boss, 5);
		}
		if (myshoot2[j] != NULL)
		{
			myshoot2[j]->collision<Enemy>(enemy, 20);
			myshoot2[j]->collision<Boss>(boss, 5);
		}
		if (myshoot3[j] != NULL)
		{
			myshoot3[j]->collision<Enemy>(enemy, 20);
			myshoot3[j]->collision<Boss>(boss, 5);
		}
	}

	myplane.collisiongift<Giftplus>(giftplus, 5, clock.getElapsedTime());
	if (myplane.life == 3)
	{
		blood.setColor(sf::Color(34, 172, 56, 255));
	}
	if (myplane.life == 2)
	{
		blood.setColor(sf::Color(237, 141, 38, 255));
	}

	myplane.collisiongift<Giftgun>(giftgun, 5, clock.getElapsedTime());

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
	ifdeletegift<Giftplus>(giftplus, 5);
	ifdeletegift<Giftgun>(giftgun, 5);
	ifdelete<Enemyshoot>(enemyshoot, 200);
	ifdelete<Myshoot>(myshoot, 101);
	ifdelete<Myshoot>(myshoot1, 101);
	ifdelete<Myshoot>(myshoot2, 101);
	ifdelete<Myshoot>(myshoot3, 101);

	//死亡   life-1 刷新飞机
	if (myplane.times <= 0)
	{
		myplane.times = 20;
		myplane.life -= 1;
		if (myplane.life == 2)
		{
			blood.setColor(sf::Color(237, 141, 38, 255));
		}
		if (myplane.life == 1)
		{
			blood.setColor(sf::Color(217, 71, 71, 255));
		}
		if (myplane.life == 0)
		{
			blood.setColor(sf::Color(0, 0, 0, 0));
		}
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
				switch (myplane.getGun())
				{
				case 0:
					myplane.shoot(myshoot, 101);
					break;
				case 1:
					myplane.shoot(myshoot1, 101);
					break;
				case 2:
					myplane.shoot(myshoot2, 101);
					break;
				case 3:
					myplane.shoot(myshoot3, 101);
					break;
				default:
					break;
				}
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
			score = 0;
			customspass = 1;
			multiple = 1;
			multiple1 = 1;
			levelnum = std::to_string(customspass);
			customspasstype.setString("Level  " + levelnum);
			myplane.life = 3;
			blood.setColor(sf::Color(34, 172, 56, 255));

			for (size_t i = 0; i < 101; i++)
			{
				myshoot[i] = NULL;
				myshoot1[i] = NULL;
				myshoot2[i] = NULL;
				myshoot3[i] = NULL;
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
	if (timeNow % sf::seconds(5 * multiple1) < sf::seconds(0.01))
	{
		int i = create<Enemy>(enemy, 20, 1.5);
		enemy[i]->setSpeed(0, 1.5);
	}
	if (timeNow % sf::seconds(30 * multiple1) < sf::seconds(0.01))
	{
		int i = create<Boss>(boss, 5, 1.5);
	}
	if (timeNow % sf::seconds(25 * multiple1) < sf::seconds(0.01))
	{
		int i = create<Giftplus>(giftplus, 5, 2);
	}
	if ((timeNow + sf::seconds(10)) % sf::seconds(22 * multiple1) < sf::seconds(0.01))
	{
		int i = create<Giftgun>(giftgun, 5, 2);
	}
}

void Game::shootall()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (enemy[i] != NULL && enemy[i]->getIfboom() == 0)
		{
			enemy[i]->shoot(enemyshoot, 200, myplane.getX(), myplane.getY(), shootSound, multiple1);
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL && boss[i]->getIfboom() == 0)
		{
			boss[i]->shoot(enemyshoot, 200, bossShootSound, multiple1);
		}
	}
}
