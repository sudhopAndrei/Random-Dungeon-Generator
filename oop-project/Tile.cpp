#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "Tile.hpp"
#include "MapAsset.hpp"

Tile::Tile(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& soundName) : MapAsset(textureName, x, y, sizeX, sizeY), tileSoundBuffer(soundName), tileSound(tileSoundBuffer) {
	tileSound.setVolume(50);
	tileSound.setLooping(true);
}

///getters
sf::SoundBuffer Tile::getSoundBuffer() {
	return tileSoundBuffer;
}

sf::Sound Tile::getSound() {
	return tileSound;
}
