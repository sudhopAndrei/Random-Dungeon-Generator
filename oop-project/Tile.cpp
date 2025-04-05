#include "Tile.hpp"

Tile::Tile(const std::string& textureName, float x, float y, bool isPassable) {
	if (setSprite(textureName)) {
		return 0;
	}
	
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	this->isPassable = isPassable;
}

bool Tile::setSprite(std::string textureName) {
	if (!texture.loadFromFile(textureName)) {
		std::cout << "Error loading texture" << std::endl;
		return 0;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	return 1;
}
