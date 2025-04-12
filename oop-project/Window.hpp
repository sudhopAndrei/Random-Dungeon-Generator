#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Wall.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window : public Wall {
	sf::SoundBuffer windowBreakSoundBuffer;
	sf::Sound windowBreakSound;
	bool isBroken;

public:
	Window(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type, bool isPassable, const std::string& soundName, bool isBroken);
	~Window() {};

	void breakWindow();

	///getters
	sf::SoundBuffer getSoundBuffer();
	sf::Sound getSound();
};

#endif
