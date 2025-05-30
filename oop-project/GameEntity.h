#include <iostream>
#include <SFML/Graphics.hpp>

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

class GameEntity : public MovementBlocker {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	static std::vector <GameEntity*> entities; //main game vector (holds everything)

	GameEntity(const std::string& textureName);
	virtual ~GameEntity() {};

	virtual void handleMovement(float deltaTime) {}; //implements movement into a virtual class
	virtual void changeDirection() {}; //changes the direction of the entity into a virtual class

	void blockMovementUp() override {};
	void blockMovementDown() override {};
	void blockMovementLeft() override {};
	void blockMovementRight() override {};

	//getters
	virtual EntityType getEntityType() const = 0; //virtual getter for the entity type (works like casting)

	sf::Sprite getSprite();
	sf::Sprite& getSpriteRef();
};

#endif
