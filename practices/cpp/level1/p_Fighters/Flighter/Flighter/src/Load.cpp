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
	background.setRepeated(1);

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

	if (!myshoot0.loadFromFile(("Resource/myshoot0.png")))
	{
		std::cout << "open the file shoot.png failed!" << std::endl;
		system("pause");
	}
	if (!myshoot1.loadFromFile(("Resource/myshoot1.png")))
	{
		std::cout << "open the file myshoot1.png failed!" << std::endl;
		system("pause");
	}
	if (!myshoot2.loadFromFile(("Resource/myshoot2.png")))
	{
		std::cout << "open the file myshoot2.png failed!" << std::endl;
		system("pause");
	}
	if (!myshoot3.loadFromFile(("Resource/myshoot3.png")))
	{
		std::cout << "open the file myshoot3.png failed!" << std::endl;
		system("pause");
	}
	if (!font.loadFromFile("Resource/Deng.ttf"))
	{
		std::cout << "open the file Deng.ttf failed!" << std::endl;
		system("pause");
	}
	if (!bgm.openFromFile("Resource/Sunburst.ogg"))
	{
		std::cout << "open the file Sunburst.ogg failed!" << std::endl;
		system("pause");
	}
	if (!buffer.loadFromFile("Resource/shoot.wav"))
	{
		std::cout << "open the file shoot.wav failed!" << std::endl;
		system("pause");
	}
	if (!bossshootSound.loadFromFile("Resource/bossshoot.wav"))
	{
		std::cout << "open the file bossshoot.wav failed!" << std::endl;
		system("pause");
	}
	if (!myshootSound.loadFromFile("Resource/myshoot.wav"))
	{
		std::cout << "open the file myshoot.wav failed!" << std::endl;
		system("pause");
	}
	if (!enemyBoom.loadFromFile("Resource/enemyboom.wav"))
	{
		std::cout << "open the file enemyboom.wav failed!" << std::endl;
		system("pause");
	}
	if (!enemyBoom.loadFromFile("Resource/enemyboom.wav"))
	{
		std::cout << "open the file enemyboom.wav failed!" << std::endl;
		system("pause");
	}
	if (!bloodframe.loadFromFile(("Resource/bloodframe.png")))
	{
		std::cout << "open the file bg.png failed!" << std::endl;
		system("pause");
	}
	if (!blood.loadFromFile(("Resource/blood.png")))
	{
		std::cout << "open the file bg.png failed!" << std::endl;
		system("pause");
	}
	if (!giftplus.loadFromFile(("Resource/giftplus.png")))
	{
		std::cout << "open the file giftplus.png failed!" << std::endl;
		system("pause");
	}
	if (!giftgun1.loadFromFile(("Resource/giftgun1.png")))
	{
		std::cout << "open the file giftgun1.png failed!" << std::endl;
		system("pause");
	}
	if (!giftgun2.loadFromFile(("Resource/giftgun2.png")))
	{
		std::cout << "open the file giftgun2.png failed!" << std::endl;
		system("pause");
	}
	if (!giftgun3.loadFromFile(("Resource/giftgun3.png")))
	{
		std::cout << "open the file giftgun3.png failed!" << std::endl;
		system("pause");
	}
}
