#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "WalkableTile.h"

WalkableTile::WalkableTile(const std::string& textureName, float x, float y, int sizeX, int sizeY,const std::string& soundName) : 
	Tile(textureName, x, y, sizeX, sizeY), tileSoundBuffer(soundName), tileSound(tileSoundBuffer) {
	tileSound.setVolume(50);
	tileSound.setLooping(true);
}

void WalkableTile::playSound(sf::Sound& sound) {
	sound.play();
}

///getters
EntityType WalkableTile::getEntityType() const {
	return EntityType::WalkableTile;
}

sf::Sound WalkableTile::getSound() {
	return tileSound;
}
