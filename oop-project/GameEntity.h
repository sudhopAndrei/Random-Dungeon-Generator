#include <iostream>
#include <SFML/Graphics.hpp>

#include "CollisionHandler.h"
#include "MovementBlocker.h"

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

enum class EntityType {
	Player,
	Enemy,
	Wall,
	Door,
	WalkableTile
};

class GameEntity : public CollisionHandler, public MovementBlocker {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	static std::vector <GameEntity*> entities; //main game vector (holds everything)

	GameEntity(const std::string& textureName);
	~GameEntity() {};

	virtual void handleMovement() {}; //implements movement into a virtual class
	virtual void changeDirection() {}; //changes the direction of the entity into a virtual class

	virtual void handleCollision(GameEntity* managedEntity, GameEntity* collidedEntity = nullptr) override = 0; //pure virtual function for collision handling

	void blockMovementUp() override {};
	void blockMovementDown() override {};
	void blockMovementLeft() override {};
	void blockMovementRight() override {};

	//getters
	virtual EntityType getEntityType() const = 0; //virtual getter for the entity type (works like casting)

	sf::Sprite getSprite();
};

#endif
