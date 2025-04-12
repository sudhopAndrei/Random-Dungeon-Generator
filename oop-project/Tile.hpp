#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "MapAsset.hpp"

#ifndef TILE_HPP
#define TILE_HPP

class Tile : public MapAsset{
	sf::SoundBuffer tileSoundBuffer;
	sf::Sound tileSound;

public:
	Tile(const std::string& textureName, float x, float y, int sizeX, int sizeY,const std::string& type, const std::string& soundName);
	~Tile() {};

	///getters
	sf::SoundBuffer getSoundBuffer();
	sf::Sound getSound();
};

#endif
