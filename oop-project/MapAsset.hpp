#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef MAPASSET_HPP
#define MAPASSET_HPP

class MapAsset {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string type;

public:
	MapAsset(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type);
	~MapAsset() {};

	//getters
	sf::Texture getTexture();
	sf::Sprite getSprite();
	std::string getType();
};

#endif
