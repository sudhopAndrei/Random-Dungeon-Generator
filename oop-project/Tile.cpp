#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Tile.h"

Tile::Tile(const std::string& textureName, float x, float y, int sizeX, int sizeY) : GameEntity(textureName) {
	sprite.setPosition(sf::Vector2f(x,y));
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { sizeX, sizeY }));
}

