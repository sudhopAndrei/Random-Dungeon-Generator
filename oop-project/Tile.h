#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "GameEntity.h"

#ifndef TILE_HPP
#define TILE_HPP

class Tile : public GameEntity {
public:
	Tile(const std::string& textureName, float x, float y, int sizeX, int sizeY);
	~Tile() {};

	virtual void handleCollision(GameEntity* managedEntity, GameEntity* collidedEntity = nullptr) override {}; //urmeaza play-sound la collision

	//getters
	EntityType getEntityType() const = 0;
};

#endif
