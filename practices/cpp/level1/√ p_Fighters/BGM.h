#pragma once
#include <SFML/Audio.hpp>
class BGM
{
public:
	sf::Music bgm;
	BGM() {
		bgm.openFromFile("BGM.wav");
		
	};

	void Play() {
		bgm.play();
		bgm.setLoop(true);
	}
};

