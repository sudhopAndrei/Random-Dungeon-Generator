#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Door.hpp"

Door::Door(const std::string& textureName, float x, float y, int sizeX, int sizeY, bool isPassable, const std::string& soundName, bool isBroken) :
	Wall(textureName, x, y, sizeX, sizeY, isPassable), doorSoundBuffer(soundName), doorSound(doorSoundBuffer) {
	doorSound.setVolume(50);
	doorSound.setLooping(true);
}

void Door::openDoor() {
	if (isOpen == false) {
		///if abs(playerPos-DoorPos) < 50px poate apasa key -> se deschide usa
		Door::setIsPassable(true);
		doorSound.play();
		isOpen = true;
	}
}

void Door::closeDoor() {
	if (isOpen == true) {
		///if abs(playerPos-DoorPos) < 50px poate apasa key -> se inchide usa
		Door::setIsPassable(false);
		doorSound.play();
		isOpen = false;
	}
}

///getters
sf::SoundBuffer Door::getSoundBuffer() {
	return doorSoundBuffer;
}

sf::Sound Door::getSound() {
	return doorSound;
}
