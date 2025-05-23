#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

enum class EntityType {
	Player,
	Enemy,
	Wall,
	Door,
	WalkableTile
};

class GameEntity {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	bool isVerticalCollision;
	bool isHorizontalCollision;

public:
	static std::vector <GameEntity*> entities; //main game vector (holds everything)

	GameEntity(const std::string& textureName);
	~GameEntity() {};

	virtual void handleMovement() {}; //implements movement into a virtual class
	virtual void changeDirection() {}; //changes the direction of the entity into a virtual class

	virtual void blockMovementUp() {};
	virtual void blockMovementDown() {};
	virtual void blockMovementLeft() {};
	virtual void blockMovementRight() {};

	//reset all flags
	virtual void resetMovementFlags() {};

	//getters
	virtual EntityType getEntityType() const = 0; //virtual getter for the entity type (works like casting)

	sf::Sprite getSprite();
	bool getIsVerticalCollision();
	bool getIsHorizontalCollision();

	//setters
	void setIsVerticalCollision(bool isVerticalCollision);
	void setIsHorizontalCollision(bool isHorizontalCollision);
};

#endif
