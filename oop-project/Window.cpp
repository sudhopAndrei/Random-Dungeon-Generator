#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Window.hpp"

Window::Window(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type, const std::string& soundName, bool isBroken) : 
	MapAsset(textureName, x, y, sizeX, sizeY, type), windowBreakSoundBuffer(soundName), windowBreakSound(windowBreakSoundBuffer) {
	this->isBroken = isBroken; 
	windowBreakSound.setVolume(50);
	windowBreakSound.setLooping(true);
}

void Window::breakWindow() {
	if (isBroken == false) {
		///if abs(playerPos-WindowPos) < 50px poate apasa key -> se sparge geamul
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
