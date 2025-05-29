#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.h"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Actor {
public:
	Player(const std::string& textureName, sf::Vector2f spawnPosition);
	~Player() {};

	void handleMovement(float deltaTime) override; //overrides the movement function

	EntityType getEntityType() const override;
};

#endif 
