//背景
/*sf::Texture bg;
if (!bg.loadFromFile(("bg.png")))
{
	cout << "failed to open the file";
	system("pause");
	exit(0);
}

sf::Sprite myBg;
myBg.setTexture(bg);

//这里插入别的背景

//自己的飞机
sf::Texture plane;
if (!plane.loadFromFile(("shoot.png"), sf::IntRect(2, 100, 98, 125)))
{
	cout << "failed to open the file";
	system("pause");
	exit(0);
}
plane.setSmooth(true);

//飞机初始位置
float leftRight = 275;

sf::Sprite myPlane;
myPlane.setTexture(plane);
myPlane.setPosition(sf::Vector2f(leftRight, 725));
myPlane.setScale(sf::Vector2f(0.5f, 0.5f));
myPlane.setColor(sf::Color(0, 200, 100, 255));

//框大小  帧率60
sf::RenderWindow window(sf::VideoMode(600, 800), "myWindow");
window.setFramerateLimit(60);

//循环主体
while (window.isOpen())
{
	sf::Event event;
	while (window.pollEvent(event))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// left key is pressed: move our character
		if (leftRight > 0)
		{
			leftRight -= 10;
			myPlane.setPosition(sf::Vector2f(leftRight, 725));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// left key is pressed: move our character
		if (leftRight < 550)
		{
			leftRight += 10;
			myPlane.setPosition(sf::Vector2f(leftRight, 725));
		}
	}

	//window.clear(sf::Color::White);//底板白色

	window.draw(myBg);//背景

	window.draw(myPlane);//自己的飞机

	window.display();
}

return 0;*/