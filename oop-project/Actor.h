#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "GameEntity.h"
#include "MovementBlocker.h"

#ifndef ACTOR_HPP
#define ACTOR_HPP


class Actor : public GameEntity {
private:
	float speed;

public:
	Actor(const std::string& texturePath);
	~Actor() {};

	void handleMovement(float deltaTime) override = 0; //overrides the virtual function from Entity class into a pure virtual function
	void changeDirection() override {}; //changes the direction of the entity

	//block the movement
	void blockMovementUp() override;
	void blockMovementDown() override;
	void blockMovementLeft() override;
	void blockMovementRight() override;

	//type getter
	EntityType getEntityType() const = 0;

	//speed
	float getSpeed();
	void setSpeed(float speed);
};

#endif

