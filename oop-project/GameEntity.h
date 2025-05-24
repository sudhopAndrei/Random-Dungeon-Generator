#include <iostream>
#include <SFML/Graphics.hpp>

#include "CollisionHandler.h"

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

enum class EntityType {
	Player,
	Enemy,
	Wall,
	Door,
	WalkableTile
};

class GameEntity : public CollisionHandler {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	static std::vector <GameEntity*> entities; //main game vector (holds everything)

	GameEntity(const std::string& textureName);
	~GameEntity() {};

	virtual void handleMovement() {}; //implements movement into a virtual class
	virtual void changeDirection() {}; //changes the direction of the entity into a virtual class

	virtual void handleCollision() override = 0;

	//getters
	virtual EntityType getEntityType() const = 0; //virtual getter for the entity type (works like casting)

	sf::Sprite getSprite();
};

#endif
