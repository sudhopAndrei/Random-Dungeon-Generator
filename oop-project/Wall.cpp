#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Wall.hpp"

Wall::Wall(const std::string& textureName, float x, float y, int sizeX, int sizeY, bool isPassable) : MapAsset(textureName, x, y, sizeX, sizeY) {
	texture.setRepeated(true);
	this->isPassable = isPassable;
}

///getters
bool Wall::getIsPassable() {
	return isPassable;
}