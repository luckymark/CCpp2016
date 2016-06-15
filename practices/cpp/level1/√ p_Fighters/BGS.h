#pragma once
#include <SFML/Audio.hpp>
class BGS
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	
	BGS(int num) {
		if (num == 1){
		buffer.loadFromFile("coll.wav");
		sound.setBuffer(buffer);
		}
		if (num == 2) {
			buffer.loadFromFile("boom.wav");
			sound.setBuffer(buffer);
		}
	};
	void Play() {
		sound.play();
	}
};

