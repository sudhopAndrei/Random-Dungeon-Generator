#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Wall.hpp"

Wall::Wall(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type, bool isPassable) :
	MapAsset(textureName, x, y, sizeX, sizeY, type) {
	texture.setRepeated(true);
	this->isPassable = isPassable;
}

///getters
bool Wall::getIsPassable() {
	return isPassable;
}

///setters
void Wall::setIsPassable(bool isPassable) {
	this->isPassable = isPassable;
}