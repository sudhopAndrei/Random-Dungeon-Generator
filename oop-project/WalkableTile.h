#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "Tile.h"
#include "SoundPlayer.h"

#ifndef WALKABLETILE_HPP
#define WALKABLETILE_HPP

class WalkableTile : public Tile, public SoundPlayer {
private:
	sf::SoundBuffer tileSoundBuffer;
	sf::Sound tileSound;

public:
	WalkableTile(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& soundName);
	~WalkableTile() {};

	void playSound(sf::Sound& sound) override;	

	///getters
	EntityType getEntityType() const override;
	sf::Sound getSound();
};

#endif
