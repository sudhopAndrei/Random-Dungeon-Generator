#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

#include "Tile.hpp"
#include "MapAsset.hpp"

Tile::Tile(const std::string& textureName, float x, float y, const std::string& soundName) : MapAssets(textureName, x, y), tileSoundBuffer(soundName), tileSound(tileSoundBuffer) {
	tileSound.setVolume(50);
	tileSound.setLooping(true);
}

///getters
sf::SoundBuffer Tile::getSoundBuffer() {
	return tileSoundBuffer;
}
