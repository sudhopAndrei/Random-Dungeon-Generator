#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Window.hpp"

Window::Window(const std::string& textureName, float x, float y, int sizeX, int sizeY, bool isPassable, const std::string& soundName, bool isBroken) : 
	Wall(textureName, x, y, sizeX, sizeY, isPassable), windowBreakSoundBuffer(soundName), windowBreakSound(windowBreakSoundBuffer) {
	windowBreakSound.setVolume(50);
	windowBreakSound.setLooping(true);
}

void Window::breakWindow() {
	if (isBroken == false) {
		///if abs(playerPos-WindowPos) < 50px poate apasa key -> se sparge geamul
		Window::setIsPassable(true);
		windowBreakSound.play();
		isBroken = true;
	}
}

///getters
sf::SoundBuffer Window::getSoundBuffer() {
	return windowBreakSoundBuffer;
}

sf::Sound Window::getSound() {
	return windowBreakSound;
}
