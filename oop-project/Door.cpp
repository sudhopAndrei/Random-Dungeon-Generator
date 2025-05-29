#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Door.h"

Door::Door(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& soundName) :
	Tile(textureName, x, y, sizeX, sizeY), doorSoundBuffer(soundName), doorSound(doorSoundBuffer) {
	doorSound.setVolume(50);
	doorSound.setLooping(false);
}

void Door::playSound(sf::Sound& sound) {
	sound.play();
}

///getters
EntityType Door::getEntityType() const {
	return EntityType::Door;
}

sf::Sound Door::getSound() {
	return doorSound;
}
