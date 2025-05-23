#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "GameEntity.h"

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor : public GameEntity {
protected:
	bool canMoveUp;
	bool canMoveLeft;
	bool canMoveRight;
	bool canMoveDown;
	
public:
	Actor(const std::string& texturePath);
	~Actor() {};

	virtual void handleMovement() override = 0; //overrides the virtual function from Entity class into a pure virtual function
	virtual void changeDirection() override {}; //changes the direction of the entity

	//block the movement
	void blockMovementUp() override;
	void blockMovementDown() override;
	void blockMovementLeft() override;
	void blockMovementRight() override;

	//reset all flags
	void resetMovementFlags() override;

	//getters
	virtual EntityType getEntityType() const = 0;

	bool getCanMoveUp();
	bool getCanMoveLeft();
	bool getCanMoveRight();
	bool getCanMoveDown();
};

#endif

