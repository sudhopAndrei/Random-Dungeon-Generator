#include <iostream>
#include <SFML/Audio.hpp>

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

class SoundPlayer {
	virtual void playSound(sf::Sound& sound) = 0;
};

#endif