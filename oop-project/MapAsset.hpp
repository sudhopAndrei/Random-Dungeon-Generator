#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef MAPASSET_HPP
#define MAPASSET_HPP

class MapAsset {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	MapAsset(const std::string& textureName, float x, float y, int sizeX, int sizeY);
	~MapAsset() {};

	///getters
	sf::Texture getTexture();
	sf::Sprite getSprite();
};

#endif
