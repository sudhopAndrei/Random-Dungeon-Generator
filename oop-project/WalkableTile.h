#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "Tile.h"

#ifndef WALKABLETILE_HPP
#define WALKABLETILE_HPP

class WalkableTile : public Tile {
private:
	sf::SoundBuffer tileSoundBuffer;
	sf::Sound tileSound;

public:
	WalkableTile(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& soundName);
	~WalkableTile() {};

	///getters
	EntityType getEntityType() const override;
	sf::Sound getSound();
};

#endif
