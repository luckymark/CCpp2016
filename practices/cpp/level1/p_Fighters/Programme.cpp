#include "Programme.h"
void Programme::run()
{
	int isDead = 0;
	sf::RenderWindow begin(sf::VideoMode(580,320),"begin");
	iniBackround();
	
	backround->drawBeginBackround();
	begin.draw(backround->sbackround);
	text->drawBeginText();
	begin.draw(text->text);
	begin.display();
	while (begin.isOpen())
	{
		sf::Event event;
		while (begin.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				begin.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				begin.close();
			}
		}
	}
	sf::Event event;
	isDraw = 0;
	bigBoom = 3;
	afterCollision = 2 * AFTERBOOM;
	isCreateEnemy = -1;
	playsound();
	iniBackround();
	plane = new Plane(335, 607);
	plane->iniPlane();
	while (window.isOpen())
	{
		if ((life+1))
		{
			isCreateEnemy++;
			isCreateEnemy %= 700;
			window.clear();
			drawBackround();
			while (window.pollEvent(event))
			{
				if (afterCollision > AFTERBOOM)
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyPressed:
						plane->move();
						if (boom->isBoom())
						{
							iniBoom();
							addBoom(boom);

						}
						if (boom->BigBoom() && bigBoom > 0)
						{
							bigBoom--;
							n += lenemy.size();
							lenemy.clear();
							lBoom.clear();
							lEnemyBoom.clear();
							window.clear();
							window.draw(backround->sbackround);
							window.draw(plane->shost);
						}
						break;
					default:
						break;
					}
				}


			}
			if (!isCreateEnemy)
			{
				iniEnemy();
			}
			if ((!lBoom.empty()) && (!lenemy.empty()))
			{
				collision();
			}
			if (afterCollision > 2 * AFTERBOOM)
			{
				if (godCollision())
				{
					bigBoom = 3;
					godBuffer.loadFromFile("D://Heaven.ogg");
					godSound.setBuffer(godBuffer);
					godSound.play();
					afterCollision = 0;
					isDraw = 0;
					plane->getini();
				}
			}
			afterCollision++;
			drawBoom();
			if (afterCollision > AFTERBOOM&&afterCollision < 2 * AFTERBOOM)
			{
				if (isDraw > 50)
					drawPlane();
				if (isDraw == 100)
					isDraw = 0;
				isDraw++;
			}
			else if (afterCollision > 2 * AFTERBOOM)
			{
				drawPlane();
				addEnemyBoom();
			}
			drawExplode();
			drawEnemyBoom();
			drawEnemy();
			drawText();
			window.display();
		}
		else
		{
			window.clear();
			drawBackround();
			window.draw(backround->sbackround);
			text->drawFail();
			window.draw(text->text);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (event.type == sf::Event::KeyPressed)
				{
					window.close();
				}
			}
		}
		
	}
}

void Programme::playsound()
{
	sound = new Sound;

	sound->playsound();
	
}

void Programme::iniBackround()
{
	backround = new Backround;

	text = new Text;
}

void Programme::drawBackround()
{
	backround->inibackround();
	window.draw(backround->sbackround);
}

void Programme::drawPlane()
{
	plane->drawplane();
	window.draw(plane->shost);
}

void Programme::drawText()
{
	text->iniText();
	window.draw(text->text);
}

void Programme::iniBoom()
{
	boom = new Boom(plane);
}

void Programme::drawBoom()
{
	Boom *middle;
	for (int i = 0; i < lBoom.size(); i++)
	{
		middle = lBoom[i];
		middle->move();
		if (middle->gety() < plane->gety()-400)
		{
			iBoom = lBoom.begin() + i;
			lBoom.erase(iBoom);
		}
		else
		{
			middle->iniBoom(plane->getx());
		}
		window.draw(middle->sboom);
	}
}

void Programme::addBoom(Boom *boom)
{
	lBoom.push_back(boom);
}

void Programme::drawEnemy()
{
	Enemy *middle;
	for (int i = 0; i < lenemy.size(); i++)
	{
		middle = lenemy[i];
		middle->move();
		if (middle->gety() > 800)
		{
			iEnemy = lenemy.begin() + i;
			lenemy.erase(iEnemy);
		}
		else
		{
			middle->iniEnemy();
		}
		window.draw(middle->shost);
	}
}

void Programme::iniEnemy()
{
	enemy = new Enemy(enemy->getposition(), 0);
	lenemy.push_back(enemy);
	enemy = new Enemy;
}

void Programme::collision()
{
	docollision.doCollision(lBoom, lenemy, lExplode);
}

void Programme::addEnemyBoom()
{
	Enemy *middle;
	for (int i = 0; i < lenemy.size(); i++)
	{
		middle = lenemy[i];
		if ((middle->gety()==10||middle->gety() == 200 || middle->gety() == 500))
		{
			if (!middle->isBoom())
			{
				boom = new Boom(middle->getx() + 25, middle->gety() + 50);
				boom->getdeviation(plane, middle);
				lEnemyBoom.push_back(boom);
			}
		}
	}
}

void Programme::drawEnemyBoom()
{
	double x, y;
	Boom *middle;
	Deviation *mdeviation;
	for (int i = 0; i < lEnemyBoom.size(); i++)
	{
		middle = lEnemyBoom[i];
		if (middle->getx()>=799||middle->getx()<=1||middle->gety()>=799||middle->gety()<=1)
		{
			iEnemyBoom = lEnemyBoom.begin() + i;
			lEnemyBoom.erase(iEnemyBoom);
		}
		mdeviation = middle->getDeviation();
		x = SPEED*mdeviation->x / (sqrt(pow(mdeviation->x, 2) + pow(mdeviation->y, 2)));
		y = SPEED*mdeviation->y / (sqrt(pow(mdeviation->x, 2) + pow(mdeviation->y, 2)));
		middle->changePosition(middle->getx() + x, middle->gety() + y);
		middle->iniBoom(middle->getx(), middle->gety());
		window.draw(middle->sboom);
	}
}

void Programme::randomMove()
{
	for (int i = 0; i < lenemy.size(); i++)
	{
		enemy = lenemy[i];
		enemy->randomMove();
	}
}

bool Programme::godCollision()
{
	if (docollision.godCollision(lenemy, lEnemyBoom, plane))
	{
		return true;
	}
	return false;
}

void Programme::drawExplode()
{
	Explode *middle;
	for (int i = 0; i < lExplode.size(); i++)
	{
		middle = lExplode[i];
		middle->carry_out();
		if (middle->getProcess() > 200)
		{
			iExplode = lExplode.begin() + i;
			lExplode.erase(iExplode);
			delete middle;
		}
		else
		{
			middle->drawExplode();
			window.draw(middle->sExplode);
		}
	}
}

void Programme::drawBegin()
{
	backround->drawBeginBackround();
	
}

