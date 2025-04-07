#include <iostream>
#include "Tile.hpp"
#include <string>

Tile::Tile(const std::string& textureName, float x, float y, bool isPassable) : sprite(texture) {
	if (setSprite(textureName) == false) {
		return;
	}
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	this->isPassable = isPassable;
}

bool Tile::setSprite(const std::string& textureName) {
	if (texture.loadFromFile(textureName) == false) {
		std::cout << "Error loading texture" << std::endl;
		return false;
	}
	texture.setSmooth(true);
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 120, 120 }));
	return true;
}
