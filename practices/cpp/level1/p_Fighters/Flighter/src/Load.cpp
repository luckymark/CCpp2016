#include "Load.hpp"

Load::Load()
{
	load();
}

void Load::load()
{
	if (!background.loadFromFile(("Resource/bg.png")))
	{
		std::cout << "open the file bg.png failed!" << std::endl;
		system("pause");
	}

	if (!enemy.loadFromFile(("Resource/shoot.png"),sf::IntRect(0,4,70,86)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!enemy2.loadFromFile(("Resource/shoot.png"), sf::IntRect(536, 656, 70, 86)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!enemy3.loadFromFile(("Resource/shoot.png"), sf::IntRect(672, 656, 70, 86)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!enemy4.loadFromFile(("Resource/shoot.png"), sf::IntRect(742, 656, 70, 86)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!boss.loadFromFile(("Resource/shoot.png"), sf::IntRect(507, 754, 166, 248)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!boss2.loadFromFile(("Resource/shoot.png"), sf::IntRect(6, 490, 158, 252)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!boss3.loadFromFile(("Resource/shoot.png"), sf::IntRect(678, 754, 166, 248)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!boss4.loadFromFile(("Resource/shoot.png"), sf::IntRect(6, 754, 166, 248)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!bgm.openFromFile("Resource/bg.ogg"))
	{
		std::cout << "open the file Sunburst.ogg failed!" << std::endl;
		system("pause");

	if (!myplane.loadFromFile(("Resource/shoot.png"), sf::IntRect(2,100,98,124)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!myplane2.loadFromFile(("Resource/shoot.png"),sf::IntRect(166,238,98,124)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!myplane3.loadFromFile(("Resource/shoot.png"), sf::IntRect(334, 500, 98, 124)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!myplane4.loadFromFile(("Resource/shoot.png"), sf::IntRect(436, 500, 98, 124)))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!enemyshoot.loadFromFile(("Resource/enemyshoot.png")))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!myshoot.loadFromFile(("Resource/myshoot.png")))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}

	if (!font.loadFromFile("Resource/Deng.ttf"))
	{
		std::cout << "open the file Deng.ttf failed!" << std::endl;
		system("pause");
	}
}
