#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Tile.hpp"

Tile::Tile(const std::string& textureName, float x, float y, bool isPassable) : sprite(texture) {
	if (setSprite(textureName) == false) {
		return; 
	} ///check if the texture was loaded successfully
	sprite.setPosition(sf::Vector2f(x, y)); 
	this->isPassable = isPassable; 
}

bool Tile::setSprite(const std::string& textureName) { 
	if (texture.loadFromFile(textureName) == false) {
		std::cout << "Error loading texture" << std::endl; ///throw an error if the texture is not loaded
		return false;
	}
	texture.setSmooth(true);
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 120, 120 }));
	return true;
}

///getters

sf::Texture Tile::getTexture() {
	return texture;
}

sf::Sprite Tile::getSprite() {
	return sprite;
}

bool Tile::getIsPassable() {
	return isPassable;
}
