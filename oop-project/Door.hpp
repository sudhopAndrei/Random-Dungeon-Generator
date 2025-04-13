#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "MapAsset.hpp"

#ifndef DOOR_HPP
#define DOOR_HPP

class Door: public MapAsset {
	sf::SoundBuffer doorSoundBuffer;
	sf::Sound doorSound;
	bool isOpen;

public:
	Door(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type, const std::string& soundName, bool isOpen);
	~Door() {};

	void openDoor();
	void closeDoor();

	///getters
	sf::SoundBuffer getSoundBuffer();
	sf::Sound getSound();
};

#endif
