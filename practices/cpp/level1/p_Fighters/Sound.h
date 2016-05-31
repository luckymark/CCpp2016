#pragma once
#include<string>
#include<SFML\Audio.hpp>
class Sound
{
public:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	Sound();
	void playsound();
	void inisound();
private:
	std::string s;
};