#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <windows.h>
#include "Enemy.h"
#include "Rocket.h"
#include "Bullet.h"
#include "Enemy_bullet.h"
#include "Background.h"
#include "BGM.h"
#include "BGS.h"
#include "Texts.h"
#define SPEED 0.15


int width = GetSystemMetrics(SM_CXSCREEN);
static int height = GetSystemMetrics(SM_CYSCREEN);
static int level = 1, score = 0, life = 3;
static sf::RenderWindow window(sf::VideoMode(700, height), "Fighter!");
Background background;
Enemy enemy[80];
Rocket rocket;
Enemy_bullet enemy_bullet[80];
Bullet bullet;
BGM bgm;
BGS bgs1(1),bgs2(2);
Texts text;

void Game() {

	bgm.Play();
	sf::Clock clock;
	sf::Event event;
	while (window.isOpen()) {
		//系统关键位置初始化
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		background.Show();
		sf::Time time1 = clock.getElapsedTime();
		//显示分数
		text.ShowScore();
		//显示敌机以及子弹
		for (int i = 0; i < 80; i++) {
			if (time1 >= sf::seconds(1.5*i)) {
				enemy[i].Show();
				window.draw(enemy_bullet[i].enemy_bullet);
				enemy_bullet[i].enemy_bullet.setPosition(sf::Vector2f(enemy[i].enemy.getPosition().x + 30, enemy[i].enemy.getPosition().y + 60));
				enemy_bullet[i].Show();
			}
		}
		//显示飞机、控制移动
		rocket.move();	
		//开炮
		rocket.Gun();
		bullet.Show();
		if (bullet.bullet.getPosition().y <= 10) { 
			bullet.Gone(); 
		}
		//碰撞处理
		sf::FloatRect collision_enemy[80];
		sf::FloatRect collision_enemy_bullet[80];
		sf::FloatRect boundingBox2 = rocket.rocket.getGlobalBounds();
		for (int i = 0; i < 80; i++) {
			collision_enemy[i] = enemy[i].enemy.getGlobalBounds();
			collision_enemy_bullet[i] = enemy_bullet[i].enemy_bullet.getGlobalBounds();
			sf::FloatRect boundingBox1 = bullet.bullet.getGlobalBounds();
				if ((boundingBox1.intersects(collision_enemy[i])) && (enemy[i].enemy.getPosition().y >= 0.0f)) {
					bullet.bullet.setPosition(sf::Vector2f(1000, 0));
					bgs1.Play();
					score += 100;
				}
			if ((boundingBox2.intersects(collision_enemy_bullet[i]))) {
				enemy_bullet[i].enemy_bullet.setPosition(sf::Vector2f(-400, 0));
				bgs2.Play();
				life--;
			}
			if ((boundingBox2.intersects(collision_enemy[i]))) {
				enemy[i].enemy.setPosition(sf::Vector2f(-400, 0));
				bgs2.Play();
				life--;
			}
		}
		window.display();
		//分数迭代
		if (score >= 100 * level) {level++;}
		if (life <= 0) {window.close();}
		if (score >= 7500) {window.close();}	
	}
}