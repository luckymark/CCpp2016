#include "Sound.h"

Sound::Sound()
{
	s = "D://No_Limits.ogg";
}

void Sound::playsound()
{
	if (!Sound::buffer.loadFromFile(s))
	{
		exit(0);
	}

	Sound::sound.setBuffer(buffer);
	Sound::sound.play();
	Sound::sound.setLoop(true);
}

void Sound::inisound()
{
}
