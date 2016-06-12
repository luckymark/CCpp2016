#include"Game.hpp"
#include<time.h>


sf::Clock Game::clock;

Game::Game()
	:background(0),
	type("PLAY!"),
	gameover("Game Over"),
	tryagain("Try Again"),
	scorerecord("Score: "),
	levelrecord("Level: ")
{
	srand(time(0));
	timeNow = sf::seconds(0.00f);
	type.setPosition(270, 350);
	gameover.setPosition(250, 350);
	levelrecord.setPosition(500, 0);
	tryagain.setPosition(250, 420);
	score = 0;
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

void Game::loop()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "My window");

	window.setFramerateLimit(400);
	
	load.bgm.setLoop(1);
	load.bgm.setVolume(50);
	load.bgm.play();

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
			}
		}

		mouseManager(window);

		keyboardManager(window);

		if (ifRefrash)
		{
			if (type.getifConceled())
			{
				createenemy();
				shootall();
				collision();
				deletethem();
			}

			window.clear();

			drawall(window);

			window.display();
		}
		
	}
}

void Game::giveTexture()
{
	background1.setTexture(load.background);
	background2.setTexture(load.background);
	type.setFont(load.font);
	gameover.setFont(load.font);
	scorerecord.setFont(load.font);
	levelrecord.setFont(load.font);
	tryagain.setFont(load.font);
	myplane.setTexture(load.myplane);
	for (size_t i = 0; i < 20; i++)
	{
		if (enemy[i] != NULL)
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
		if (boss[i] != NULL)
		{
			boss[i]->setTexture(load.boss);
		}
	}
}

void Game::drawall(sf::RenderWindow &window)
{
	window.draw(background);

	scorerecord.setString("Score: " + std::toString(score));
	window.draw(scorerecord);

	levelrecord.setString("Level: " + std::toString(1 + (score / 200)));
	window.draw(levelrecord);

	if (!type.getifConceled())
	{
		window.draw(type);
	}
	else
	{

		if (myplane.life <= 0)
		{
			window.draw(gameover);
			window.draw(tryagain);
			return;
		}

		myplane.moveMe();
		window.draw(myplane);

		for (size_t i = 0; i < 300; i++)
		{
			if (myshoot[i] != NULL)
			{
				myshoot[i]->move();
				window.draw(*myshoot[i]);
			}
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

void Game::collision()
{
	for (size_t j = 0; j < 300; j++)
	{
		if (myshoot[j] != NULL)
		{
			myshoot[j]->collision<Enemy>(enemy, 20, score);
			myshoot[j]->collision<Boss>(boss, 5, score);
		}
	}
	if (!myplane.getInvincible())
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

void Game::deletethem()
{
	ifdelete<Enemy>(enemy, 20);
	ifdelete<Boss>(boss, 5);
	ifdelete<Enemyshoot>(enemyshoot, 200);
	ifdelete<Myshoot>(myshoot, 300);

	if (myplane.times <= 0)
	{
		myplane.times = 20;
		myplane.life -= 1;
		myplane.beInvincible();
		invicible_time = clock.getElapsedTime();
	}
}

void Game::keyboardManager(sf::Window &window)
{
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
		if (enemy[i] != NULL)
		{
			enemy[i]->shoot(enemyshoot, 200, myplane.getX(), myplane.getY());
		}
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (boss[i] != NULL)
		{
			boss[i]->shoot(enemyshoot, 200);
		}
	}
}

