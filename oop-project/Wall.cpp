#include <iostream>
#include <vector>

#include "Wall.h"

Wall::Wall(const std::string& textureName, float x, float y, int sizeX, int sizeY) :
	Tile(textureName, x, y, sizeX, sizeY) {}

EntityType Wall::getEntityType() const {
	return EntityType::Wall;
}
