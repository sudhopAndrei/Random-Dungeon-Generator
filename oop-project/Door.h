#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Tile.h"

#ifndef DOOR_HPP
#define DOOR_HPP

class Door : public Tile {
private:
	sf::SoundBuffer doorSoundBuffer;
	sf::Sound doorSound;

public:
	Door(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& soundName);
	~Door() {};

	///getters
	EntityType getEntityType() const override;

	sf::Sound getSound();
};

#endif
