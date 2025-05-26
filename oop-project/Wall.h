#include <SFML/Graphics.hpp>
#include <iostream>

#include "Tile.h"

#ifndef WALL_H
#define WALL_H

class Wall : public Tile {
public:
	Wall(const std::string& textureName, float x, float y, int sizeX, int sizeY);
	~Wall() {};

	//getters
	EntityType getEntityType() const override;
};

#endif