#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <windows.h>
#include <winuser.h>
#define SPEED 0.15

int main(){
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	std::random_device rd;
	std::default_random_engine e(rd());

	sf::Clock clock;
	//计时，与敌机的出现有关系

	bool sleep = 0;
	int count[10] = { 0 };
	int bullet_count = 0;
	sf::RenderWindow window(sf::VideoMode(700, height), "Fighter");
	sf::Texture texture, texture_bullet, texture_enemy, texture_enemy_bullet, texture_boom, texture_flame, texture_background;
	sf::Font font;
	font.loadFromFile("SourceCodePro.ttf");
	sf::Text text1, text2;
	text1.setFont(font); text2.setFont(font);
	text1.setCharacterSize(20); text2.setCharacterSize(20);
	text1.setColor(sf::Color::White); text2.setColor(sf::Color::Black);
	int level = 1, score = 0, life = 3;
	texture.loadFromFile("Rocket.png");
	texture_bullet.loadFromFile("Bullet.png");
	sf::Sprite Rocket;
	Rocket.setTexture(texture);
	Rocket.setPosition(sf::Vector2f(378, height - 112));
	sf::Sprite bullet[10];
	for (int i = 0; i <= 49; i++) {
		bullet[i].setTexture(texture_bullet);
	}

	sf::Sprite enemy_bullet[50];
	texture_enemy_bullet.loadFromFile("enemy_bullet.png");
	sf::Sprite enemy[50];
	texture_enemy.loadFromFile("enemy.png");

	sf::Sprite boom_text;
	texture_boom.loadFromFile("boom_text.png");
	//sf::Sprite flame;
	//texture_flame.loadFromFile("flame.gif");
	sf::Sprite background;
	texture_background.loadFromFile("background.jpg");
	background.setTexture(texture_background);

	for (int i = 0; i <= 49; i++) {
		enemy[i].setTexture(texture_enemy);
		std::uniform_int_distribution <> u(0, 650);
		enemy[i].setPosition(sf::Vector2f(u(e), -30));
		enemy_bullet[i].setTexture(texture_enemy_bullet);
		enemy_bullet[i].setPosition(sf::Vector2f(enemy[i].getPosition().x + 30, enemy[i].getPosition().y + 60));
	}




	sf::Music music;
	sf::SoundBuffer buffer1, buffer2;
	buffer1.loadFromFile("coll.wav");
	buffer2.loadFromFile("boom.wav");
	sf::Sound sound1, sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	music.openFromFile("BGM.wav");
	music.play();
	music.setLoop(true);
	sf::Event event;

	//防止开局出现错误的初始化
	//sf::Vector2f rocket_position = Rocket.getPosition();
	//bullet.setPosition(sf::Vector2f(rocket_position.x + 10, height - 150));


	while (window.isOpen())
	{
		//window.clear(sf::Color::Black);
		window.draw(background);

		sf::Vector2f rocket_position = Rocket.getPosition();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(Rocket);



		char s1[30];
		sprintf(s1, "level: %d\nscore: %d\nlife: %d", level, score, life);
		text1.setString(s1);
		window.draw(text1);

		sf::Time time1 = clock.getElapsedTime();


		for (int i = 0; i <= 49; i++) {
			if (time1 >= sf::seconds(1.5*i)) {
				//if (time1 == sf::seconds(i)) {
				//sf::Vector2f temp = enemy[i].getPosition();
				//temp.y = 0.0f;
				//enemy[i].setPosition(temp);

				//}
				window.draw(enemy[i]);
			}
		}
		for (int i = 0; i <= 49; i++) {
			if (time1 >= sf::seconds(1.5*i)) {
				enemy[i].move(0, 0.5 * level *SPEED);
				window.draw(enemy_bullet[i]);
				enemy_bullet[i].move(0, 2 * level  *SPEED);
			}
			//if (time1 >= sf::seconds(i + 1.25)) {


			//enemy_bullet[i].move(0, 2 * SPEED);
			//}
			//sf::Vector2f test_border = enemy[i].getPosition();
			//if (test_border.y >= 765.0) { enemy[i].setPosition(sf::Vector2f(600, 900)); }
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (rocket_position.x >= 0.15f) {
				Rocket.move(-2 * SPEED, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (rocket_position.x < 647.85f) {
				Rocket.move(2 * SPEED, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			count[bullet_count] = 1;
			//count[bullet_count - 1] = 0;
			bullet[bullet_count].setPosition(sf::Vector2f(rocket_position.x + 10, height - 150));;
			//flame.setPosition(sf::Vector2f(rocket_position.x + 20, 750));
			//window.draw(flame);
			//window.draw(bullet[bullet_count]);
			//function: sth.store bullet if bullet fly out of the window re
			sf::Vector2f bullet_position = bullet[bullet_count].getPosition();
		}
		
		for (int i = 0; i < 9;i++){
			if (count[i]) { 
				window.draw(bullet[i]); 
				bullet[i].move(0, -10 * SPEED); 
				//bullet_count = (bullet_count + 1) % 10;
				}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			sleep = sleep + 1;
		}
		if (sleep) {
			system("pause");
			sleep = 0;
		}

		for (int i = 0; i <= 9;i++){
			sf::Vector2f bullet_position = bullet[i].getPosition();
			if (bullet_position.y <= 10) { bullet[i].setPosition(sf::Vector2f(1000, 0)); count[i]+= 1; }
		}
		//碰撞
		sf::FloatRect collision_enemy[50];
		sf::FloatRect collision_enemy_bullet[50];
		sf::FloatRect boundingBox2 = Rocket.getGlobalBounds();


		sf::Time time2 = clock.getElapsedTime();
		for (int i = 0; i <= 49; i++) {
			collision_enemy[i] = enemy[i].getGlobalBounds();
			collision_enemy_bullet[i] = enemy_bullet[i].getGlobalBounds();
			for (int j = 0; j <= 9;j++){
				sf::FloatRect boundingBox1 = bullet[j].getGlobalBounds();
			if ((boundingBox1.intersects(collision_enemy[i])) && (enemy[i].getPosition().y >= 0.0f)) {
				//boom_text.setPosition(enemy[i].getPosition()); 
				//if (time1 <= sf::seconds(1.0f)) { window.draw(boom_text); }
				enemy[i].setPosition(sf::Vector2f(-400, 0));
				bullet[j].setPosition(sf::Vector2f(1000, 0));
				sound1.play();
				score += 100;//积分
				}
			}


			if ((boundingBox2.intersects(collision_enemy_bullet[i]))) {
				enemy_bullet[i].setPosition(sf::Vector2f(-400, 0));
				sound2.play();
				life--;
			}
			if ((boundingBox2.intersects(collision_enemy[i]))) {
				enemy[i].setPosition(sf::Vector2f(-400, 0));
				sound2.play();
				life--;
			}
		}
		//window.draw(boom_text);

		if (score >= 1800) {
			level = 2;
		}
		if (score >= 3600) {
			level = 3;
		}
		window.display();

		if (life <= 0) {
			//int result= MessageBox(NULL, TEXT("游戏结束！"), TEXT("Game Over!"), MB_OK);
			//switch (result) {
			//case IDOK:
			//	CString total;
			//	total.Format(_T("你的分数：%d\n你达到的等级：%d"), score,level);
			//	MessageBox(total);
			window.close();
		}
		if (score >= 4500) {
			window.close();
		}
	}
	if (life <= 0) {
		sf::RenderWindow window2(sf::VideoMode(300, 80), "Game Over!");
		while (window2.isOpen()) {
			while (window2.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window2.close();
			}
			window2.display();
			char s2[30];
			sprintf(s2, "Your Score: %d\nYour level: Level %d", score, level);
			text2.setString(s2);
			window2.clear(sf::Color::White);
			window2.draw(text2);
		}
	}
	if (score == 4500) {
		sf::RenderWindow window3(sf::VideoMode(300, 80), "You Win!");
		while (window3.isOpen()) {
			while (window3.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window3.close();
			}
			window3.display();
			char s2[30];
			sprintf(s2, "Your Score: %d\nYour level: Level %d", score, level);
			text2.setString(s2);
			window3.clear(sf::Color::White);
			window3.draw(text2);
		}
	}
}