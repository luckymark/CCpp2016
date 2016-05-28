//#define CRT_SECURE_NO_WARNING

#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<string>
#include"Game.hpp"
#include"Background.hpp"
#include"Type.hpp"
#include"Myplane.hpp"
#include"Enemy.hpp"

using namespace std;

int main() {
	Game game;
	game.play();
	return 0;
} 